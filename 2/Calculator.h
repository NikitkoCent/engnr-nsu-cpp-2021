#pragma once

#include "libs/SafeInt/SafeInt.hpp"
#include "exception.h"
#include "Calculator.h"

#include <stack>
#include <sstream>
#include <map>
#include <iostream>
#include <cstdint>
#include <cstring>
#include <vector>
#include <iterator>
#include <string>
#include <fstream>

struct calculator_data {
    std::stack<SafeInt<int64_t>> values;
    std::map<std::string, SafeInt<int64_t>> names_and_values;
};

bool is_number(const std::string &line) {
    char *p;
    strtol(line.c_str(), &p, 10);
    return *p == 0;
}

class Command {
public:
    virtual void exec(const std::vector<std::string> &tokens,
                      calculator_data& data,
                      int64_t &result,int args) = 0;
    virtual ~Command() = default;

};

class Print final : public Command {
    void exec(const std::vector<std::string> &tokens,
              calculator_data& data,
              int64_t &result,int args) override {
        if (data.values.empty()) {
            throw PrintEmptyStack();
//            std::cerr << "ERROR";
//            throw std::runtime_error("ERROR");
        }
        std::cout << std::to_string((int64_t) data.values.top()) << std::endl;
    }
};

class Plus final : public Command {
    void exec(const std::vector<std::string> &tokens,
              calculator_data& data,
              int64_t &result,int args) override {
        if (data.values.size() < 2) {
            throw PlusEmptyStack();
//            std::cerr << "ERROR";
//            throw std::runtime_error("ERROR");
        }
        int64_t first_element = data.values.top(); data.values.pop();
        int64_t second_element = data.values.top(); data.values.pop();

        int64_t operation_result;
        SafeAdd(second_element, first_element, operation_result);
        data.values.push(operation_result);
    }
};

class Minus : public Command {
    void exec(const std::vector<std::string> &tokens,
              calculator_data& data,
              int64_t &result,int args) override {
        if (data.values.size() < 2) {
//            std::cerr << "ERROR";
//            throw std::runtime_error("ERROR");
            throw MinusEmptyStack();
        }
        int64_t first_element = data.values.top(); data.values.pop();
        int64_t second_element = data.values.top(); data.values.pop();

        int64_t operation_result;
        SafeSubtract(second_element, first_element, operation_result);
        data.values.push(operation_result);
    }
};

class Mul : public Command {
    void exec(const std::vector<std::string> &tokens,
              calculator_data& data,
              int64_t &result,int args) override {
        if (data.values.size() < 2) {
//            std::cerr << "ERROR";
//            throw std::runtime_error("ERROR");
            throw MulEmptyStack();
        }
        int64_t first_element = data.values.top(); data.values.pop();
        int64_t second_element = data.values.top(); data.values.pop();

        int64_t operation_result;
        SafeMultiply(second_element, first_element, operation_result);
        data.values.push(operation_result);
    }
};

class Div : public Command {
    void exec(const std::vector<std::string> &tokens,
              calculator_data& data,
              int64_t &result,int args) override {
        if (data.values.size() < 2) {
//            std::cerr << "ERROR";
//            throw std::runtime_error("ERROR");
            throw DivEmptyStack();
        }
        int64_t first_element = data.values.top(); data.values.pop();
        int64_t second_element = data.values.top(); data.values.pop();
        if (first_element == 0) {
            throw DivException();
//            std::cerr << "ERROR";
//            throw std::runtime_error("ERROR");
        }
        int64_t operation_result;
        SafeDivide(second_element, first_element, operation_result);
        data.values.push(operation_result);
    }
};

class Push : public Command {
    void exec(const std::vector<std::string> &tokens,
              calculator_data& data,
              int64_t &result,int args) override {
            std::string varname = tokens[1];
            if(varname == "")
                throw PushEmptyVarname();
            if (is_number(varname)) {
                data.values.push(std::stoll(varname));
//                if (!SafeAdd(result_64, result_64, result_64))
//                    throw PushIntegerOverflow();
            } else {
                if (data.names_and_values.find(varname) == data.names_and_values.end()) {
                    throw PushException();
//                std::cerr << "ERROR";
//                throw std::runtime_error("ERROR");
                }
                data.values.push(data.names_and_values[varname]);
            }
    }
};

class Peek : public Command {
    void exec(const std::vector<std::string> &tokens,
              calculator_data& data,
              int64_t &result,int args) override {
        if(data.values.empty()) {
            throw PeekEmptyStack();
//            std::cerr << "ERROR";
//            throw std::runtime_error("ERROR");
        }
        if(args < 2)
            throw PeekEmptyVarname();
        std::string varname = tokens[1];
        data.names_and_values[varname] = data.values.top();
    }
};


class Abs : public Command {
    void exec(const std::vector<std::string> &tokens,
              calculator_data& data,
              int64_t &result,int args) override {
        if(data.values.empty()) {
            throw AbsStackEmpty();
//            std::cerr << "ERROR";
//            throw std::runtime_error("ERROR");
        }
        int64_t value = data.values.top();
        data.values.pop();
        value = value > 0 ? value : -value;
        data.values.push(value);
    }
};


class Pop : public Command {
    void exec(const std::vector<std::string> &tokens,
              calculator_data& data,
              int64_t &result,int args) override {
        if (!data.values.empty())
            data.values.pop();
        else {
            throw PopStackEmpty();
//            std::cerr << "ERROR";
//            throw std::runtime_error("ERROR");
        }
    }
};


class Read : public Command {
    void exec(const std::vector<std::string> &tokens,
              calculator_data& data,
              int64_t &result,int args) override {
        std::string varname = tokens[1];
        data.values.push(std::stoll(varname));
    }
};

class Comment : public Command {
    void exec(const std::vector<std::string> &tokens,
              calculator_data& data,
              int64_t &result,int args) override {
        //nothing
    }
};

class Calculator {
public:

    Calculator() = default;

    virtual Command *factoryMethod(const std::vector<std::string> &commands) = 0;

};


class CommandCreator : Calculator {
public:
    Command *factoryMethod(const std::vector<std::string> &commands) override {
        std::string tag = commands[0];
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
            throw CommandException();
//            std::cerr << "ERROR";
//            throw std::runtime_error("ERROR");
        }
    }
};
