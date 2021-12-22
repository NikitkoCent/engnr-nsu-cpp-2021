//
// Created by gav on 15/12/2021.
//

#ifndef CPP_LABS_EXCEPTIONS_H
#define CPP_LABS_EXCEPTIONS_H

#include <stdexcept>
#include <cstring>

class StackCalculatorException : public std::runtime_error {
public:
    explicit StackCalculatorException(const char *exc_txt) : std::runtime_error(exc_txt) {}
    explicit StackCalculatorException(const std::string &exc_txt) : std::runtime_error(exc_txt) {}
};

class StackEmptyException : public StackCalculatorException {
public:
    StackEmptyException() : StackCalculatorException("Stack is empty!") {}
};

class InvalidArgumentsException : public StackCalculatorException {
public:
    InvalidArgumentsException() : StackCalculatorException("Command has invalid args!") {}
};

class OverflowException : public StackCalculatorException {
public:
    OverflowException() : StackCalculatorException("Number overflows int64_t!") {}
};

#endif //CPP_LABS_EXCEPTIONS_H
