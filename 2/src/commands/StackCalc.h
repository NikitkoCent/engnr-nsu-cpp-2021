#ifndef CPP_LAB2_STACKCALC_H
#define CPP_LAB2_STACKCALC_H

#include <string>
#include <stack>
#include <map>
#include <sstream>
#include <cmath>
#include <iostream>
#include <utility>
#include "../../libs/SafeInt/SafeInt.hpp"
#include <memory>


class StackException: public std::runtime_error{
public:
    std::string text = "ERROR: ";
    StackException() : std::runtime_error(text) {
        std::cerr << text << std::endl;
    };

    virtual std::string what() = 0;
};

class WrongArgument : public StackException {
public:
    std::string wrong;

    WrongArgument() : wrong("Wrong argument ") {
    };

    virtual std::string what() override;
};

class EmptyStack : public StackException {
public:
    std::string empty;

    EmptyStack() : empty("Empty stack error: ") {
    };

    virtual std::string what() override;
};

class FewElementError : public StackException {
public:
    std::string few_elem;

    FewElementError() : few_elem("Too few elements in stack for operation:") {
    };

    virtual std::string what() override;
};

//class CustomException : public SafeIntException {
//public:
//    static void SafeIntOnOverflow();
//};


typedef struct context_execution {
    std::stack<SafeInt<int64_t>> stack;
    std::map<std::string, SafeInt<int64_t>> variables;
} ContextExecution;


class Command {
public:
    explicit Command(std::string &args) { params = args; }

    virtual void
    command(ContextExecution &context_execution) = 0;

    virtual ~Command() = default;

protected:
    std::string params;
};

class PopException : public EmptyStack {
public:
    std::string pop;

    PopException() : pop("POP operation failed.") {
    };

    virtual std::string what() override;
};

class Pop : public Command {
public:
    explicit Pop(std::string &args);

    void
    command(ContextExecution &context_execution) override;

};

class PushException : public WrongArgument {
public:
    std::string push;

    explicit PushException() : push("Variable doesn't exist. PUSH operation failed.") {
    };

    virtual std::string what() override;
};

class Push : public Command {
public:
    explicit Push(std::string &args);

    void
    command(ContextExecution &context_execution) override;
};

class PeekException : public EmptyStack {
public:
    std::string peek;

    explicit PeekException() : peek("PEEK operation failed.") {
    };

    virtual std::string what() override;
};

class Peek : public Command {
public:
    explicit Peek(std::string &args);

    void
    command(ContextExecution &context_execution) override;
};

class AbsException : public EmptyStack {
public:
    std::string abs;

    explicit AbsException() : abs("ABS operation failed.") {
    };

    virtual std::string what() override;
};

class Abs : public Command {
public:
    explicit Abs(std::string &args);

    void
    command(ContextExecution &context_execution) override;
};

class PlusException : public FewElementError {
public:
    std::string plus;

    explicit PlusException() : plus("PLUS operation failed.") {
    };

    virtual std::string what() override;
};

class Plus : public Command {
public:
    explicit Plus(std::string &args);

    void
    command(ContextExecution &context_execution) override;
};

class MinusException : public FewElementError {
public:
    std::string minus;

    explicit MinusException() : minus("MINUS operation failed.") {
    };

    virtual std::string what() override;
};

class Minus : public Command {
public:
    explicit Minus(std::string &args);

    void
    command(ContextExecution &context_execution) override;
};

class MultiplyException : public FewElementError {
public:
    std::string mul;

    explicit MultiplyException() : mul("MUL operation failed.") {
    };

    virtual std::string what() override;
};

class Multiply : public Command {
public:
    explicit Multiply(std::string &args);

    void
    command(ContextExecution &context_execution) override;
};

class DivisionException : public FewElementError {
public:
    std::string div;

    explicit DivisionException() : div("DIV operation failed.") {
    };

    virtual std::string what() override;
};

class Division : public Command {
public:
    explicit Division(std::string &args);

    void
    command(ContextExecution &context_execution) override;
};

class PrintException : public EmptyStack {
public:
    std::string print;

    PrintException() : print("PRINT operation failed.") {
    };

    virtual std::string what() override;
};

class Print : public Command {
public:
    explicit Print(std::string &args);

    void
    command(ContextExecution &context_execution) override;
};

class ReadException : public WrongArgument {
public:
    std::string read;

    explicit ReadException() : read("READ operation failed.") {
    };

    virtual std::string what() override;
};

class Read : public Command {
public:
    explicit Read(std::string &args);

    void command(ContextExecution &context_execution) override;
};

class Comment : public Command {
public:
    explicit Comment(std::string &args);

    void command(ContextExecution &context_execution) override;
};

class StackCalc {
    ContextExecution context_execution;
public:
    void command(std::unique_ptr<Command> cmd);

    Command *read_command(std::string &command_line);

    std::map<std::string, SafeInt<int64_t>> FindResult() {
        return context_execution.variables;
    }
};

StackCalc ReadFromStream(std::istream &str);

StackCalc OneCommandRead();

#endif
