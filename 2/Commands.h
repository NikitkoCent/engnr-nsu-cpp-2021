//
// Created by gav on 08/10/2021.
//

#ifndef CPP_LABS_COMMANDS_H
#define CPP_LABS_COMMANDS_H

#include <map>
#include <stack>
#include <string>
#include <iostream>

#include "SafeInt.hpp"
#include "Exceptions.h"

using std::map;
using std::stringstream;
using std::string;
using std::stack;
using std::cout;
using std::cin;
using std::endl;

class Command {
protected:
    stringstream args;
public:
    explicit Command(string &_args) {
        string ass;
        args = stringstream(_args);
        args >> ass; // read cmd name
    }

    virtual void exec(stack<SafeInt<int64_t>> &_stack, map<string, SafeInt<int64_t>> &m) = 0;

    virtual ~Command() {};
};

class Push : public Command {
public:
    explicit Push(string &_args) : Command(_args) {
//        std::cout << "Push ctor: " << _args << std::endl;
    }

    static bool is_number(const std::string &line) {
        char *p;
        strtol(line.c_str(), &p, 10);
        return *p == 0;
    }

    void exec(stack<SafeInt<int64_t>> &_stack, map<string, SafeInt<int64_t>> &m) override {
//        std::cout << "exec!" << std::endl;
        string varname;
        args >> varname;
//        std::cout << "VARMAME: " << varname << std::endl;
        if (is_number(varname)) {
//            cout << "Push " << varname << endl;
            _stack.push(std::stoi(varname));
        } else {
            if (m.count(varname) == 0)
                throw InvalidArgumentsException();
//            cout << "Push m[" << varname << "]=" << (int64_t)m[varname] << endl;
            _stack.push(m[varname]);
        }
    }
};

class Pop : public Command {
public:
    explicit Pop(string &_args) : Command(_args) {}

    void exec(stack<SafeInt<int64_t>> &stack, map<string, SafeInt<int64_t>> &m) override {
//        cout << "Pop " << (int64_t)stack.top() << endl;
        if (stack.empty()) throw StackEmptyException();
        stack.pop();
    }
};

class Peek : public Command {
public:
    explicit Peek(string &_args) : Command(_args) {}

    void exec(stack<SafeInt<int64_t>> &stack, map<string, SafeInt<int64_t>> &m) override {
        string varname;
        args >> varname;
        if (varname.empty())
            throw InvalidArgumentsException();
//        cout << "Peek m[" << varname << "]=" << (int64_t)stack.top() << endl;
        m[varname] = stack.top();
    }
};

class Abs : public Command {
public:
    explicit Abs(string &_args) : Command(_args) {}

    void exec(stack<SafeInt<int64_t>> &stack, map<string, SafeInt<int64_t>> &m) override {
        if (stack.empty()) throw StackEmptyException();

        auto t = stack.top();
//        cout << "Abs " << (int64_t)t << endl;
        stack.pop();
        if (t < 0)
            stack.push(-t);
        else
            stack.push(t);
    }
};

class Plus : public Command {
public:
    explicit Plus(string &_args) : Command(_args) {}

    void exec(stack<SafeInt<int64_t>> &stack, map<string, SafeInt<int64_t>> &m) override {
        if (stack.size() < 2) throw StackEmptyException();

        auto a = stack.top(); stack.pop(); auto b = stack.top(); stack.pop();
//        cout << (int64_t)a << " + " << (int64_t)b << endl;
        stack.push(a + b);
    }
};

class Minus : public Command {
public:
    explicit Minus(string &_args) : Command(_args) {}

    void exec(stack<SafeInt<int64_t>> &stack, map<string, SafeInt<int64_t>> &m) override {
        if (stack.size() < 2) throw StackEmptyException();

        auto a = stack.top(); stack.pop(); auto b = stack.top(); stack.pop();
//        cout << (int64_t)b << " - " << (int64_t)a << endl;
        stack.push(b - a);
    }
};

class Mul : public Command {
public:
    explicit Mul(string &_args) : Command(_args) {}

    void exec(stack<SafeInt<int64_t>> &stack, map<string, SafeInt<int64_t>> &m) override {
        if (stack.size() < 2) throw StackEmptyException();

        auto a = stack.top(); stack.pop(); auto b = stack.top(); stack.pop();
//        cout << (int64_t)a << " * " << (int64_t)b << endl;
        stack.push(a * b);
    }
};

class Div : public Command {
public:
    explicit Div(string &_args) : Command(_args) {}

    void exec(stack<SafeInt<int64_t>> &stack, map<string, SafeInt<int64_t>> &m) override {
        if (stack.size() < 2) throw StackEmptyException();
        auto a = stack.top(); stack.pop(); auto b = stack.top(); stack.pop();
//        cout << (int64_t)b << " / " << (int64_t)a << endl;
        stack.push(b / a);
    }
};

class Print : public Command {
public:
    explicit Print(string &_args) : Command(_args) {}

    void exec(stack<SafeInt<int64_t>> &stack, map<string, SafeInt<int64_t>> &m) override {
        if (stack.empty()) throw StackEmptyException();
        auto a = stack.top();
        std::cout << (int64_t)a << std::endl;
        m["last_print_don_t_use_me_as_variable_name_pleeeeezzzzzzzzz"] = a;
    }
};

class Read : public Command {
public:
    explicit Read(string &_args) : Command(_args) {}

    void exec(stack<SafeInt<int64_t>> &stack, map<string, SafeInt<int64_t>> &m) override {
        int64_t a;
        std::cin >> a;
        stack.push((SafeInt<int64_t>)a);
    }
};



#endif //CPP_LABS_COMMANDS_H
