#pragma once

#include "Calculator.h"
#include <vector>
#include <string>
#include <cmath>
#include <memory>

using namespace ns_Calc;

struct abstract_command {
    virtual ~abstract_command() = default;

    virtual void execute(CalcContext &) = 0;
};

//Stack operations
struct push_var_cmd : abstract_command {
    explicit push_var_cmd(std::string &&_arg) : arg(_arg) {};
    std::string arg;

    void execute(CalcContext &_calc) override;
};

struct push_num_cmd : abstract_command {
    explicit push_num_cmd(SafeInt<int64_t> _arg) : arg(_arg) {};
    SafeInt<int64_t> arg;

    void execute(CalcContext &_calc) override;
};

struct pop_cmd : abstract_command {
    void execute(CalcContext &_calc) override;
};

struct peek_cmd : abstract_command {
    explicit peek_cmd(std::string &&_arg) : arg(_arg) {};
    std::string arg;

    void execute(CalcContext &_calc) override;
};

//Arithmethic operations
struct abs_cmd : abstract_command {
    void execute(CalcContext &_calc) override;
};

struct plus_cmd : abstract_command {
    void execute(CalcContext &) override;
};

struct minus_cmd : abstract_command {
    void execute(CalcContext &) override;
};

struct mul_cmd : abstract_command {
    void execute(CalcContext &) override;
};

struct div_cmd : abstract_command {
    void execute(CalcContext &) override;
};

//Misc operations
struct print_cmd : abstract_command {
    void execute(CalcContext &) override;
};

struct read_cmd : abstract_command {
    void execute(CalcContext &) override;
};

std::vector<std::string> split(const std::string& s);

std::unique_ptr<abstract_command> CreateAbstCmd(std::string &command);