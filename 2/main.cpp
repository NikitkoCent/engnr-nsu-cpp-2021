#include <iostream>
#include <fstream>
#include <memory>
#include "src/Command.h"
#include "src/Exceptions.h"

using namespace std;

shared_ptr<Command> get_command_by_string(string &cur_string, Context &context) {
    shared_ptr<Command> operation;
    if (cur_string.empty()) {
        operation = nullptr;
    } else if (cur_string == "POP") {
        operation = shared_ptr<Command>(new Pop(context));
    } else if (cur_string == "PUSH") {
        operation = shared_ptr<Command>(new Push(context));
    } else if (cur_string == "PEEK") {
        operation = shared_ptr<Command>(new Peek(context));
    } else if (cur_string == "ABS") {
        operation = shared_ptr<Command>(new Abs(context));
    } else if (cur_string == "PLUS") {
        operation = shared_ptr<Command>(new Plus(context));
    } else if (cur_string == "MINUS") {
        operation = shared_ptr<Command>(new Minus(context));
    } else if (cur_string == "MUL") {
        operation = shared_ptr<Command>(new Mul(context));
    } else if (cur_string == "DIV") {
        operation = shared_ptr<Command>(new Div(context));
    } else if (cur_string == "PRINT") {
        operation = shared_ptr<Command>(new Print(context));
    } else if (cur_string == "READ") {
        operation = shared_ptr<Command>(new Read(context));
    } else {
        if (cur_string != "#") {
            throw UnknownArgument("Unknown command: " + cur_string);
        } else {
            operation = shared_ptr<Command>(new Comment(context));
        }
    }
    return operation;
}


void parse_stream(istream &stream) {
    Context context;
    while (!stream.eof()) {
        string strCommand;
        stream >> strCommand;
        shared_ptr<Command> command = get_command_by_string(strCommand, context);
        if (auto argsCommand = dynamic_pointer_cast<ArgsCommand>(command)) {
            string args;
            getline(stream, args);
            argsCommand->eval(args);
        } else if (auto nonArgsCommand = dynamic_pointer_cast<NonArgsCommand>(command)) {
            nonArgsCommand->eval();
        }

    }
}


int main(int argc, char **argv) {
    string help = "Usage: ./Calculator <filepath?>\n"
                  "Available commands: #, POP, PUSH <number>, PUSH <varname>, PEEK <varname>, ABS, PLUS, MINUS, MUL, DIV, PRINT, READ.";
    if (argc > 2) {
        cerr << "HELP";
        return 1;
    }

    if (argc == 2) {
        string filename = argv[1];
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "File not found!" << endl << help;
            return 1;

        }
        try {
            parse_stream(file);
        } catch (const BaseException &e) {
            std::cerr << e.what() << std::endl;
            return 1;
        } catch (SafeIntException &e) {
            return 1;
        } catch (std::runtime_error &e) {
            std::cerr << e.what() << std::endl;
            return 1;
        }

    }

    try {
        parse_stream(cin);
    } catch (const BaseException &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (SafeIntException &e) {
        return 1;
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}

