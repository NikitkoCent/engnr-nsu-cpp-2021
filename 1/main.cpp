#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "Hash.h"

#define elif else if

int main(int argc, char *argv[]) {
    std::string mode, file_name = "";
    std::string help = "How to use this programm: ./helper -m <mode> <filename> or ./helper <filename> -m <mode> \nModes: adler32 or sum64";
    std::ifstream file;
    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        std::cout << help << std::endl;
        return 1;
    } elif (argc == 4) {
        if (strcmp(argv[1], "-m") == 0) {
            if (strcmp(argv[2], "adler32") == 0) {
                mode = "adler32";
                file_name = argv[3];
            } elif (strcmp(argv[2], "sum64") == 0) {
                mode = "sum64";
                file_name = argv[3];
            } else {
                std::cerr << "Wrong mode, please check input" << std::endl;
                return 1;
            }
        } elif (strcmp(argv[2], "-m") == 0) {
            if (strcmp(argv[3], "adler32") == 0) {
                mode = "adler32";
                file_name = argv[1];
            } elif (strcmp(argv[3], "sum64") == 0) {
                mode = "sum64";
                file_name = argv[1];
            } else {
                std::cerr << "Wrong mode, please check input" << std::endl;
                return 1;
            }
        } else {
            std::cerr << "wrong input" << std::endl;
            return 1;
        }
    } elif (argc == 1) {
        std::cerr << "Please, enter arguments";
        return 1;
    } else {
        std::cerr << "wrong input" << std::endl;
        return 1;
    };
    file.open(file_name, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "file does not exist" << std::endl;
        return 1;
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

}
