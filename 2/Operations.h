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
#include "lib/safeint/SafeInt.hpp"
#include "Commands.h"
#include "Errors.h"
#include <memory>



struct Memory {
    std::stack<SafeInt<int64_t, CustomException>> stack;
    std::map<std::string, SafeInt<int64_t, CustomException>> variables;
};

class Operation {
public:
    explicit Operation(std::string &args) { params = args; }

    virtual void
    command (Memory &memory) = 0;

    virtual ~Operation() = default ;

protected:
    std::string params;
};

class Pop : public Operation {
public:
    explicit Pop(std::string &args);

    void command(Memory &memory) override;
};

class Push : public Operation {
public:
    explicit Push(std::string &args);

    void
    command(Memory &memory) override;
};

class Peek : public Operation {
public:
    explicit Peek(std::string &args);

    void
    command(Memory &memory) override;
};

class Abs : public Operation {
public:
    explicit Abs(std::string &args);

    void
    command(Memory &memory) override;
};

class Plus : public Operation {
public:
    explicit Plus(std::string &args);

    void
    command(Memory &memory) override;
};

class Minus : public Operation {
public:
    explicit Minus(std::string &args);

    void
    command(Memory &memory) override;
};

class Multiply : public Operation {
public:
    explicit Multiply(std::string &args);

    void
    command(Memory &memory) override;
};

class Division : public Operation {
public:
    explicit Division(std::string &args);

    void
    command(Memory &memory) override;
};

class Print : public Operation {
public:
    explicit Print(std::string &args);

    void
    command(Memory &memory) override;
};

class Read : public Operation {
public:
    explicit Read(std::string &args);

    void command(Memory &memory) override;
};

class Comment : public Operation {
public:
    explicit Comment(std::string &args);

    void command(Memory &memory) override;
};

#endif //CPP_LABS_OPERATIONS_H
