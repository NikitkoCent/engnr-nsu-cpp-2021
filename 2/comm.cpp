//
// Created by Ростислав on 03.01.2022.
//

#include "comm.h"
#include <iostream>
#include <fstream>



bool is_number(const std::string &s) {
    return !s.empty() && (std::all_of(s.begin(), s.end(), [](char c) { return ::isdigit(c); }) ||
                          (s[0] == '-' && std::all_of(s.begin() + 1, s.end(), [](char c) { return ::isdigit(c); })));
}

void Pop::act(ContextExecution &context, std::vector<std::string> &str) {
    if (!context.vals.empty()) {
        context.vals.pop();
    } else
        throw PopException();
}



void Push::act(ContextExecution &context, std::vector<std::string> &str) {
    try {
        if (str.size() < 2) {
            throw PushException();
        }
        if (is_number(str[1])) {
            context.vals.push(std::stoll(str[1]));
        } else {
            context.vals.push(context.vars[str[1]]);  //add exception(?)
        }
    } catch (std::out_of_range){
        throw PushException();
    }

}

void Peek::act(ContextExecution &context, std::vector<std::string> &str) {
    if (context.vals.empty() || str.size() < 2) {
        throw PeekException();
    } else
        context.vars[str[1]] = context.vals.top();
}

void Abs::act(ContextExecution &context, std::vector<std::string> &) {
    if (context.vals.empty()) {
        throw AbsException();
    } else {
        int64_t a = context.vals.top();
        if (a < 0) {
            SafeMultiply(a,-1,a);
            if (!SafeMultiply(a,-1,a)){throw OverException();}
        }
        context.vals.pop();
        context.vals.push(a);
    }
}

void Plus::act(ContextExecution &context, std::vector<std::string> &str) {
    if (context.vals.size()<2) {
        throw PlusException();
    } else {
        int64_t a = context.vals.top();
        context.vals.pop();
        int64_t b = context.vals.top();
        int64_t res;
        SafeAdd(a,b,res);
        if (!SafeAdd(a,b,res)){throw OverException();}
        context.vals.pop();
        context.vals.push(res);
    }
}


void Minus::act(ContextExecution &context, std::vector<std::string> &str) {
    if (context.vals.size()<2) {
        throw MinusException();
    } else {
        int64_t a = context.vals.top();
        context.vals.pop();
        int64_t b = context.vals.top();
        int64_t res;
        SafeSubtract(b,a,res);
        if (!SafeSubtract(b,a,res)){throw OverException();}
        context.vals.pop();
        context.vals.push(res);
    }
}

void Div::act(ContextExecution &context, std::vector<std::string> &str) {
    if (context.vals.size()<2) {
        throw DivException();
    } else {
        int64_t a = context.vals.top();
        context.vals.pop();
        if (a==0) {throw ZeroException();}
        int64_t b = context.vals.top();
        int64_t res ;
        SafeDivide(b,a,res);
        if (!SafeDivide(b,a,res)) { throw OverException();}
        context.vals.pop();
        context.vals.push(res);
    }
}

void Mul::act(ContextExecution &context, std::vector<std::string> &str) {
    if (context.vals.size()<2) {
        throw MulException();
    } else {
        int64_t a = context.vals.top();
        context.vals.pop();
        int64_t b = context.vals.top();
        int64_t res;
        SafeMultiply(a,b,res);
        if(!SafeMultiply(a,b,res)) {throw OverException();}
        context.vals.pop();
        context.vals.push(res);
    }
}

void Print::act(ContextExecution &context, std::vector<std::string> &str) {
    if (context.vals.empty()){
        throw PrintException();
    } else{
        std::cout<<(int64_t)context.vals.top() << std::endl;
    }
}


void Read::act(ContextExecution &context, std::vector<std::string> &str) {
    if (str.size()<2) {
        throw ReadException();
    }
    if (!is_number(str[1])) {
        throw ReadException();
    }
    context.vals.push(std::stoll(str[1]));
}

void Comment::act(ContextExecution &context, std::vector<std::string> &str) {

}



Comm *Obrer::obr(std::vector<std::string> &commands) {
    if (commands[0] == "#") {return new Comment();}
    if (commands[0] == "POP") {return new Pop();}
    if (commands[0] == "PUSH") {return new Push();}
    if (commands[0] == "PEEK") {return new Peek();}
    if (commands[0] == "ABS") {return new Abs();}
    if (commands[0] == "PLUS") {return new Plus();}
    if (commands[0] == "MINUS") {return new Minus();}
    if (commands[0] == "DIV") {return new Div();}
    if (commands[0] == "MUL") {return new Mul();}
    if (commands[0] == "PRINT") {return new Print();}
    if (commands[0] == "READ") {return new Read();}
    else {throw NoCommandException() ;}

}

void pre (std::istream &sr) {
    std::string command_line;
    std::vector<std::string> ph;
    Comm *calc_command;
    Obrer proccessor;
    ContextExecution data;
    while (getline(sr, command_line)) {
        if (command_line.empty()) {
            continue;
        }
        std::stringstream str_new(command_line);
        std::vector<std::string> command; //empty lines(?)
        std::stringstream str(command_line);
        std::string com;
        while (getline(str, com, ' ')) {
            ph.push_back(com);
        }
        calc_command = proccessor.obr(ph);
        calc_command->act(data, ph);
        ph.clear();
        delete calc_command;


    }
}

    void procces(std::stringstream &test_s, std::ifstream &ty, int kind) {


        if (kind == 1) {
            pre(std::cin);
        }
        if (kind == 2) {
            pre(ty);
        }
        if (kind == 3) {
            pre(test_s);
        }
    }














