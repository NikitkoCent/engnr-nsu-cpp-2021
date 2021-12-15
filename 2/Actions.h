//
// Created by Mikhail Okan on 15.11.2021.
//

#ifndef STACK_CALC_ACTIONS_H
#define STACK_CALC_ACTIONS_H
#include <string>
#include <sstream>
#include <stack>
#include <map>
#include "SafeInt/SafeInt.hpp"
#include "Excpetions.h"

namespace StackActions{
    typedef struct context {
        std::stack<SafeInt<long>> st;
        std::map<std::string, SafeInt<long>> vars;
    } Context;

    class Action {
    protected:
        std::istringstream args;
    public:
        explicit Action(std::string &_args);

        virtual void act(Context &context) = 0;

        static bool is_number(const std::string &line);

        virtual ~Action() = default;
    };

    class ArithmeticAction : public Action {
    public:
        explicit ArithmeticAction(std::string &_args) : Action(_args) {};

        static SafeInt<long> pop(std::stack<SafeInt<long>> &st);
    };

    class Push : public Action {
    public:
        explicit Push(std::string &_args) : Action(_args) {};

        void act(Context &context) override;
    };

    class Pop : public Action {
    public:
        explicit Pop(std::string &_args) : Action(_args) {};

        void act(Context &context) override;
    };

    class Peek : public Action {
    public:
        explicit Peek(std::string &_args) : Action(_args) {};

        void act(Context &context) override;
    };

    class Print : public Action {
    public:
        explicit Print(std::string &_args) : Action(_args) {};

        void act(Context &context) override;
    };

    class Read : public Action {
    public:
        explicit Read(std::string &_args) : Action(_args) {};

        void act(Context &context) override;
    };

    class Abs : public ArithmeticAction {
    public:
        explicit Abs(std::string &_args) : ArithmeticAction(_args) {};

        void act(Context &context) override;
    };

    class Plus : public ArithmeticAction {
    public:
        explicit Plus(std::string &_args) : ArithmeticAction(_args) {};

        void act(Context &context) override;
    };

    class Minus : public ArithmeticAction {
    public:
        explicit Minus(std::string &_args) : ArithmeticAction(_args) {};

        void act(Context &context) override;
    };

    class Mul : public ArithmeticAction {
    public:
        explicit Mul(std::string &_args) : ArithmeticAction(_args) {};

        void act(Context &context) override;
    };

    class Div : public ArithmeticAction {
    public:
        explicit Div(std::string &_args) : ArithmeticAction(_args) {};

        void act(Context &context) override;
    };
}


#endif //STACK_CALC_ACTIONS_H
