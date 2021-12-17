// CMakeProject1.cpp : Defines the entry point for the application.
//

#include "Lab1.h"

using namespace std;

int main(int argc, char* argv[])
{

    std::string filename;
    std::string mode;
    std::uint_64t val1 = 0;

 
   
    if (argc >=2) {    
        if (strcmp(argv[1], "-h") == 0) {
     
            std::cout << "Information: <mode>:  <adler32, sum64> " << endl;
            std::cout << "Input:             <filename> -m <mode>" << endl;
            std::cout << "Input:             -m <mode> <filename>" << endl;
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
                return 1;
            }
        }
        else {
            std::cout << "Error: Not enough arguments" << endl;
            std::cout << "Examples: <filename> -m <mode>" << endl;
            std::cout << "          -m <mode> <filename>" << endl;
            return 1;
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
	    val1 = adler32(in);
            std::cout << std::hex << val1 << std::endl;
        }
        else {
            std::cout << "File not found" << endl;
            return 1;
        }
        in.close();
        
        }
    
    else if (mode == "sum64"){
        std::ifstream in(filename);
        if (in.is_open())
        {
	    val1 = sum64;
            std::cout << std::hex << val1 << std::endl;
        }
        else {
            std::cout << "File not found" << endl;
            return 1;
        }
        in.close();
    }
    else {
        std::cout << "Error: No such mode" << endl;
        std::cout << "Information: <mode>:  <adler32, sum64> " << endl;
        return 1;
    }
    

    

	return 0;
}
