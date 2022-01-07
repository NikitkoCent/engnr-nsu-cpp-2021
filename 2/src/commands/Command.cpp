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

Context::Context(ostream &output) : output(output) {}




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
    context.output << context.top() << endl;
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

shared_ptr<Command> get_command_by_string(string &cur_string, Context &context) {
    shared_ptr<Command> operation;
    if (cur_string.empty()) {
        operation = nullptr;
    } else if (cur_string == "POP") {
        operation = shared_ptr<Command>(new Pop(context));
    } else if (cur_string == "PUSH") {
        operation = shared_ptr<Command>(new Push(context));
    } else if (cur_string == "PEEK") {
        operation = shared_ptr<Command>(new Peek(context));
    } else if (cur_string == "ABS") {
        operation = shared_ptr<Command>(new Abs(context));
    } else if (cur_string == "PLUS") {
        operation = shared_ptr<Command>(new Plus(context));
    } else if (cur_string == "MINUS") {
        operation = shared_ptr<Command>(new Minus(context));
    } else if (cur_string == "MUL") {
        operation = shared_ptr<Command>(new Mul(context));
    } else if (cur_string == "DIV") {
        operation = shared_ptr<Command>(new Div(context));
    } else if (cur_string == "PRINT") {
        operation = shared_ptr<Command>(new Print(context));
    } else if (cur_string == "READ") {
        operation = shared_ptr<Command>(new Read(context));
    } else {
        if (cur_string != "#") {
            throw UnknownArgument("Unknown command: " + cur_string);
        } else {
            operation = shared_ptr<Command>(new Comment(context));
        }
    }
    return operation;
}


void parse_stream(istream &stream, Context &context) {
    while (!stream.eof()) {
        string strCommand;
        stream >> strCommand;
        shared_ptr<Command> command = get_command_by_string(strCommand, context);
        if (auto argsCommand = dynamic_pointer_cast<ArgsCommand>(command)) {
            string args;
            getline(stream, args);
            argsCommand->eval(args);
        } else if (auto nonArgsCommand = dynamic_pointer_cast<NonArgsCommand>(command)) {
            nonArgsCommand->eval();
        }
    }
}