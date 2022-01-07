//
// Created by Dasha Shestakova on 07.01.2022.
//

#ifndef CALC_COMMAND_H
#define CALC_COMMAND_H

#include <map>
#include <stack>
#include <string>
#include <iostream>
#include <memory>
#include "../../libs/SafeInt/SafeInt.hpp"

using namespace std;

class Context {
private:
    map<string, int64_t> variables;
    stack<int64_t> calc_stack_avokado;

public:
    ostream &output;

    Context(ostream &output);


    int64_t pop();

    int64_t top();

    void set_variable(string &name, int64_t &value);

    int64_t get_variable(string &name);

    void push(int64_t val);
};

class Command {
protected:
    Context &context;
public:
//    Command() = default;

    explicit Command(Context &cur_context) : context(cur_context) {};

    virtual ~Command() = default;
};

class ArgsCommand : public Command {
public:
    explicit ArgsCommand(Context &curContext) : Command(curContext) {};

    virtual void eval(string &args) = 0;
};

class NonArgsCommand : public Command {
public:
    explicit NonArgsCommand(Context &curContext) : Command(curContext) {};

    virtual void eval() = 0;
};


// region ArithmeticalCommand
class ArithmeticalCommand : public NonArgsCommand {
public:
    explicit ArithmeticalCommand(Context &curContext);
};

class BinaryArithmeticalCommand : public ArithmeticalCommand {
protected:
    virtual int64_t command(SafeInt<int64_t> first, SafeInt<int64_t> second) = 0;

public:
    explicit BinaryArithmeticalCommand(Context &curContext);

    void eval() override;
};

class Plus : public BinaryArithmeticalCommand {
public:
    explicit Plus(Context &curContext) : BinaryArithmeticalCommand(curContext) {}

private:
    int64_t command(SafeInt<int64_t> first, SafeInt<int64_t> second) override { return first + second; };
};

class Minus : public BinaryArithmeticalCommand {
public:
    explicit Minus(Context &curContext) : BinaryArithmeticalCommand(curContext) {}

private:
    int64_t command(SafeInt<int64_t> first, SafeInt<int64_t> second) override { return second - first; };
};

class Mul : public BinaryArithmeticalCommand {
public:
    explicit Mul(Context &curContext) : BinaryArithmeticalCommand(curContext) {}

private:
    int64_t command(SafeInt<int64_t> first, SafeInt<int64_t> second) override { return first * second; };
};

class Div : public BinaryArithmeticalCommand {
    int64_t command(SafeInt<int64_t> first, SafeInt<int64_t> second) override;

public:
    explicit Div(Context &curContext);
};


class UnaryArithmeticalCommand : public ArithmeticalCommand {
public:
    explicit UnaryArithmeticalCommand(Context &curContext);

protected:
    virtual int64_t command(SafeInt<int64_t> first) = 0;

public:
    void eval() override;
};

class Abs : public UnaryArithmeticalCommand {
public:
    explicit Abs(Context &curContext) : UnaryArithmeticalCommand(curContext) {}

private:
    int64_t command(SafeInt<int64_t> first) override { return first < 0 ? -first : first; };
};

//endregion

//region NonArgsCommand

class Read : public NonArgsCommand {
public:
    explicit Read(Context &curContext);

public:
    void eval() override;
};

class Print : public NonArgsCommand {
public:
    explicit Print(Context &curContext);

    void eval() override;
};

class Pop : public NonArgsCommand {
public:
    explicit Pop(Context &curContext) : NonArgsCommand(curContext) {}

    void eval() override { context.pop(); };
};


//endregion

//region ArgsCommand

class Comment : public ArgsCommand {
public:
    explicit Comment(Context &curContext) : ArgsCommand(curContext) {}

    void eval(string &args) override {};
};

class Peek : public ArgsCommand {
public:
    explicit Peek(Context &curContext) : ArgsCommand(curContext) {}

    void eval(string &args) override;
};

class Push : public ArgsCommand {
public:
    explicit Push(Context &curContext) : ArgsCommand(curContext) {}

    void eval(string &args) override;
};
//endregion


shared_ptr<Command> get_command_by_string(string &cur_string, Context &context);
void parse_stream(istream &stream, Context &context);
#endif //CALC_COMMAND_H
