#ifndef CPP_LAB2_STACKCALC_H
#define CPP_LAB2_STACKCALC_H

#include <string>
#include <stack>
#include <map>
#include <sstream>
#include <cmath>
#include <iostream>
#include <utility>
#include "../../libs/SafeInt/SafeInt.hpp"

class CustomException : public SafeIntException{
public:
    static void SafeIntOnOverflow();
};

class Command {
public:
    explicit Command(std::string &args){ params = args; }
    virtual void command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) = 0;
    virtual ~Command() = default;
protected:
    std::string params;
};

class Pop: public Command {
public:
    explicit Pop(std::string &args);
    void command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) override;

};

class Push: public Command {
public:
    explicit Push(std::string &args);
    void command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) override;
};

class Peek: public Command {
public:
    explicit Peek(std::string &args);
    void command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) override;
};

class Abs: public Command {
public:
    explicit Abs(std::string &args);
    void command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) override;
};

class Plus: public Command {
public:
    explicit Plus(std::string &args);
    void command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) override;
};

class Minus: public Command {
public:
    explicit Minus(std::string &args);
    void command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) override;
};

class Multiply: public Command {
public:
    explicit Multiply(std::string &args);
    void command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) override;
};

class Division: public Command {
public:
    explicit Division(std::string &args);
    void command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) override;
};

class Print: public Command {
public:
    explicit Print(std::string &args);
    void command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) override;
};

class Read: public Command {
public:
    explicit Read(std::string &args);
    void command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) override;
};

class Comment: public Command {
public:
    explicit Comment(std::string &args);
    void command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) override;
};

class StackCalc {
    std::stack<SafeInt<int64_t, CustomException>> stack;
    std::map<std::string, SafeInt<int64_t, CustomException>> variables;
public:
    void command(Command* cmd);
    Command* read_command(std::string &command_line);
    std::map<std::string, SafeInt<int64_t, CustomException>> FindResult(){
        return variables;
    }
};

StackCalc ReadFromStream(std::istream &str);
StackCalc OneCommandRead();
#endif
