//
// Created by Дарья on 06.01.2022.
//
#include "Commands.h"
#include <iostream>
#include <string>

using std:: istream;

using std:: string;
using std:: cerr;
using std:: endl;
using std:: ifstream;

int main(int argc, char *argv[]) {
    try {
        string filepath;
        bool flag = true;

        if (argc > 1) {
            flag = false;
            if (argc == 2) {
                filepath = argv[1];
            } else {
                cerr << "Please, enter file path or arithmetic operations" << endl;
                return 1;
            }
        }

        if (flag) {
            ReadLine(std::cin);
        } else {
            ifstream file;
            file.open(filepath);
            if (!file.is_open()) {
                cerr << "FileNotFoundError" << endl;
                return 1;
            } else if (file.peek() == EOF) {
                return 0;
            }

            ReadLine(file);
        }
    }  catch (const StackException &e) {
        cerr << e.what() << endl;
        return 1;
    }  catch (SafeIntException &e) {
        return 1;
    }
    return 0;
}
