#include "SafeInt/SafeInt.hpp"
#include "Calc.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

void h(std::ostream &c){
    c<<"Use:"<<std::endl;
    c<<"./calculator <filename> or ./calculator"<<std::endl;
    c<<"Possible command inputs:"<<std::endl;
    c<<"#, POP, PUSH <number>, PEEK <varname>, PUSH <varname>, ABS, PLUS, MINUS, MUL, DIV, PRINT, READ";
}

int main(int argc, char *argv[]) {
    try {
        std::ifstream file;
        std::string path;

        if(argc != 1 && argc != 2){
            std::cerr << "Error: The argument is entered incorrectly" << std::endl;
            h(std::cerr);
            return 1;
        }

        if (argc == 2){
            path = argv[1];
            file.open(path);
            if (!file.is_open()){
                std::cerr << "Error: File is not found" << std::endl;
                h(std::cerr);
                return 1;
            }

            if (file.peek() == EOF){
                return 0;
            }

        }
        counting(file, argc);
    }
    catch (StackException &error){
        std::cerr << error.what() << std::endl;
        return 1;
    }
    return 0;
}