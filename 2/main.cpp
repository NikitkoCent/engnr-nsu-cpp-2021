//
// Created by Дарья on 06.01.2022.
//
#include "Commands.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
//#include "../../libs/SafeInt/SafeInt.hpp"
#include <stdexcept>

using std:: string;

int main(int argc, char *argv[]) {
    try {
        string filepath;
        bool flag = true;

        if (argc > 1) {
            flag = false;
            if (argc == 2) {
                filepath = argv[1];
            } else {
                std::cerr << "Wrong usage." << std::endl;
                return 1;
            }
        }

        if (flag) {
            ReadLine();
        } else {
            std::ifstream file;
            file.open(filepath);
            if (!file.is_open()) {
                std::cerr << "FileNotFoundError" << std::endl;
                return 1;
            } else if (file.peek() == EOF) {
                return 0;
            }
            ReadFromFile(file);
        }
    }  catch (const StackException &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }  catch (SafeIntException &e) {
        return 1;
    }  catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
