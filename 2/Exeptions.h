//
// Created by Артем Шмаков on 02.01.2022.
//

#pragma once
#include <iostream>
#include <string>

namespace CalcExceptions {
    class BaseEx : public std::exception {
    public:
        std::string base_error;

        BaseEx() : base_error("\nStackCalculator exception: \n") {};

        virtual std::string _what() = 0;
    };

    class PushException : public BaseEx {
    public:
        std::string push_error;

        explicit PushException() : push_error("PushException: \n") {}

        std::string _what() override;
    };


    class EmptyVarName : public PushException {
    public:
        std::string fir_push_error;

        explicit EmptyVarName() : fir_push_error("VarName is empty") {}

        std::string _what() override;
    };


    class InvalidInput : public PushException {
    public:
        std::string sec_push_error;

        explicit InvalidInput() : sec_push_error("arg is not an integer or variable") {}

        std::string _what() override;
    };

    class ReadException : public BaseEx {
    public:
        std::string read_error;

        ReadException() : read_error("READ ERROR AAAAAA\n!") {}

        std::string _what() override;
    };

    class EmptyName : public ReadException {
    public:
        std::string name_error;

        EmptyName() : name_error("Where is name of file, user?") {}

        std::string _what() override;
    };


    class StackEx : public BaseEx {
    public:
        std::string stack_error;

        StackEx() : stack_error("Stack problem, booy\n") {}

        std::string _what() override;
    };


    class StackDeficit : public StackEx {
    public:
        std::string Def_error;

        StackDeficit() : Def_error("Stack has less than 2 arguments!") {}

        std::string _what() override;
    };


    class StackEmpty : public StackEx {
    public:
        std::string empty_error;

        StackEmpty() : empty_error("Stack is empty!") {}

        std::string _what() override;
    };


    class DivisionByZero : public BaseEx {
    public:
        std::string zero_error;

        DivisionByZero() : zero_error("Division by 0!") {}

        std::string _what() override;
    };


    class InvalidOperation : public BaseEx {
    public:
        std::string operation_error;

        explicit InvalidOperation() : operation_error("Invalid operation!") {}

        std::string _what() override;
    };

    class PopException : public BaseEx {
    public:
        std::string pop_error;

        explicit PopException() : pop_error("PopEXCEPTION!!!!!!: \n") {}

        std::string _what() override;
    };


    class Empty : public PopException {
    public:
        std::string empty_pop;

        explicit Empty() : empty_pop("WHY ARE YOU POOPING EMPTY STACK BRO?") {}

        std::string _what() override;
    };
}
