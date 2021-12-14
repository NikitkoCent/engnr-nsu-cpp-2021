#include "StackCalc.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>


void CustomException::SafeIntOnOverflow(){
    std::cerr << "Caught a SafeInt Overflow exception!" << std::endl;
}

Pop::Pop(std::string &args) : Command(args) {}
void Pop::command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) {
    if(!stack.empty()){
        stack.pop();
    }else{
        std::cerr << "Stack is empty. POP operation failed." << std::endl;
        throw;
    }
}

Push::Push(std::string &args) : Command(args) {}
void Push::command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) {
    try{
        int val = std::stoi(params);
        stack.push(val);
    }catch(const std::invalid_argument&){
        if(variables.find(params) == variables.end()){
            std::cerr << "Variable doesn't exist. PUSH operation failed." << std::endl;
            throw;
        }else{
            stack.push(variables[params]);
        }
    }
}

Peek::Peek(std::string &args) : Command(args) {}
void Peek::command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) {
    if(!stack.empty()) {
        variables[params] = stack.top();
    }else{
        std::cerr << "Stack is empty. PEEK operation failed." << std::endl;
        throw;
    }
}

Abs::Abs(std::string &args) : Command(args) {}
void Abs::command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) {
    if(!stack.empty()) {
        int val = stack.top();
        stack.pop();
        stack.push(abs(val));
    }else{
        std::cerr << "Stack is empty. ABS operation failed." << std::endl;
        throw;
    }
}

Plus::Plus(std::string &args) : Command(args) {}
void Plus::command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) {
    if(stack.size() >= 2){
        int val1 = stack.top();
        stack.pop();
        int val2 = stack.top();
        stack.pop();
        stack.push(val1 + val2);
    }else{
        std::cerr << "Less than 2 elements in stack. PLUS operation failed." << std::endl;
        throw;
    }
}

Minus::Minus(std::string &args) : Command(args) {}
void Minus::command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) {
    if(stack.size() >= 2) {
        int val1 = stack.top();
        stack.pop();
        int val2 = stack.top();
        stack.pop();
        stack.push(val2 - val1);
    }else{
        std::cerr << "Less than 2 elements in stack. MINUS operation failed." << std::endl;
        throw;
    }
}

Multiply::Multiply(std::string &args) : Command(args) {}
void Multiply::command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) {
    if(stack.size() >= 2) {
        int val1 = stack.top();
        stack.pop();
        int val2 = stack.top();
        stack.pop();
        stack.push(val2 * val1);
    }else{
        std::cerr << "Less than 2 elements in stack. MUL operation failed." << std::endl;
        throw;
    }
}

Division::Division(std::string &args) : Command(args) {}
void Division::command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) {
    if(stack.size() >= 2) {
        int val1 = stack.top();
        stack.pop();
        int val2 = stack.top();
        stack.pop();
        stack.push(val2 / val1);
    }else{
        std::cerr << "Less than 2 elements in stack. DIV operation failed." << std::endl;
        throw;
    }
}

Print::Print(std::string &args) : Command(args) {}
void Print::command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) {
    if(!stack.empty()) {
        int val = stack.top();
        variables["result"] = val;
        std::cout << val << std::endl;
    }else{
        std::cerr << "Stack is empty. POP operation failed." << std::endl;
        throw;
    }
}

Read::Read(std::string &args) : Command(args) {}
void Read::command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) {
    try {
        std::string val;
        std::cin >> val;
        stack.push(std::stoi(val));
    }catch(const std::invalid_argument&){
        std::cerr << "READ operation failed." << std::endl;
        throw;
    }
}

Comment::Comment(std::string &args) : Command(args) {}
void Comment::command(std::stack<SafeInt<int64_t, CustomException>> &stack, std::map<std::string, SafeInt<int64_t, CustomException>> &variables) {}

void StackCalc::command(Command *cmd) {
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
    std::string command_line;
    while (!command_line.empty()) {
        getline(std::cin, command_line);
        Command *cmd = calculator.read_command(command_line);
        try{
            calculator.command(cmd);
        }catch(std::exception &e){
            std::cerr << e.what() <<std::endl;
            delete cmd;
        }
        delete cmd;
    }
    return calculator;
}


StackCalc ReadFromStream(std::istream &file){
    StackCalc calculator;
    std::string command_line;
    while (!file.eof()) {
        std::getline(file, command_line);
        Command *cmd = calculator.read_command(command_line);
        if(cmd == nullptr){
            continue;
        }
        try{
            calculator.command(cmd);
        }catch(std::exception &e){
            std::cerr << e.what() <<std::endl;
            delete cmd;
        }
        delete cmd;
    }
    return calculator;
}