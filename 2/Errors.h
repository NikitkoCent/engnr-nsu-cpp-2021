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


class CustomException : public SafeIntException{
public:
    static void SafeIntOnOverflow();
};

class StackException : public std::runtime_error {
    std::string message = "Error: ";
public:
    explicit StackException(const std::string &Message) : runtime_error(Message),
                                                              message(Message) {};
    const char *what() const noexcept override {
        return message.c_str();
    }
};

class WrongArgument : public StackException {
public:
    explicit WrongArgument(const std::string &Message) : StackException(Message) {}
    WrongArgument() : StackException("WrongArg") {}
};

class EmptyStack : public StackException {
public:
    explicit EmptyStack(const std::string &Message) : StackException(Message) {}
    EmptyStack() : StackException("Stack is Empty") {}
};

class UnknownCommand : public StackException {
public:
    explicit UnknownCommand(const std::string &Message) : StackException(Message) {}
    UnknownCommand() : StackException("Unknown command!") {}
};

class OverflowException : public StackException {
public:
    explicit OverflowException(const std::string &Message) : StackException(Message) {}
    OverflowException() : StackException("Overflow Exception") {}
};

class DivisionByZero : public StackException {
public:
    explicit DivisionByZero(const std::string &Message) : StackException(Message) {}
    DivisionByZero() : StackException("DivisionByZero Error") {}
};

void CustomException::SafeIntOnOverflow() {
    throw OverflowException();
}


#endif //CPP_LABS_ERRORS_H
