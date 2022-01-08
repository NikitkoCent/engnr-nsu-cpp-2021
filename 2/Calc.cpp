//
// Created by nedobitaia on 03.01.2022.
//

#include "Calc.h"
#include <stack>
#include <sstream>
#include <map>
#include <iostream>
#include <cstdint>
#include <cstring>
#include <vector>
#include <iterator>
#include <string>
#include <fstream>
#include <istream>

bool is_number(std::string &line) {
    char *p;
    strtol(line.c_str(), &p, 10);
    return *p == 0;
}

void Comment::ct(type &tp, std::vector<std::string> str) {}

void Pop::ct(type &tp, std::vector<std::string> str){
    if (!tp.stack_.empty())
        tp.stack_.pop();
    else{
        throw PopException(); //e.s.
    }
}

void Push::ct(type &tp, std::vector<std::string> str) {
    if (str.size()<2) {
        throw VarnameException();
    }
    try {
        std::string varname = str[1];
        if (is_number(varname)) {
            tp.stack_.push(std::stoll(varname));
        } else {
            auto it = tp.mp.find(varname);
            if (it == tp.mp.end()) {
                throw PushException();
            }
            tp.stack_.push(it->second);
        }
    }
    catch(std::out_of_range){
        throw SIException();
    }
}

void Peek::ct(type &tp, std::vector<std::string> str) {
    if (tp.stack_.empty()) {
        throw PeekException(); //e.s.
    }
    if(str.size() < 2)
        throw PeekException(); //e.s.
    tp.mp[str[1]] = tp.stack_.top();
}

void Abs::ct(type &tp, std::vector<std::string> str) {
    if (tp.stack_.empty()) {
        throw AbsException(); //e.s.
    }
    try{
        SafeInt<int64_t> value = tp.stack_.top();
        tp.stack_.pop();
        if(value < 0) {value = (-1)*value;}
        tp.stack_.push(value);
    }
    catch(...){
        throw SIException();
    }
}

void Plus::ct(type &tp, std::vector<std::string> str) {
    if (tp.stack_.size() < 2) {
        throw PlusException(); //s.e.
    }
    int64_t fe = tp.stack_.top();
    tp.stack_.pop();
    int64_t se = tp.stack_.top();
    tp.stack_.pop();
    int64_t sum;
    //SafeAdd(se, fe, sum);
    if(SafeAdd(se, fe, sum) == 0){
        throw SIException();
    }

    tp.stack_.push(sum);
}

void Minus::ct(type &tp, std::vector<std::string> str){
    if (tp.stack_.size() < 2) {
        throw MinusException(); //s.e.
    }
    int64_t fe = tp.stack_.top();
    tp.stack_.pop();
    int64_t se = tp.stack_.top();
    tp.stack_.pop();
    int64_t razn;
    //SafeSubtract(se, fe, razn);
    if(SafeSubtract(se, fe, razn) == 0){
        throw SIException();
    }
    tp.stack_.push(razn);
}

void Mul::ct(type &tp, std::vector<std::string> str){
    if (tp.stack_.size() < 2) {
        throw MulException();//s.e.
    }
    int64_t fe = tp.stack_.top();
    tp.stack_.pop();
    int64_t se = tp.stack_.top();
    tp.stack_.pop();
    int64_t mull;
    //SafeMultiply(se, fe, mull);
    if(SafeMultiply(se, fe, mull) == 0){
        throw SIException();
    }
    tp.stack_.push(mull);
}

void Div::ct(type &tp, std::vector<std::string> str){
    if (tp.stack_.size() < 2) {
        throw EmptyDivException();
    }
    int64_t fe = tp.stack_.top();
    tp.stack_.pop();
    int64_t se = tp.stack_.top();
    tp.stack_.pop();
    if (fe == 0) {
        throw ZeroException();
    }
    int64_t divv;
    //SafeDivide(se, fe, divv);
    if(SafeDivide(se, fe, divv) == 0){
        throw SIException();
    }
    tp.stack_.push(divv);
}


void Print::ct(type &tp, std::vector<std::string> str){
    if (tp.stack_.empty()) {
        throw PrintException(); //s.e.
    }
    std::cout << std::to_string((int64_t) tp.stack_.top()) << std::endl;
}

void Read::ct(type &tp, std::vector<std::string> str){
    std::string varname = str[1];
    tp.stack_.push(std::stoll(varname));
}



void countingg(std::istream &is) {
    Create_Command creator;
    type tp;
    std::vector<std::string> words;
    std::string word, stroka;
    Commands *command;

    while (getline(is, stroka, '\n')) {
        if (stroka.empty()) continue;
        std::stringstream st(stroka);
        while (getline(st, word, ' ')) {
            words.push_back(word);
        }
        command = creator.factoryMethod(words);
        command->ct(tp, words);
        words.clear();
        delete command;
    }

}

void counting(std::stringstream &in, std::ifstream &file, int args){
    if(args == 1){ countingg(std::cin);}
    if(args == 2){ countingg(file);}
    if(args == 3){ countingg(in);}

}



Commands *Create_Command::factoryMethod(std::vector<std::string> &commands) {
    std::string word = commands[0];
    if (word == "#") {
        return new Comment();
    }
    else if (word == "PRINT"){
        return new Print();
    }
    else if (word == "PLUS") {
        return new Plus();
    }
    else if (word == "DIV") {
        return new Div();
    }
    else if (word == "MINUS") {
        return new Minus();
    }
    else if (word == "MUL") {
        return new Mul();
    }
    else if (word == "READ") {
        return new Read();
    }
    else if (word == "PUSH") {
        return new Push();
    }
    else if (word == "PEEK") {
        return new Peek();
    }
    else if (word == "ABS") {
        return new Abs();
    }
    else if (word == "POP") {
        return new Pop();
    }
    else {
        throw CommandException();
    }
}



