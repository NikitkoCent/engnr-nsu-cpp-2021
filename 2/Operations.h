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

using std::stack;
using std::map;
using std::string;

struct Memory {
    stack<SafeInt<int64_t>> is_stack;
    map<std::string, SafeInt<int64_t>> variables;
};

class Operation {
public:
    explicit Operation( string &args) { params = args; }

    virtual void
    command (Memory &memory) = 0;

    virtual ~Operation() = default ;

protected:
    string params;
};

class Pop : public Operation {
public:
    explicit Pop(string &args);

    void command(Memory &memory) override;
};

class Push : public Operation {
public:
    explicit Push(string &args);

    void
    command(Memory &memory) override;
};

class Peek : public Operation {
public:
    explicit Peek (string &args);

    void
    command(Memory &memory) override;
};

class Abs : public Operation {
public:
    explicit Abs(string &args);

    void
    command(Memory &memory) override;
};

class Plus : public Operation {
public:
    explicit Plus(string &args);

    void
    command(Memory &memory) override;
};

class Minus : public Operation {
public:
    explicit Minus(string &args);

    void
    command(Memory &memory) override;
};

class Multiply : public Operation {
public:
    explicit Multiply(string &args);

    void
    command(Memory &memory) override;
};

class Division : public Operation {
public:
    explicit Division(string &args);

    void
    command(Memory &memory) override;
};

class Print : public Operation {
public:
    explicit Print(string &args);

    void
    command(Memory &memory) override;
};

class Read : public Operation {
public:
    explicit Read(string &args);

    void command(Memory &memory) override;
};

class Comment : public Operation {
public:
    explicit Comment(string &args);

    void command(Memory &memory) override;
};

#endif //CPP_LABS_OPERATIONS_H
