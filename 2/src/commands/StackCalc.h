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


class StackException : public std::runtime_error {
    std::string what_message = "Error: ";
public:
    explicit StackException(const std::string &whatMessage) : runtime_error(whatMessage),
                                                what_message(whatMessage) {};
    const char *what() const noexcept override {
        return what_message.c_str();
    }
};

class WrongArgument : public StackException {
public:
    explicit WrongArgument(const std::string &whatMessage) : StackException(whatMessage) {}
    WrongArgument() : StackException("WrongArg") {}
};

class EmptyStack : public StackException {
public:
    explicit EmptyStack(const std::string &whatMessage) : StackException(whatMessage) {}
    EmptyStack() : StackException("Stack is Empty") {}
};

class FewElementError : public StackException {
public:
    explicit FewElementError(const std::string &whatMessage) : StackException(whatMessage) {}
    FewElementError() : StackException("FewElementError") {}
};

class UnknownCommand : public StackException {
public:
    explicit UnknownCommand(const std::string &whatMessage) : StackException(whatMessage) {}
    UnknownCommand() : StackException("Unknown command was found") {}
};

class OverflowException : public StackException {
public:
    explicit OverflowException(const std::string &whatMessage) : StackException(whatMessage) {}
    OverflowException() : StackException("Overflow happened") {}
};

class DivisionByZero : public StackException {
public:
    explicit DivisionByZero(const std::string &whatMessage) : StackException(whatMessage) {}
    DivisionByZero() : StackException("DivisionByZeroError") {}
};

class CustomException : public SafeIntException{
public:
    static void SafeIntOnOverflow();
};

struct ContextExecution {
    std::stack<SafeInt<int64_t, CustomException>> stack;
    std::map<std::string, SafeInt<int64_t, CustomException>> variables;
};


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
    explicit PopException(const std::string &whatMessage) : EmptyStack(whatMessage) {}
    PopException() : EmptyStack("POP operation failed.") {}
};

class Pop : public Command {
public:
    explicit Pop(std::string &args);

    void
    command(ContextExecution &context_execution) override;

};


class PushException : public WrongArgument {
public:
    explicit PushException(const std::string &whatMessage) : WrongArgument(whatMessage) {}
    PushException() : WrongArgument("PUSH operation failed.") {}
};

class Push : public Command {
public:
    explicit Push(std::string &args);

    void
    command(ContextExecution &context_execution) override;
};


class PeekException : public EmptyStack {
public:
    explicit PeekException(const std::string &whatMessage) : EmptyStack(whatMessage) {}
    PeekException() : EmptyStack("PEEK operation failed.") {}
};

class Peek : public Command {
public:
    explicit Peek(std::string &args);

    void
    command(ContextExecution &context_execution) override;
};


class AbsException : public EmptyStack {
public:
    explicit AbsException(const std::string &whatMessage) : EmptyStack(whatMessage) {}
    AbsException() : EmptyStack("ABS operation failed.") {}
};

class Abs : public Command {
public:
    explicit Abs(std::string &args);

    void
    command(ContextExecution &context_execution) override;
};


class PlusException : public FewElementError {
public:
    explicit PlusException(const std::string &whatMessage) : FewElementError(whatMessage) {}
    PlusException() : FewElementError("PLUS operation failed.") {}
};

class Plus : public Command {
public:
    explicit Plus(std::string &args);

    void
    command(ContextExecution &context_execution) override;
};

class MinusException : public FewElementError {
public:
    explicit MinusException(const std::string &whatMessage) : FewElementError(whatMessage) {}
    MinusException() : FewElementError("MINUS operation failed.") {}
};

class Minus : public Command {
public:
    explicit Minus(std::string &args);

    void
    command(ContextExecution &context_execution) override;
};


class MultiplyException : public FewElementError {
public:
    explicit MultiplyException(const std::string &whatMessage) : FewElementError(whatMessage) {}
    MultiplyException() : FewElementError("MUL operation failed.") {}
};

class Multiply : public Command {
public:
    explicit Multiply(std::string &args);

    void
    command(ContextExecution &context_execution) override;
};


class DivisionException : public FewElementError {
public:
    explicit DivisionException(const std::string &whatMessage) : FewElementError(whatMessage) {}
    DivisionException() : FewElementError("DIV operation failed.") {}
};

class Division : public Command {
public:
    explicit Division(std::string &args);

    void
    command(ContextExecution &context_execution) override;
};


class PrintException : public EmptyStack {
public:
    explicit PrintException(const std::string &whatMessage) : EmptyStack(whatMessage) {}
    PrintException() : EmptyStack("PRINT operation failed.") {}
};

class Print : public Command {
public:
    explicit Print(std::string &args);

    void
    command(ContextExecution &context_execution) override;
};


class ReadException : public WrongArgument {
public:
    explicit ReadException(const std::string &whatMessage) : WrongArgument(whatMessage) {}
    ReadException() : WrongArgument("READ operation failed.") {}
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

    std::map<std::string, SafeInt<int64_t, CustomException>> FindResult() {
        return context_execution.variables;
    }
};

StackCalc ReadFromStream(std::istream &str);

StackCalc OneCommandRead();

#endif







