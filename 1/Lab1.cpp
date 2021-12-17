// CMakeProject1.cpp : Defines the entry point for the application.
//
#include "Lab1.h"

int main(int argc, char* argv[])
{
    std::string filename;
    std::string mode;
    if (argc >=2) {    
        if (strcmp(argv[1], "-h") == 0) {
     
            std::cout << "Information: <mode>:  <adler32, sum64> " << std::endl;
            std::cout << "Input:             <filename> -m <mode>" << std::endl;
            std::cout << "Input:             -m <mode> <filename>" << std::endl;
            return 0;
        }
        else if (argc >= 4) {
            if (strcmp(argv[1], "-m") == 0) {
                mode = argv[2];
                filename = argv[3];

            }
            else if (strcmp(argv[2], "-m") == 0) {
                mode = argv[1];
                filename = argv[3];
            }
            else {
                std::cout << "Error: no -m in the string. End of program" << std::endl;
                return 0;
            }
        }
        else {
            std::cout << "Error: Not enough arguments" << std::endl;
            std::cout << "Examples: <filename> -m <mode>" << std::endl;
            std::cout << "          -m <mode> <filename>" << std::endl;
            return 0;
        }
    }
    else {
        std::cout << "Error: no arguments in the string. End of program" << std::endl;
        return 1;
    }
    if (mode == "adler32" ){
        std::ifstream in(filename);
        if (in.is_open())
        {
            std::cout << std::hex << adler32(in) << std::endl;
        }
        else {
            std::cout << "File not found" << std::endl;
            return 0;
        }
        in.close();      
        }   
    else if (mode == "sum64"){
        std::ifstream in(filename);
        if (in.is_open())
        {
            std::cout << std::hex << sum64(in) << std::endl;
        }
        else {
            std::cout << "File not found" << std::endl;
            return 0;
        }
        in.close();
    }
    else {
        std::cout << "Error: No such mode" << std::endl;
        std::cout << "Information: <mode>:  <adler32, sum64> " << std::endl;
        return 1;
    }
	return 0;
}
