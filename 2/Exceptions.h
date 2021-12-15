//
// Created by gav on 15/12/2021.
//

#ifndef CPP_LABS_EXCEPTIONS_H
#define CPP_LABS_EXCEPTIONS_H

#include <stdexcept>

class StackCalculatorException : std::runtime_error {
public:
    explicit StackCalculatorException(const char *exc_txt) : std::runtime_error(exc_txt) {}

    explicit StackCalculatorException(const std::string &exc_txt) : std::runtime_error(exc_txt) {}
};

class StackEmptyException : StackCalculatorException {
public:
    explicit StackEmptyException(const char *command_name) : StackCalculatorException(
            strcat("Stack is empty! Calling command: ", command_name)) {}
};

class InvalidArgumentsException : StackCalculatorException {
public:
    InvalidArgumentsException(const char *command_name, const char* args) : StackCalculatorException(
            strcat(strcat(strcat("Command has invalid args:", args), "; Reason: "), command_name)) {}
    InvalidArgumentsException(const char *command_name, std::string &args) : StackCalculatorException(
            strcat(strcat(strcat("Command has invalid args:", args.c_str()), "; Reason: "), command_name)) {}
};

#endif //CPP_LABS_EXCEPTIONS_H
