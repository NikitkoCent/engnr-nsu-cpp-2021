// CMakeProject1.cpp : Defines the entry point for the application.
//
#include "Lab1.h"

int main(int argc, char* argv[])
{
    std::string filename;
    std::string mode;
    if (argc >= 2) {
        if (strcmp(argv[1], "-h") == 0 || argc == 2) {
            std::cout << "Information: <mode>:  <adler32, sum64> " << std::endl;
            std::cout << "Input:             <filename> -m <mode>" << std::endl;
            std::cout << "Input:             -m <mode> <filename>" << std::endl;
            return 0;
        }
        else if (argc == 4) {
            if (strcmp(argv[1], "-m") == 0) {
                mode = argv[2];
                filename = argv[3];

            }
            else if (strcmp(argv[2], "-m") == 0) {
                mode = argv[3];
                filename = argv[1];
            }
            else {
                std::cerr << "Error: no -m in the string. End of program" << std::endl;
                std::cout << "Information: mode - <adler32, sum64>; input: <filename> -m <mode> or -m <mode> <filename> " << std::endl;
                return 1;
            }
        }
        else if (argc < 4) {
            std::cerr << "Error: Not enough arguments" << std::endl;
            std::cout << "Information: mode - <adler32, sum64>; input: <filename> -m <mode> or -m <mode> <filename> " << std::endl;            
            return 1;
        }
        else {
            std::cerr << "Error: Too many arguments" << std::endl;
            std::cout << "Information: mode - <adler32, sum64>; input: <filename> -m <mode> or -m <mode> <filename> " << std::endl;
            return 1;
        }
    }
    else {
        std::cerr << "Error: no arguments in the string. End of program" << std::endl;
        std::cout << "Information: mode - <adler32, sum64>; input: <filename> -m <mode> or -m <mode> <filename> " << std::endl;        
        return 1;
    }
    std::ifstream in(filename);
    try {
        if (mode == "adler32") {
            std::cout << std::hex << adler32(in) << std::endl;
        }
        else if (mode == "sum64") {
            std::cout << std::hex << sum64(in) << std::endl;
        }
        else {
            throw 1;
        }
    }
    catch (int) {
        std::cerr << "Error: No such mode" << std::endl;
        std::cerr << "Information: <mode>:  <adler32, sum64> " << std::endl;
        return 1;
    }
    catch (...) {
        std::cerr << "File error" << std::endl;
        return 1;
    }
    in.close();
    

    return 0;
}
