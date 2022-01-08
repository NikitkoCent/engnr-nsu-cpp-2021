#include "StackCalc.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <memory>
#include <charconv>
#include <algorithm>

using namespace std;

Pop::Pop(string &args) : Command(args) {}

void Pop::command(ContextExecution &context_execution) {
    if (!context_execution.stack.empty()) {
        context_execution.stack.pop();
    } else {
        throw PopException();
    }
}

bool is_number(const string &s) {
    return !s.empty() && (all_of(s.begin(), s.end(), [](char c) { return ::isdigit(c); }) ||
                          (s[0] == '-' && all_of(s.begin() + 1, s.end(), [](char c) { return ::isdigit(c); })));
}


Push::Push(string &args) : Command(args) {}

void Push::command(ContextExecution &context_execution) {
    if (is_number(params)) {
        int64_t result{};
        auto[ptr, ec]{from_chars(params.data(), params.data() + params.size(), result)};
        if (ec == errc::result_out_of_range) {
            throw OverflowException();
        }
        context_execution.stack.push(result);
    } else {
        auto elem = context_execution.variables.find(params);
        if (elem == context_execution.variables.end()) {
            throw PushException();
        } else context_execution.stack.push(elem->second);
    }
}


Peek::Peek(string &args) : Command(args) {}

void Peek::command(ContextExecution &context_execution) {
    if (!context_execution.stack.empty()) {
        context_execution.variables[params] = context_execution.stack.top();
    } else {
        throw PeekException();
    }
}


Abs::Abs(string &args) : Command(args) {}

void Abs::command(ContextExecution &context_execution) {
    if (!context_execution.stack.empty()) {
        SafeInt<int64_t, CustomException> val = context_execution.stack.top();
        context_execution.stack.pop();
        if (val < 0) {
            SafeInt<int64_t, CustomException> result = -val;
            context_execution.stack.push(result);
        } else {
            SafeInt<int64_t, CustomException> result = val;
            context_execution.stack.push(result);
        }
    } else {
        throw AbsException();
    }
}


Plus::Plus(string &args) : Command(args) {}

void Plus::command(ContextExecution &context_execution) {
    if (context_execution.stack.size() >= 2) {
        SafeInt<int64_t, CustomException> val1 = context_execution.stack.top();
        context_execution.stack.pop();
        SafeInt<int64_t, CustomException> val2 = context_execution.stack.top();
        context_execution.stack.pop();
        SafeInt<int64_t, CustomException> result = val1 + val2;
        context_execution.stack.push(result);
    } else {
        throw PlusException();
    }
}

Minus::Minus(string &args) : Command(args) {}

void Minus::command(ContextExecution &context_execution) {
    if (context_execution.stack.size() >= 2) {
        SafeInt<int64_t, CustomException> val1 = context_execution.stack.top();
        context_execution.stack.pop();
        SafeInt<int64_t, CustomException> val2 = context_execution.stack.top();
        context_execution.stack.pop();
        SafeInt<int64_t, CustomException> result = val2 - val1;
        context_execution.stack.push(result);
    } else {
        throw MinusException();
    }
}


Multiply::Multiply(string &args) : Command(args) {}

void Multiply::command(ContextExecution &context_execution) {
    if (context_execution.stack.size() >= 2) {
        SafeInt<int64_t, CustomException> val1 = context_execution.stack.top();
        context_execution.stack.pop();
        SafeInt<int64_t, CustomException> val2 = context_execution.stack.top();
        context_execution.stack.pop();
        SafeInt<int64_t, CustomException> result = val1 * val2;
        context_execution.stack.push(result);
    } else {
        throw MultiplyException();
    }
}


Division::Division(string &args) : Command(args) {}

void Division::command(ContextExecution &context_execution) {
    if (context_execution.stack.size() >= 2) {
        int64_t val1 = context_execution.stack.top();
        context_execution.stack.pop();
        int64_t val2 = context_execution.stack.top();
        if (val1 != 0) {
            context_execution.stack.pop();
            int64_t res;
            SafeDivide(val2, val1, res);
            context_execution.stack.push(res);
        } else {
            throw DivisionByZero();
        }
    } else {
        throw DivisionException();

    }
}


Print::Print(string &args) : Command(args) {}

void Print::command(ContextExecution &context_execution) {
    if (!context_execution.stack.empty()) {
        SafeInt<int64_t, CustomException> val = context_execution.stack.top();
        context_execution.variables["result"] = val;
        cout << (int64_t) val << endl;
    } else {
        throw PrintException();
    }
}


Read::Read(string &args) : Command(args) {}

void Read::command(ContextExecution &context_execution) {
    string val;
    cin >> val;
    if (is_number(val)) {
        int64_t result{};
        from_chars(val.data(), val.data() + val.size(), result);
        context_execution.stack.push(result);
    } else {
        throw ReadException();
    }
}

Comment::Comment(string &args) : Command(args) {}

void Comment::command(ContextExecution &context_execution) {}

void StackCalc::command(unique_ptr<Command> cmd) {
    cmd->command(context_execution);
}

void CustomException::SafeIntOnOverflow() {
    throw OverflowException();
}


Command *StackCalc::read_command(string &command_line) {
    string help = "Usage:\n./Calculator <filepath> or ./Calculator\n"
                       "Commands:\n#, POP, PUSH <number>, PUSH <varname>, PEEK <varname>, ABS, PLUS, MINUS, MUL, DIV, PRINT, READ.";
    string command;
    stringstream x;
    x << command_line;
    x >> command;
    Command *operation;
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


StackCalc OneCommandRead() {
    StackCalc calculator;
    string command_line = "s";
    while (!cin.eof()) {
        getline(cin, command_line);
        if (command_line.empty()) continue;
        unique_ptr<Command> cmd(calculator.read_command(command_line));
        if (cmd == nullptr) {
            continue;
        }
        calculator.command(move(cmd));
    }
    return calculator;
}


StackCalc ReadFromStream(istream &file) {
    StackCalc calculator;
    string command_line;
    while (!file.eof()) {
        getline(file, command_line);
        unique_ptr<Command> cmd(calculator.read_command(command_line));
        if (cmd == nullptr) {
            continue;
        }
        calculator.command(move(cmd));
    }
    return calculator;
}

