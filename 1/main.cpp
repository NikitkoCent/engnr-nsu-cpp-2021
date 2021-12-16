#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include "hashfunctions.h"


int main(int argc, char *argv[]) {
    std::ifstream file;
    std::string phrase, path, mode;
    phrase = "You should use: ./helper -m <mode> <filename> or ./helper <filename> -m <mode>. \n<mode>: adler32 or sum64";
    if (argc == 2){
        if (strcmp(argv[1], "-h") == 0){
            std::cout << phrase << std::endl;
            return 0;
        }
        else{
            std::cerr << "Error: unknown command. " << phrase << std::endl;
            return 1;
        }
    } else if(argc == 4){
        if((strcmp(argv[1], "-m") == 0)&&((strcmp(argv[2],"adler32") == 0)||(strcmp(argv[2],"sum64") == 0))){
            mode = argv[2];
            path = argv[3];
        } else if((strcmp(argv[2], "-m") == 0)&&((strcmp(argv[3],"adler32") == 0)||(strcmp(argv[3],"sum64") == 0))){
            mode = argv[3];
            path = argv[1];
        } else{
            std::cerr << "Error: wrong arguments"  << phrase << std::endl;
            return 1;
        }
    } else {
        if(argc == 1){
            std::cerr << "Error: no arguments" << phrase << std::endl;
            return 1;
        } else {
            std::cerr << "Error: unknown command" << phrase << std::endl;
            return 1;
        }
    }

    file.open(path, std::ios_base::binary);

    if(!(file.is_open())){
        std::cerr << "Error: File not found" << phrase << std::endl;
        return 1;
    }
    if(file.peek() == EOF){
        if(mode == "adler32"){
            std::cout << 1 << std::endl;
        }
        if(mode == "sum64"){
            std::cout << 0 << std::endl;
        }
        return 0;
    }

    try {
        if(mode == "adler32"){
            std::uint32_t hash = adler32(file);
            std::cout << std::hex << hash << std::endl;
        }
        if(mode == "sum64"){
            std::uint64_t hash = sum64(file);
            std::cout << std::hex << hash << std::endl;
        }
    } catch (std::exception &error) {
        std::cerr << error.what();
        return 1;
    }
    return 0;
}
