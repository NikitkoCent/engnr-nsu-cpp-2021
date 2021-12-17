//
// Created by Mikhail Okan on 15.12.2021.
//

#ifndef STACK_CALC_EXCPETIONS_H
#define STACK_CALC_EXCPETIONS_H
#include <iostream>

namespace StackExceptions {
    class SCException{
    public:
        std::string default_error;

        SCException() : default_error("\nStackCalc Exception: ") {};

        virtual std::string what() = 0;
    };

    class InvalidArgument: public SCException {
    public:
        std::string invalid_error;

        InvalidArgument() : invalid_error("Invalid argument in method ") {}

        virtual std::string what() override;
    };

//
//    class OverflowException: public SCException {
//    public:
//        std::string overflow_error;
//
//        OverflowException() : overflow_error("Overflow exception") {}
//
//        virtual std::string what() override;
//    };


    class PushException: public InvalidArgument {
    public:
        std::string push_error;

        explicit PushException() : push_error("PUSH (arg is not an integer or variable)!") {}

        virtual std::string what() override;
    };


    class ReadException: public InvalidArgument {
    public:
        std::string read_error;

        ReadException() : read_error("READ!") {}

        virtual std::string what() override;
    };


    class StackLack: public SCException {
    public:
        std::string lack_error;

        StackLack() : lack_error("Stack has less than 2 arguments!") {}

        virtual std::string what() override;
    };


    class StackEmpty : public SCException {
    public:
        std::string empty_error;

        StackEmpty() : empty_error("Stack is empty!") {}

        virtual std::string what() override;
    };


    class DivisionByZero: public SCException {
    public:
        std::string zero_error;

        DivisionByZero() : zero_error("Division by zero!") {}

        virtual std::string what() override;
    };


    class InvalidOperation: public SCException {
    public:
        std::string operation_error;

        explicit InvalidOperation() : operation_error("Invalid operation!") {}

        virtual std::string what() override;
    };
}

#endif //STACK_CALC_EXCPETIONS_H
