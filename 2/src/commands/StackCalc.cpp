#include "StackCalc.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

std::string WrongArgument::what() {
    return text + wrong;
}

std::string EmptyStack::what() {
    return text + empty;
}

std::string FewElementError::what() {
    return text + few_elem;
}

void CustomException::SafeIntOnOverflow(){
    std::cerr << "Caught a SafeInt Overflow exception!" << std::endl;
}

std::string PopException::what() {
    return text + empty + pop;
}

Pop::Pop(std::string &args) : Command(args) {}
void Pop::command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) {
    if(!stack.empty()){
        stack.pop();
    }else{
        throw PopException();
    }
}

std::string PushException::what() {
    return text + wrong + push;
}

Push::Push(std::string &args) : Command(args) {}
void Push::command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) {
    try{
        SafeInt<int64_t, CustomException> val = std::stoi(params);
        stack.push((int64_t)val);
    }catch(const std::invalid_argument&){
        if(variables.find(params) == variables.end()){
            throw PushException();
        }else{
            stack.push(variables[params]);
        }
    }
}

std::string PeekException::what() {
    return text + empty + peek;
}

Peek::Peek(std::string &args) : Command(args) {}
void Peek::command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) {
    if(!stack.empty()) {
        variables[params] = stack.top();
    }else{
        throw PeekException();
    }
}

std::string AbsException::what() {
    return text + empty + abs;
}

Abs::Abs(std::string &args) : Command(args) {}
void Abs::command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) {
    if(!stack.empty()) {
        SafeInt<int64_t, CustomException> val = stack.top();
        stack.pop();
        if (val < 0){
            stack.push(-(int64_t)val);
        }else {
            stack.push((int64_t)val);
        }
    }else{
        throw AbsException();
    }
}

std::string PlusException::what() {
    return text + few_elem + plus;
}

Plus::Plus(std::string &args) : Command(args) {}
void Plus::command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) {
    if(stack.size() >= 2){
        SafeInt<int64_t, CustomException> val1 = stack.top();
        stack.pop();
        SafeInt<int64_t, CustomException> val2 = stack.top();
        stack.pop();
        stack.push((int64_t)val1 + (int64_t)val2);
    }else{
        throw PlusException();
    }
}

std::string MinusException::what() {
    return text + few_elem + minus;
}

Minus::Minus(std::string &args) : Command(args) {}
void Minus::command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) {
    if(stack.size() >= 2) {
        SafeInt<int64_t, CustomException> val1 = stack.top();
        stack.pop();
        SafeInt<int64_t, CustomException> val2 = stack.top();
        stack.pop();
        stack.push((int64_t)val2 - (int64_t)val1);
    }else{
        throw MinusException();
    }
}

std::string MultiplyException::what() {
    return text + few_elem + mul;
}

Multiply::Multiply(std::string &args) : Command(args) {}
void Multiply::command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) {
    if(stack.size() >= 2) {
        SafeInt<int64_t, CustomException> val1 = stack.top();
        stack.pop();
        SafeInt<int64_t, CustomException> val2 = stack.top();
        stack.pop();
        stack.push((int64_t)val2 * (int64_t)val1);
    }else{
        throw MultiplyException();
    }
}

std::string DivisionException::what() {
    return text + few_elem + div;
}

Division::Division(std::string &args) : Command(args) {}
void Division::command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) {
    if(stack.size() >= 2) {
        SafeInt<int64_t, CustomException> val1 = stack.top();
        stack.pop();
        SafeInt<int64_t, CustomException> val2 = stack.top();
        stack.pop();
        stack.push((int64_t)val2 / (int64_t)val1);
    }else{
        throw DivisionException();

    }
}

std::string PrintException::what() {
    return text + empty + print;
}

Print::Print(std::string &args) : Command(args) {}
void Print::command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) {
    if(!stack.empty()) {
        SafeInt<int64_t, CustomException> val = stack.top();
        variables["result"] = val;
        std::cout << (int64_t)val << std::endl;
    }else{
        throw PrintException();
    }
}

std::string ReadException::what() {
    return text + wrong + read;
}

Read::Read(std::string &args) : Command(args) {}
void Read::command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) {
    try {
        std::string val;
        std::cin >> val;
        stack.push(std::stoi(val));
    }catch(const std::invalid_argument&){
        throw ReadException();
    }
}

Comment::Comment(std::string &args) : Command(args) {}
void Comment::command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) {}

void StackCalc::command(std::unique_ptr<Command> cmd) {
    cmd->command(stack, variables);
}

Command *StackCalc::read_command(std::string &command_line) {
    std::string help = "Usage: ./Calculator <filepath> or ./Calculator"
                       "Commands: #, POP, PUSH <number>, PUSH <varname>, PEEK <varname>, ABS, PLUS, MINUS, MUL, DIV, PRINT, READ.";
    std::string command;
    std::stringstream x;
    x << command_line;
    x >> command;
    Command *operation;
    if(command.empty()){
        return nullptr;
    }else if(command == "POP") {
        operation = new Pop(command);
    }else if(command == "PUSH") {
        x >> command;
        operation = new Push(command);
    }else if(command == "PEEK"){
        x >> command;
        operation = new Peek(command);
    }else if(command == "ABS"){
        operation = new Abs(command);
    }else if(command == "PLUS"){
        operation = new Plus(command);
    }else if(command == "MINUS"){
        operation = new Minus(command);
    }else if(command == "MUL"){
        operation = new Multiply(command);
    }else if(command == "DIV"){
        operation = new Division(command);
    }else if(command == "PRINT"){
        operation = new Print(command);
    }else if(command == "READ"){
        operation = new Read(command);
    }else{
        if(command != "#"){
            std::cerr << "Unknown command:" << command << help << std::endl;
            throw;
        }else{
            operation = new Comment(command);
        }
    }
    return operation;
}


StackCalc OneCommandRead(){
    StackCalc calculator;
    std::string command_line = "s";
    while (!std::cin.eof()) {
        getline(std::cin, command_line);
        if (command_line.empty()) continue;
        try{
            std::unique_ptr<Command> cmd(calculator.read_command(command_line));
            if(cmd == nullptr){
                continue;
            }
            calculator.command(std::move(cmd));
        }catch(StackException &e){
            std::cerr << e.what() <<std::endl;
            throw &e;
        }
    }
    return calculator;
}


StackCalc ReadFromStream(std::istream &file){
    StackCalc calculator;
    std::string command_line;
    while (!file.eof()) {
        std::getline(file, command_line);
        try{
            std::unique_ptr<Command> cmd(calculator.read_command(command_line));
            if(cmd == nullptr){
                continue;
            }
            calculator.command(std::move(cmd));
        }catch(StackException &e){
            std::cerr << e.what() <<std::endl;
            throw &e;
        }
    }
    return calculator;
}