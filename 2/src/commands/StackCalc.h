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
#include <memory>

class StackException {
public:
    std::string text;
    StackException(): text("StackException, ") {
    };
    virtual std::string what() = 0;
};

class WrongArgument: public StackException{
public:
    std::string wrong;
    WrongArgument(): wrong("Wrong argument ") {
    };
    virtual std::string what() override;
};

class EmptyStack: public StackException {
public:
    std::string empty;
    EmptyStack(): empty("Empty stack error: " ) {
    };
    virtual std::string what() override;
};

class FewElementError: public StackException {
public:
    std::string few_elem;
    FewElementError(): few_elem("Too few elements in stack for operation:" ) {
    };
    virtual std::string what() override;
};
//class OperationException final: public StackException{
//public:
//    OperationException(): StackException(){
//        text = "Operation failed.";
//    }
//    explicit OperationException(std::string _text): StackException(std::move(_text)){
//    }
//    std::string what() override {
//        return text;
//    }
//};

class CustomException: public SafeIntException{
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

class PopException: public EmptyStack {
public:
    std::string pop;
    PopException(): pop("POP operation failed." ) {
    };
    virtual std::string what() override;
};

class Pop: public Command {
public:
    explicit Pop(std::string &args);
    void command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) override;

};

class PushException: public WrongArgument{
public:
    std::string push;
    explicit PushException(): push("Variable doesn't exist. PUSH operation failed.") {
    };
    virtual std::string what() override;
};

class Push: public Command {
public:
    explicit Push(std::string &args);
    void command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) override;
};

class PeekException: public EmptyStack{
public:
    std::string peek;
    explicit PeekException(): peek("PEEK operation failed.") {
    };
    virtual std::string what() override;
};

class Peek: public Command {
public:
    explicit Peek(std::string &args);
    void command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) override;
};

class AbsException: public EmptyStack{
public:
    std::string abs;
    explicit AbsException(): abs("ABS operation failed.") {
    };
    virtual std::string what() override;
};

class Abs: public Command {
public:
    explicit Abs(std::string &args);
    void command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) override;
};

class PlusException: public FewElementError{
public:
    std::string plus;
    explicit PlusException(): plus("PLUS operation failed.") {
    };
    virtual std::string what() override;
};

class Plus: public Command {
public:
    explicit Plus(std::string &args);
    void command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) override;
};

class MinusException: public FewElementError{
public:
    std::string minus;
    explicit MinusException(): minus("MINUS operation failed.") {
    };
    virtual std::string what() override;
};

class Minus: public Command {
public:
    explicit Minus(std::string &args);
    void command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) override;
};

class MultiplyException: public FewElementError{
public:
    std::string mul;
    explicit MultiplyException(): mul("MUL operation failed.") {
    };
    virtual std::string what() override;
};

class Multiply: public Command {
public:
    explicit Multiply(std::string &args);
    void command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) override;
};

class DivisionException: public FewElementError{
public:
    std::string div;
    explicit DivisionException(): div("DIV operation failed.") {
    };
    virtual std::string what() override;
};

class Division: public Command {
public:
    explicit Division(std::string &args);
    void command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) override;
};

class PrintException: public EmptyStack{
public:
    std::string print;
    explicit PrintException(): print("PRINT operation failed.") {
    };
    virtual std::string what() override;
};

class Print: public Command {
public:
    explicit Print(std::string &args);
    void command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) override;
};

class ReadException: public WrongArgument{
public:
    std::string read;
    explicit ReadException(): read("READ operation failed.") {
    };
    virtual std::string what() override;
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
    void command(std::unique_ptr<Command> cmd);
    Command* read_command(std::string &command_line);
    std::map<std::string, SafeInt<int64_t, CustomException>> FindResult(){
        return variables;
    }
};

StackCalc ReadFromStream(std::istream &str);
StackCalc OneCommandRead();
#endif