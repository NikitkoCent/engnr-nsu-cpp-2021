//
// Created by Дарья on 06.01.2022.
//

#ifndef CPP_LABS_OPERATIONS_H
#define CPP_LABS_OPERATIONS_H

#include <string>
#include <stack>
#include <map>
#include <sstream>
#include <cmath>
#include <iostream>
#include <utility>
//#include "../../libs/SafeInt/SafeInt.hpp"
#include <memory>


class Pop : public Command {
public:
    explicit Pop(std::string &args);

    void
    command(ContextExecution &context_execution) override;

};


class Push : public Command {
public:
    explicit Push(std::string &args);

    void
    command(ContextExecution &context_execution) override;
};

class Peek : public Command {
public:
    explicit Peek(std::string &args);

    void
    command(ContextExecution &context_execution) override;
};


class Abs : public Command {
public:
    explicit Abs(std::string &args);

    void
    command(ContextExecution &context_execution) override;
};


class Plus : public Command {
public:
    explicit Plus(std::string &args);

    void
    command(ContextExecution &context_execution) override;
};


class Minus : public Command {
public:
    explicit Minus(std::string &args);

    void
    command(ContextExecution &context_execution) override;
};


class Multiply : public Command {
public:
    explicit Multiply(std::string &args);

    void
    command(ContextExecution &context_execution) override;
};


class Division : public Command {
public:
    explicit Division(std::string &args);

    void
    command(ContextExecution &context_execution) override;
};


class Print : public Command {
public:
    explicit Print(std::string &args);

    void
    command(ContextExecution &context_execution) override;
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

#endif //CPP_LABS_OPERATIONS_H
