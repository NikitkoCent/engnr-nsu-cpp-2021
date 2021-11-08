//
// Created by gav on 08/10/2021.
//

#ifndef CPP_LABS_COMMANDS_H
#define CPP_LABS_COMMANDS_H

#include <map>
#include <stack>
#include <string>

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
    Command(string &_args) {
        string ass;
        args = stringstream(_args);
        args >> ass; // read cmd name
    }

    virtual void exec(stack<SafeInt<int64_t>> &stack, map<string, SafeInt<int64_t>> &m) = 0;

    ~Command() {}
};

class Push : public Command {
public:
    Push(string &_args) : Command(_args) {
//        std::cout << "Push ctor: " << _args << std::endl;
    }

    bool is_number(const std::string &line) {
        char *p;
        strtol(line.c_str(), &p, 10);
        return *p == 0;
    }

    void exec(stack<SafeInt<int64_t>> &stack, map<string, SafeInt<int64_t>> &m) override {
//        std::cout << "exec!" << std::endl;
        string varname;
        int64_t num;
        args >> varname;
//        std::cout << "VARMAME: " << varname << std::endl;
        if (is_number(varname)) {
//            cout << "Push " << varname << endl;
            stack.push(std::stoi(varname));
        } else {
            if (m.count(varname) == 0)
                throw std::invalid_argument("Can't push by varname to stack: no such key in container!");
//            cout << "Push m[" << varname << "]=" << (int64_t)m[varname] << endl;
            stack.push(m[varname]);
        }
    }
};

class Pop : public Command {
public:
    Pop(string &_args) : Command(_args) {}

    void exec(stack<SafeInt<int64_t>> &stack, map<string, SafeInt<int64_t>> &m) override {
//        cout << "Pop " << (int64_t)stack.top() << endl;
        stack.pop();
    }
};

class Peek : public Command {
public:
    Peek(string &_args) : Command(_args) {}

    void exec(stack<SafeInt<int64_t>> &stack, map<string, SafeInt<int64_t>> &m) override {
        string varname;
        args >> varname;
        if (varname.empty())
            throw std::invalid_argument("Can't PEEK: empty key!");
//        cout << "Peek m[" << varname << "]=" << (int64_t)stack.top() << endl;
        m[varname] = stack.top();
    }
};

class Abs : public Command {
public:
    Abs(string &_args) : Command(_args) {}

    void exec(stack<SafeInt<int64_t>> &stack, map<string, SafeInt<int64_t>> &m) override {
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
    Plus(string &_args) : Command(_args) {}

    void exec(stack<SafeInt<int64_t>> &stack, map<string, SafeInt<int64_t>> &m) override {
        auto a = stack.top(); stack.pop(); auto b = stack.top(); stack.pop();
//        cout << (int64_t)a << " + " << (int64_t)b << endl;
        stack.push(a + b);
    }
};

class Minus : public Command {
public:
    Minus(string &_args) : Command(_args) {}

    void exec(stack<SafeInt<int64_t>> &stack, map<string, SafeInt<int64_t>> &m) override {
        auto a = stack.top(); stack.pop(); auto b = stack.top(); stack.pop();
//        cout << (int64_t)b << " - " << (int64_t)a << endl;
        stack.push(b - a);
    }
};

class Mul : public Command {
public:
    Mul(string &_args) : Command(_args) {}

    void exec(stack<SafeInt<int64_t>> &stack, map<string, SafeInt<int64_t>> &m) override {
        auto a = stack.top(); stack.pop(); auto b = stack.top(); stack.pop();
//        cout << (int64_t)a << " * " << (int64_t)b << endl;
        stack.push(a * b);
    }
};

class Div : public Command {
public:
    Div(string &_args) : Command(_args) {}

    void exec(stack<SafeInt<int64_t>> &stack, map<string, SafeInt<int64_t>> &m) override {
        auto a = stack.top(); stack.pop(); auto b = stack.top(); stack.pop();
//        cout << (int64_t)b << " / " << (int64_t)a << endl;
        stack.push(b / a);
    }
};

class Print : public Command {
public:
    Print(string &_args) : Command(_args) {}

    void exec(stack<SafeInt<int64_t>> &stack, map<string, SafeInt<int64_t>> &m) override {
        auto a = stack.top(); stack.pop();
        std::cout << (int64_t)a << std::endl;
        m["last_print_don_t_use_me_as_variable_name_pleeeeezzzzzzzzz"] = a;
    }
};

class Read : public Command {
public:
    Read(string &_args) : Command(_args) {}

    void exec(stack<SafeInt<int64_t>> &stack, map<string, SafeInt<int64_t>> &m) override {
        int64_t a;
        std::cin >> a;
        stack.push((SafeInt<int64_t>)a);
    }
};



#endif //CPP_LABS_COMMANDS_H
