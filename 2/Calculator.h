//
// Created by kiril on 21.12.2021.
//

#ifndef INC_2LAB_CALCULATOR_H
#define INC_2LAB_CALCULATOR_H

#pragma once

#include "libs/SafeInt/SafeInt.hpp"
#include "exception.h"

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

bool is_number(const std::string &line);

class Command {
public:
    virtual void exec(const std::vector<std::string> &tokens,
                      calculator_data& data,
                      int args) = 0;
    virtual ~Command() = default;

};

class Print : public Command {
    void exec(const std::vector<std::string> &tokens,
                     calculator_data &data,
                     int args) override;
};

class Plus final : public Command {
    void exec(const std::vector<std::string> &tokens,
              calculator_data& data,
              int args) override;
};

class Minus final : public Command {
    void exec(const std::vector<std::string> &tokens,
              calculator_data& data,
              int args) override;
};

class Mul final : public Command {
    void exec(const std::vector<std::string> &tokens,
              calculator_data& data,
              int args) override;
};

class Div final : public Command {
    void exec(const std::vector<std::string> &tokens,
              calculator_data& data,
              int args) override;
};

class Push final : public Command {
    void exec(const std::vector<std::string> &tokens,
              calculator_data& data,
              int args) override;
};

class Peek final : public Command {
    void exec(const std::vector<std::string> &tokens,
              calculator_data& data,
              int args) override;
};


class Abs final : public Command {
    void exec(const std::vector<std::string> &tokens,
              calculator_data& data,
              int args) override;
};


class Pop final : public Command {
    void exec(const std::vector<std::string> &tokens,
              calculator_data& data,
              int args) override;
};


class Read final : public Command {
    void exec(const std::vector<std::string> &tokens,
              calculator_data& data,
              int args) override;
};

class Comment final : public Command {
    void exec(const std::vector<std::string> &tokens,
              calculator_data& data,
              int args) override;
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
        }
    }
};


#endif //INC_2LAB_CALCULATOR_H
