#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "hashFunctions.h"


int main(int argc, char *argv[]) {
    std::string filepath, mode;
    std::string help = "Usage: ./helper -m <mode> <filename> or ./helper <filename> -m <mode> \nMode types: adler32 or sum64";
    std::ifstream file;

    if (argc == 4) {
        if (strcmp(argv[1], "-m") == 0) {
            if (strcmp(argv[2], "adler32") == 0 || strcmp(argv[2], "sum64") == 0) {
                mode = argv[2];
                filepath = argv[3];
            } else {
                std::cerr << "Wrong usage: unknown mode" << help << std::endl;
                return 1;
            }
        } else {
            if ((strcmp(argv[3], "adler32") == 0) || (strcmp(argv[3], "sum64") == 0)) {
                mode = argv[3];
                filepath = argv[1];
            } else {
                std::cerr  << "Wrong usage: unknown mode" << help << std::endl;
                return 1;
            }
        }
    } else if (argc == 1){
        std::cerr  << "Wrong usage: no arguments" << help << std::endl;
        return 1;
    } else {
        if(strcmp(argv[1], "-h") == 0 && argc == 2){
            std::cout << help << std::endl;
            return 0;
        }else{
            std::cerr  << "Wrong usage: unknown commands" << help << std::endl;
        }
        return 1;
    }

    file.open(filepath, std::ios::binary);

    if (!(file.is_open())) {
        std::cerr << "FileNotFound Error" << help << std::endl;
        return 1;
    }else if(file.peek() == EOF){
        if(mode == "adler32"){
            std::cout << 1 << std::endl;
        }else{
            std::cout << 0 << std::endl;
        }
        return 0;
    }

    try {
        if (mode == "adler32") {
            std::cout << std::hex << adler32(file) << std::endl;
        } else {
            std::cout << std::hex << sum64(file) << std::endl;
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}

