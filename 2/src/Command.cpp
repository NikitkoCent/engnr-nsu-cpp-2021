//
// Created by Dasha Shestakova on 07.01.2022.
//

#include "Command.h"
#include <exception>
#include <iostream>
#include <algorithm>
#include "Exceptions.h"

int64_t Context::pop() {
    auto first = top();
    calc_stack_avokado.pop();
    return first;
}

int64_t Context::top() {
    if (calc_stack_avokado.empty())
        throw EmptyStack();
    auto first = calc_stack_avokado.top();
    return first;
}

void Context::set_variable(string &name, int64_t &value) {
    variables[name] = value;
}

int64_t Context::get_variable(string &name) {
    auto el = variables.find(name);
    if (el == variables.end())
        throw WrongArgument();
    return el->second;
}

void Context::push(int64_t val) {
    calc_stack_avokado.push(val);
}


void BinaryArithmeticalCommand::eval() {
    SafeInt<int64_t> first = context.pop();
    SafeInt<int64_t> second = context.pop();
    auto result = command(first, second);
    context.push(result);
}

BinaryArithmeticalCommand::BinaryArithmeticalCommand(Context &curContext) : ArithmeticalCommand(curContext) {}

int64_t Div::command(SafeInt<int64_t> first, SafeInt<int64_t> second) {

    int64_t a = first, b = second, res;
    if (a == 0)
        throw DivideByZero();
    SafeDivide(b, a, res);
    return res;
}

Div::Div(Context &curContext) : BinaryArithmeticalCommand(curContext) {}

void UnaryArithmeticalCommand::eval() {
    SafeInt<int64_t> first = context.pop();
    auto result = command(first);
    context.push(result);
}

UnaryArithmeticalCommand::UnaryArithmeticalCommand(Context &curContext) : ArithmeticalCommand(curContext) {}

void Read::eval() {
    string val;
    cin >> val;
    try {
        int64_t value = stoi(val);
        context.push(value);
    } catch (invalid_argument &e) {
        throw WrongArgument();
    }

}

Read::Read(Context &curContext) : NonArgsCommand(curContext) {}

void Print::eval() {
    cout << context.top() << endl;
}

Print::Print(Context &curContext) : NonArgsCommand(curContext) {}

void Peek::eval(string &args) {
    auto val = context.top();
    context.set_variable(args, val);
}


void Push::eval(string &args) {
    try {
        int64_t value = stoi(args);
        context.push(value);
    } catch (exception &e) {
        auto val = context.get_variable(args);
        context.push(val);
    }
}

ArithmeticalCommand::ArithmeticalCommand(Context &curContext) : NonArgsCommand(curContext) {}
