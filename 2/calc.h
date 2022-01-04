//
// Created by Артем Шмаков on 02.01.2022.
//
#pragma once

#include "SafeInt/SafeInt.hpp"
#include "Exeptions.h"

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
#include <istream>
#include "googletest/googletest/include/gtest/gtest.h"


bool is_number(const std::string &line);

struct calculator_data {
    std::stack<SafeInt<int64_t>> values;
    std::map<std::string, SafeInt<int64_t>> compare_names;
};


class Command {
public:
    virtual void rep(const std::vector<std::string> &command_str,
                      calculator_data& data
    ) = 0;
    virtual ~Command() = default; // деструктор

};

class Print : public Command {
    void rep(const std::vector<std::string> &command_str,
              calculator_data &data
    ) override;
};

class Plus final : public Command {
    void rep(const std::vector<std::string> &command_str,
              calculator_data& data
    ) override;
};

class Minus final : public Command {
    void rep(const std::vector<std::string> &command_str,
              calculator_data& data
    ) override;
};

class Mul final : public Command {
    void rep(const std::vector<std::string> &command_str,
              calculator_data& data
    ) override;
};

class Div final : public Command {
    void rep(const std::vector<std::string> &command_str,
              calculator_data& data
    ) override;
};

class Push final : public Command {
    void rep(const std::vector<std::string> &command_str,
              calculator_data& data
    ) override;
};

class Peek final : public Command {
    void rep(const std::vector<std::string> &command_str,
              calculator_data& data
    ) override;
};


class Abs final : public Command {
    void rep(const std::vector<std::string> &command_str,
              calculator_data& data
    ) override;
};


class Pop final : public Command {
    void rep(const std::vector<std::string> &command_str,
              calculator_data& data
    ) override;
};


class Read final : public Command {
    void rep(const std::vector<std::string> &command_str,
              calculator_data& data
    ) override;
};

class Comment final : public Command {
    void rep(const std::vector<std::string> &command_str,
              calculator_data& data
    ) override;
};

class Calculator {
public:

    Calculator() = default;

    virtual Command *factoryMethod(const std::vector<std::string> &commands) = 0;

};


class CommandCreator : Calculator {
public:
    Command *factoryMethod(const std::vector<std::string> &commands) override;
};

void calc_work(std::stringstream& in_s, std::ifstream& in, int args);
