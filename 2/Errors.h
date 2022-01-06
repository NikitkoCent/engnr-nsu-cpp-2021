//
// Created by Дарья on 06.01.2022.
//

#ifndef CPP_LABS_ERRORS_H
#define CPP_LABS_ERRORS_H

#include "Commands.h"
#include "Operations.h"

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <memory>
#include <charconv>
#include <algorithm>

class WrongArgument : public StackException {
public:
    explicit WrongArgument(const std::string &whatMessage) : StackException(whatMessage) {}
    WrongArgument() : StackException("WrongArg") {}
};

class StackException : public std::runtime_error {
    std::string what_message = "Error: ";
public:
    explicit StackException(const std::string &whatMessage) : runtime_error(whatMessage),
                                                              what_message(whatMessage) {};
    const char *what() const noexcept override {
        return what_message.c_str();
    }
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


class PopException : public EmptyStack {
public:
    explicit PopException(const std::string &whatMessage) : EmptyStack(whatMessage) {}
    PopException() : EmptyStack("POP operation failed.") {}
};

#endif //CPP_LABS_ERRORS_H
