#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "../../inc/CalcCmds.h"

void push_var_cmd::execute(CalcContext &_calc)
{
    if (_calc.m_varmap.find(arg) == _calc.m_varmap.end())
        throw std::runtime_error("Variable is not found");
    else
        _calc.m_stack.push(_calc.m_varmap[arg]);
}

void push_num_cmd::execute(CalcContext &_calc)
{
    _calc.m_stack.push(arg);
}

void pop_cmd::execute(CalcContext &_calc)
{
    if (_calc.m_stack.empty())
        throw std::runtime_error("Stack is empty");
    else
        _calc.m_stack.pop();
}

void peek_cmd::execute(CalcContext &_calc)
{
    if (_calc.m_stack.empty())
        throw std::runtime_error("Stack is empty");
    else
        _calc.m_varmap[arg] = _calc.m_stack.top();
}

void abs_cmd::execute(CalcContext &_calc)
{
    if (_calc.m_stack.empty())
        throw std::runtime_error("Stack is empty");
    else
    {
        auto item = _calc.m_stack.top();
        _calc.m_stack.pop();
        if (item.Ref() >= 0)
            _calc.m_stack.push(item);
        else
        {
            int64_t temp = *item.data_ptr();
            _calc.m_stack.push(SafeInt<int64_t>(-temp));
        }
    }
}

std::pair<SafeInt<int64_t>, SafeInt<int64_t>> GetTwoElements(CalcContext &_calc)
{
    auto item1 = _calc.m_stack.top();
    _calc.m_stack.pop();
    auto item2 = _calc.m_stack.top();
    _calc.m_stack.pop();
    return std::pair<SafeInt<int64_t>, SafeInt<int64_t>>{item1, item2};
}

void plus_cmd::execute(CalcContext &_calc)
{
    if (_calc.m_stack.size() < 2)
        throw std::runtime_error("Number of elements less than 2");
    else
    {
        auto p = GetTwoElements(_calc);
        _calc.m_stack.push(p.second + p.first);
    }
}

void minus_cmd::execute(CalcContext &_calc)
{
    if (_calc.m_stack.size() < 2)
        throw std::runtime_error("Number of elements less than 2");
    else
    {
        auto p = GetTwoElements(_calc);
        _calc.m_stack.push(p.second - p.first);
    }
}

void mul_cmd::execute(CalcContext &_calc)
{
    if (_calc.m_stack.size() < 2)
        throw std::runtime_error("Number of elements less than 2");
    else
    {
        auto p = GetTwoElements(_calc);
        _calc.m_stack.push(p.second * p.first);
    }
}

void div_cmd::execute(CalcContext &_calc)
{
    if (_calc.m_stack.size() < 2)
        throw std::runtime_error("Number of elements less than 2");
    else
    {
        auto p = GetTwoElements(_calc);
        _calc.m_stack.push(p.second / p.first);
    }
}

void print_cmd::execute(CalcContext &_calc)
{
    if (_calc.m_stack.empty())
        throw std::runtime_error("Stack is empty");
    else
    {
        SafeInt<int64_t> num = _calc.m_stack.top();
        std::cout << (int64_t)num << std::endl;
    }
}

void read_cmd::execute(CalcContext &_calc)
{
    std::int64_t temp;
    std::cin >> temp;
    _calc.m_stack.push(SafeInt<int64_t>(temp));
}

std::unique_ptr<abstract_command> CreateAbstCmd(std::string &command)
{
    auto tokens = split(command);
    if (tokens[0] == "POP")
    {
        return std::unique_ptr<pop_cmd>(new pop_cmd);
    }
    else if (tokens[0] == "PUSH")
    {
        if (tokens.size() != 2)
            throw std::runtime_error("Required 2 arguements");
        if (std::isdigit(static_cast<unsigned char>(tokens[1][0])) || tokens[1][0] == '-')
        {
            return std::unique_ptr<push_num_cmd>{new push_num_cmd(SafeInt<int64_t>(std::stoi(tokens[1])))};
        }
        else
        {
            return std::unique_ptr<push_var_cmd>{new push_var_cmd(std::move(tokens[1]))};
        }
    }
    else if (tokens[0] == "PEEK")
    {
        if (tokens.size() != 2)
            throw std::runtime_error("Required 2 arguements");
        return std::unique_ptr<peek_cmd>{new peek_cmd(std::move(tokens[1]))};
    }
    else if (tokens[0] == "ABS")
    {
        if (tokens.size() != 1)
            throw std::runtime_error("No arguements required");
        return std::unique_ptr<abs_cmd>{new abs_cmd()};
    }
    else if (tokens[0] == "PLUS")
    {
        if (tokens.size() != 1)
            throw std::runtime_error("No arguements required");
        return std::unique_ptr<plus_cmd>{new plus_cmd()};
    }
    else if (tokens[0] == "MINUS")
    {
        if (tokens.size() != 1)
            throw std::runtime_error("No arguements required");
        return std::unique_ptr<minus_cmd>{new minus_cmd()};
    }
    else if (tokens[0] == "MUL")
    {
        if (tokens.size() != 1)
            throw std::runtime_error("No arguements required");
        return std::unique_ptr<mul_cmd>{new mul_cmd()};
    }
    else if (tokens[0] == "DIV")
    {
        if (tokens.size() != 1)
            throw std::runtime_error("No arguements required");
        return std::unique_ptr<div_cmd>{new div_cmd()};
    }
    else if (tokens[0] == "PRINT")
    {
        if (tokens.size() != 1)
            throw std::runtime_error("No arguements required");
        return std::unique_ptr<print_cmd>{new print_cmd()};
    }
    else if (tokens[0] == "READ")
    {
        if (tokens.size() != 1)
            throw std::runtime_error("No arguements required");
        return std::unique_ptr<read_cmd>{new read_cmd()};
    }
    else
    {
        std::cout << command << std::endl;
        throw std::runtime_error("Command not found");
    }
}

std::vector<std::string> split(const std::string &s)
{
    const std::string delimiter(" ");
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos)
    {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}