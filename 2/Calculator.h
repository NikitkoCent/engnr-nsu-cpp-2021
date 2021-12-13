#pragma once

#include "lib/SafeInt/SafeInt.hpp"

#include <stack>
#include <sstream>
#include <map>
#include <iostream>
#include <cstdint>
#include <cstring>
#include <vector>
#include <iterator>
#include <string>


bool is_number(const std::string &line) {
    char *p;
    strtol(line.c_str(), &p, 10);
    return *p == 0;
}

class Command {
public:
    virtual void exec(const std::vector<std::string> &tokens,
                      std::stack<SafeInt<int64_t>> &values,
                      std::map<std::string, SafeInt<int64_t>> &names_and_values,
                      int64_t &result) = 0;
    virtual ~Command() = default;

};

class Print : public Command {
    void exec(const std::vector<std::string> &tokens,
              std::stack<SafeInt<int64_t>> &values,
              std::map<std::string, SafeInt<int64_t>> &names_and_values,
              int64_t &result) override {
        if(values.empty())
            throw std::invalid_argument("Operation: print, stack is empty");
        std::cout << (int64_t)values.top();
        values.pop();
    }
};

class Plus : public Command {
    void exec(const std::vector<std::string> &tokens,
              std::stack<SafeInt<int64_t>> &values,
              std::map<std::string, SafeInt<int64_t>> &names_and_values,
              int64_t &result) override {
        if (values.size() < 2)
            throw std::invalid_argument("Operation: plus, error: expected size of queue more than 2");
        int64_t first_element = values.top();
        values.pop();
        int64_t second_element = values.top();
        values.pop();
        values.push(first_element + second_element);
    }
};

class Minus : public Command {
    void exec(const std::vector<std::string> &tokens,
              std::stack<SafeInt<int64_t>> &values,
              std::map<std::string, SafeInt<int64_t>> &names_and_values,
              int64_t &result) override {
        if (values.size() < 2)
            throw std::invalid_argument("Operation: plus, error: expected size of queue more than 2");
        int64_t first_element = values.top();
        values.pop();
        int64_t second_element = values.top();
        values.pop();
        values.push(second_element - first_element);
    }
};

class Mul : public Command {
    void exec(const std::vector<std::string> &tokens,
              std::stack<SafeInt<int64_t>> &values,
              std::map<std::string, SafeInt<int64_t>> &names_and_values,
              int64_t &result) override {
        if (values.size() < 2)
            throw std::invalid_argument("Operation: plus, error: expected size of queue more than 2");
        int64_t first_element = values.top();
        values.pop();
        int64_t second_element = values.top();
        values.pop();
        values.push(second_element * first_element);
    }
};

class Div : public Command {
    void exec(const std::vector<std::string> &tokens,
              std::stack<SafeInt<int64_t>> &values,
              std::map<std::string, SafeInt<int64_t>> &names_and_values,
              int64_t &result) override {
        if (values.size() < 2)
            throw std::invalid_argument("Operation: plus, error: expected size of queue more than 2");
        int64_t first_element = values.top();
        values.pop();
        int64_t second_element = values.top();
        values.pop();
        if (first_element == 0) {
            throw std::invalid_argument("Operation: div, error: zero division");
        }
        values.push(second_element / first_element);
    }
};

class Push : public Command {
    void exec(const std::vector<std::string> &tokens,
              std::stack<SafeInt<int64_t>> &values,
              std::map<std::string, SafeInt<int64_t>> &names_and_values,
              int64_t &result) override {
        std::string varname = tokens[1];
        if (is_number(varname)) {
            values.push(stoi(varname));
        } else {
            if (names_and_values.find(varname) == names_and_values.end())
                throw std::invalid_argument("Operation: push, varname doesn't exist");
            values.push(names_and_values[varname]);
        }
    }
};

class Peek : public Command {
    void exec(const std::vector<std::string> &tokens,
              std::stack<SafeInt<int64_t>> &values,
              std::map<std::string, SafeInt<int64_t>> &names_and_values,
              int64_t &result) override {
        if(values.empty())
            throw std::invalid_argument("Operation: peek, stack is empty");
        std::string varname = tokens[1];
        names_and_values[varname] = values.top();
    }
};


class Abs : public Command {
    void exec(const std::vector<std::string> &tokens,
              std::stack<SafeInt<int64_t>> &values,
              std::map<std::string, SafeInt<int64_t>> &names_and_values,
              int64_t &result) override {
        if(values.empty())
            throw std::invalid_argument("Operation: abs, stack is empty");
        int64_t value = values.top();
        values.pop();
        value = value > 0 ? value : -value;
        values.push(value);
    }
};


class Pop : public Command {
    void exec(const std::vector<std::string> &tokens,
              std::stack<SafeInt<int64_t>> &values,
              std::map<std::string, SafeInt<int64_t>> &names_and_values,
              int64_t &result) override {
        if (!values.empty())
            values.pop();
        else
            throw std::invalid_argument("Operation: pop, stack is empty");
    }
};


class Read : public Command {
    void exec(const std::vector<std::string> &tokens,
              std::stack<SafeInt<int64_t>> &values,
              std::map<std::string, SafeInt<int64_t>> &names_and_values,
              int64_t &result) override {
        int value = std::stoi(tokens[1]);
        values.push(value);
    }
};

class Comment : public Command {
    void exec(const std::vector<std::string> &tokens,
              std::stack<SafeInt<int64_t>> &values,
              std::map<std::string, SafeInt<int64_t>> &names_and_values,
              int64_t &result) override {
        for (const auto &word: tokens) {
            std::cout << word << ' ';
        }
        std::cout << std::endl;
    }
};

class Calculator {
public:

    Calculator() = default;

    virtual Command *factoryMethod(const std::string &command) = 0;

};


class CommandCreator : Calculator {
public:
    Command *factoryMethod(const std::string &command) override {
        std::vector<std::string> words;
        std::stringstream ss(command);
        std::string word;
        while (getline(ss, word, ' '))
            words.push_back(word);
        std::string tag = words[0];
        if (tag == "#") {
            return new Comment();
        } else if (tag == "PRINT") {
            return new Print();
        } else if (tag == "PLUS") {
            return new Plus();
        } else if (tag == "DIV") {
            return new Div();
        } else if (tag == "MINUS") {
            return new Minus();
        } else if (tag == "MUL") {
            return new Mul();
        } else if (tag == "READ") {
            return new Read();
        } else if (tag == "PUSH") {
            return new Push();
        } else if (tag == "PEEK") {
            return new Peek();
        } else if (tag == "ABS") {
            return new Abs();
        } else if (tag == "POP") {
            return new Pop();
        } else {
            std::cerr << "ERROR" << std::endl;
            return nullptr;
        }
    }
};