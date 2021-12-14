#include "../commands/StackCalc.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>


int main(int argc, char *argv[]) {
    std::string filepath;
    std::string help = "Usage: ./Calculator <filepath> or ./Calculator\n"
                       "Commands: #, POP, PUSH <number>, PUSH <varname>, PEEK <varname>, ABS, PLUS, MINUS, MUL, DIV, PRINT, READ.";
    bool flag = false;

    if(argc > 1){
        if(strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "-help") == 0){
            std::cout << help << std::endl;
            return 0;
        }
        if(argc == 2){
            filepath = argv[1];
        }else{
            std::cerr << "Wrong usage." << help << std::endl;
            return 1;
        }
    }else{
        flag = true;
    }


    if (flag) {
        OneCommandRead();
    } else {
        std::ifstream file;
        file.open(filepath);
        if(!file.is_open()){
            std::cerr << "FileNotFoundError" << help << std::endl;
            return 1;
        }else if(file.peek() == EOF){
            return 0;
        }
        ReadFromStream(file);
    }
    return 0;
}

