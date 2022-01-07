#include <iostream>
#include <fstream>
#include "src/Command.h"

using namespace std;

unique_ptr<Command> get_command_by_string(string &cur_string, Context &context) {
    unique_ptr<Command> operation;
    if (cur_string.empty()) {
        operation = nullptr;
    } else if (cur_string == "POP") {
        operation = unique_ptr<Command>(new Pop(context));
    } else if (cur_string == "PUSH") {
        operation = unique_ptr<Command>(new Push(context));
    } else if (cur_string == "PEEK") {
        operation = unique_ptr<Command>(new Peek(context));
    } else if (cur_string == "ABS") {
        operation = unique_ptr<Command>(new Abs(context));
    } else if (cur_string == "PLUS") {
        operation = unique_ptr<Command>(new Plus(context));
    } else if (cur_string == "MINUS") {
        operation = unique_ptr<Command>(new Minus(context));
    } else if (cur_string == "MUL") {
        operation = unique_ptr<Command>(new Mul(context));
    } else if (cur_string == "DIV") {
        operation = unique_ptr<Command>(new Div(context));
    } else if (cur_string == "PRINT") {
        operation = unique_ptr<Command>(new Print(context));
    } else if (cur_string == "READ") {
        operation = unique_ptr<Command>(new Read(context));
    } else {
        if (cur_string != "#") {
            throw runtime_error("Unknown command: " + cur_string);
        } else {
            operation = unique_ptr<Command>(new Comment(context));
        }
    }
    return operation;
}


void parse_stream(istream &stream, Context &context) {
    while (!stream.eof()) {
        string strCommand;
        stream >> strCommand;
        shared_ptr<Command> command = get_command_by_string(strCommand, context);
        if (auto argsCommand = dynamic_pointer_cast<ArgsCommand> (command)){
            string args;
            getline(stream, args);
            argsCommand->eval(args);
        } else if (auto nonArgsCommand = dynamic_pointer_cast<NonArgsCommand> (command)){
            nonArgsCommand->eval();
        }

    }
}

int main(int argc, char **argv) {

    if (argc > 2){
        cerr << "HELP";
        return 1;
    }

    if (argc == 2){
        string filename = argv[1];
        ifstream file(filename);
        if (file.is_open())
        {
            Context a;
            parse_stream(file, a);
        }else
        {
            return 1;
        }
    }
    Context a;
    parse_stream(cin, a);
    return 0;
}

