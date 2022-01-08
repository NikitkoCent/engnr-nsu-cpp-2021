//
// Created by Дарья on 06.01.2022.
//

#ifndef CPP_LABS_ERRORS_H
#define CPP_LABS_ERRORS_H

#include "Commands.h"
#include "Operations.h"
#include "lib/safeint/SafeInt.hpp"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <memory>
#include <charconv>
#include <algorithm>

using std::string;

class StackException : public std::runtime_error {
    string message = "Error: ";
public:
    explicit StackException(const string &Message) : runtime_error(Message),
                                                              message(Message) {};
    const char *what() const noexcept override {
        return message.c_str();
    }
};

class WrongArgument : public StackException {
public:
    WrongArgument() : StackException("WrongArg") {}
};

class EmptyStack : public StackException {
public:
    EmptyStack() : StackException("Stack is Empty") {}
};

class UnknownCommand : public StackException {
public:
    explicit UnknownCommand(const string &Message) : StackException(Message) {}
    UnknownCommand() : StackException("Unknown command!") {}
};

class OverflowException : public StackException {
public:
    OverflowException() : StackException("Overflow Exception") {}
};

class DivisionByZero : public StackException {
public:
    DivisionByZero() : StackException("DivisionByZero Error") {}
};

#endif //CPP_LABS_ERRORS_H
