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

//    std::ifstream in;
//    StackCalculator stackCalculator;
//    try {
//        if (argc > 1) {
//            in.open(argv[1]);
//            stackCalculator.parse_stream(in);
//        } else {
//            stackCalculator.parse_stream(cin);
//        }
//    } catch (std::exception &e) {
//        std::cerr << e.what() << endl;
//        return 1;
//    }
//    return 0;
//}



    try {
        string filepath;

        if (argc > 1) {
            if (argc == 2) {
                filepath = argv[1];
                ifstream file;
                file.open(filepath);
                if (!file.is_open()) {
                    cerr << "FileNotFoundError" << endl;
                    return 1;
                } else if (file.peek() == EOF) {
                    return 0;
                }
                ReadFromFile(file);
            } else {
                cerr << "Please, enter file path or arithmetic operations" << endl;
                return 1;
            }
        } else ReadFromFile(std::cin);
    }
    catch (const StackException &e) {
        cerr << e.what() << endl;
        return 1;
    }  catch (SafeIntException &e) {
        return 1;
    }
    return 0;
}
