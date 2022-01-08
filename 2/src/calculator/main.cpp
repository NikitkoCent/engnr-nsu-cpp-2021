#include "../commands/StackCalc.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include "../../libs/SafeInt/SafeInt.hpp"
#include <stdexcept>

using namespace std;

int main(int argc, char *argv[]) {
    try {
        string filepath;
        string help = "Usage:\n./Calculator <filepath> or ./Calculator\n"
                           "Commands:\n#, POP, PUSH <number>, PUSH <varname>, PEEK <varname>, ABS, PLUS, MINUS, MUL, DIV, PRINT, READ.";
        bool flag = false;

        if (argc > 1) {
            if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "-help") == 0) {
                cout << help << endl;
                return 0;
            }
            if (argc == 2) {
                filepath = argv[1];
            } else {
                cerr << "Wrong usage" << help << endl;
                return 1;
            }
        } else {
            flag = true;
        }

        if (flag) {
            OneCommandRead();
        } else {
            ifstream file;
            file.open(filepath);
            if (!file.is_open()) {
                cerr << "FileNotFoundError" << help << endl;
                return 1;
            } else if (file.peek() == EOF) {
                return 0;
            }
            ReadFromStream(file);
        }
    }  catch (const StackException &e) {
        cerr << e.what() << endl;
        return 1;
    }  catch (SafeIntException &e) {
        return 1;
    }  catch (runtime_error &e) {
        cerr << e.what() << endl;
        return 1;
    }
    return 0;
}

