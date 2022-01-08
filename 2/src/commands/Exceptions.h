//
// Created by Dasha Shestakova on 07.01.2022.
//

#ifndef CALC_EXCEPTIONS_H
#define CALC_EXCEPTIONS_H

#include <stdexcept>
#include <string>

using namespace std;

class BaseException : public runtime_error {
    std::string msg = "Error: ";
public:
    explicit BaseException(const std::string &whatMsg) : runtime_error(whatMsg),
                                                         msg(whatMsg) {};

    [[nodiscard]] const char *what() const noexcept override {
        return msg.c_str();
    }
};

class WrongArgument : public BaseException {
public:
    explicit WrongArgument(const std::string &whatMessage) : BaseException(whatMessage) {}
    WrongArgument() : BaseException("WrongArg") {}
};

class UnknownArgument : public BaseException {
public:
    explicit UnknownArgument(const std::string &whatMessage) : BaseException(whatMessage) {}
    UnknownArgument() : BaseException("Unknown argument") {}
};

class EmptyStack : public BaseException {
public:
    explicit EmptyStack(const std::string &whatMessage) : BaseException(whatMessage) {}
    EmptyStack() : BaseException("Stack is Empty") {}
};

class DivideByZero : public BaseException {
public:
    explicit DivideByZero(const std::string &whatMessage) : BaseException(whatMessage) {}
    DivideByZero() : BaseException("Divide by zero") {}
};
class ArithmeticalError : public BaseException {
public:
    explicit ArithmeticalError(const std::string &whatMessage) : BaseException(whatMessage) {}
    ArithmeticalError() : BaseException("Arithmetical error") {}
};
#endif //CALC_EXCEPTIONS_H
