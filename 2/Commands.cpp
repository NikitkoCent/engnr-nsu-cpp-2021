//
// Created by Дарья on 06.01.2022.
//

#include "Commands.h"
#include <string>
#include <iostream>
#include <memory>
#include <charconv>
#include <algorithm>

void StackCalc::command(std::unique_ptr<Operation> cmd) {
    cmd->command(memory);
}

Operation *StackCalc::read_command(std::string &command_line) {
    std::string command;
    std::stringstream x;
    x << command_line;
    x >> command;
    Operation *operation;
    if (command.empty()) {
        return nullptr;
    } else if (command == "POP") {
        operation = new Pop(command);
    } else if (command == "PUSH") {
        x >> command;
        operation = new Push(command);
    } else if (command == "PEEK") {
        x >> command;
        operation = new Peek(command);
    } else if (command == "ABS") {
        operation = new Abs(command);
    } else if (command == "PLUS") {
        operation = new Plus(command);
    } else if (command == "MINUS") {
        operation = new Minus(command);
    } else if (command == "MUL") {
        operation = new Multiply(command);
    } else if (command == "DIV") {
        operation = new Division(command);
    } else if (command == "PRINT") {
        operation = new Print(command);
    } else if (command == "READ") {
        operation = new Read(command);
    } else {
        if (command != "#") {
            throw UnknownCommand("Unknown command: " + command);
        } else {
            operation = new Comment(command);
        }
    }
    return operation;
}

StackCalc ReadLine(std::istream &cin1) {
try {
    StackCalc calculator;
    std::string command_line = "1";
    while (!cin1.eof()) {
        getline(cin1, command_line);
        if (command_line.empty()) continue;

        std::unique_ptr<Operation> cmd(calculator.read_command(command_line));
        if (cmd == nullptr) {
            continue;
        }
        calculator.command(std::move(cmd));
    }
    return calculator;
    } catch(StackException &e){
        std::cerr << e.what() << std::endl;
        throw &e;
    }

}

StackCalc ReadFromFile(std::istream &file) {
    StackCalc calculator;
    std::string command_line;
    while (!file.eof()) {
        std::getline(file, command_line);

        std::unique_ptr<Operation> cmd(calculator.read_command(command_line));
        if (cmd == nullptr) {
            continue;
        }
        calculator.command(std::move(cmd));

    }
    return calculator;
}
bool is_number(const std::string &s) {
    return !s.empty() && (std::all_of(s.begin(), s.end(), [](char c) { return ::isdigit(c); }) ||
                          (s[0] == '-' && std::all_of(s.begin() + 1, s.end(), [](char c) { return ::isdigit(c); })));
}