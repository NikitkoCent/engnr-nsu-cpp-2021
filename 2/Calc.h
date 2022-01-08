//
// Created by nedobitaia on 03.01.2022.
//

#ifndef UNTITLED18_CALC_H
#define UNTITLED18_CALC_H




#include "SafeInt/SafeInt.hpp"
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <cmath>
#include <iostream>
#include <utility>
#include <memory>

class type{
public:
    std::stack<SafeInt<int64_t>> stack_;
    std::map<std::string, SafeInt<int64_t>> mp;
};

class Commands{
public:
    virtual void ct(type &tp, std::vector<std::string> str) = 0;
    virtual ~Commands() = default;

};

class Comment final : public Commands{
    void ct(type &tp, std::vector<std::string> str) override;
};

class Pop final : public Commands{
    void ct(type &tp, std::vector<std::string> str) override;
};

class Push final : public Commands{
    void ct(type &tp, std::vector<std::string> str) override;
};

class Peek final : public Commands{
    void ct(type &tp, std::vector<std::string> str) override;
};

class Abs final : public Commands{
    void ct(type &tp, std::vector<std::string> str) override;
};

class Plus final : public Commands{
    void ct(type &tp, std::vector<std::string> str) override;
};

class Minus final : public Commands{
    void ct(type &tp, std::vector<std::string> str) override;
};

class Mul final : public Commands{
    void ct(type &tp, std::vector<std::string> str) override;
};

class Div final : public Commands{
    void ct(type &tp, std::vector<std::string> str) override;
};

class Print final : public Commands{
    void ct(type &tp, std::vector<std::string> str) override;
};

class Read final : public Commands{
    void ct(type &tp, std::vector<std::string> str) override;
};

//----------------------errors---------------------------------------------
class StackException:public std::exception{
protected:
    std::string text = "Error! ";
public:
    virtual std::string what() = 0;
};

class EmptyException : public StackException{
public:
    EmptyException() {
        text += " Stack is empty. ";
    }

    std::string what() override {
        return text;
    }
};

class MulException : public EmptyException{
public:
    MulException() : EmptyException()  {
        text += " Mul exception. ";
    }

    std::string what() override {
        return text;
    }
};

class PlusException : public EmptyException{
public:
    PlusException() : EmptyException()  {
        text += " Plus exception. ";
    }

    std::string what() override {
        return text;
    }
};

class MinusException : public EmptyException{
public:
    MinusException() : EmptyException()  {
        text += " Minus exception. ";
    }

    std::string what() override {
        return text;
    }
};

class PrintException : public EmptyException{
public:
    PrintException() : EmptyException()  {
        text += " Print exception. ";
    }

    std::string what() override {
        return text;
    }
};

class AbsException : public EmptyException{
public:
    AbsException() : EmptyException()  {
        text += " Abs exception.";
    }

    std::string what() override {
        return text;
    }
};

class PopException : public EmptyException{
public:
    PopException() : EmptyException()  {
        text += " Pop exception. ";
    }

    std::string what() override {
        return text;
    }
};

class PeekException : public EmptyException{
public:
    PeekException() : EmptyException()  {
        text += " Peek exception. ";
    }

    std::string what() override {
        return text;
    }
};

class PushException : public StackException{
public:
    PushException() {
        text += " Push exception. ";
    }

    std::string what() override {
        return text;
    }
};

class VarnameException : public PushException{
public:
    VarnameException() : PushException()  {
        text += " Varname is empty. ";
    }

    std::string what() override {
        return text;
    }
};

class DivException : public StackException{
public:
    DivException() {
        text += " Div exception. ";
    }

    std::string what() override {
        return text;
    }
};

class EmptyDivException : public DivException{
public:
    EmptyDivException() : DivException()  {
        text += " Stack is empty. ";
    }

    std::string what() override {
        return text;
    }
};

class ZeroException : public DivException{
public:
    ZeroException() : DivException()  {
        text += " Division by zero. ";
    }

    std::string what() override {
        return text;
    }
};

class CommandException : public StackException {
public:
    CommandException() {
        text += " Command exception. ";
    }
    std::string what() {
        return text;
    }
};

class SIException : public StackException {
public:
    SIException() {
        text += " Overflow! ";
    }
    std::string what() {
        return text;
    }
};


//---------------------------------------------------------------------------------------
class Calculator {
public:
    Calculator() = default;
    virtual Commands *factoryMethod(std::vector<std::string> &commands) = 0;

};


class Create_Command : Calculator {
public:
    Commands *factoryMethod(std::vector<std::string> &commands) override;
};

void countingg(std::istream &is);
void counting(std::stringstream &in1, std::ifstream& in2, int args);

bool is_number(std::string &str);


#endif //UNTITLED18_CALC_H
