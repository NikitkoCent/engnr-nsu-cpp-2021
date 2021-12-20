#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "Hash.h"

void h(std::ostream &c){
    c<<"Possible command inputs:"<<std::endl;
    c<<"1) ./hasher -h"<<std::endl;
    c<<"2) ./hasher -m <mode> <filename>"<<std::endl;
    c<<"3) ./hasher <filename> -m <mode>"<<std::endl;
    c<<"where <mode>: adler32 or sum64";
}

int main(int argc, char *argv[]) {
    std::ifstream file;
    std::string mode, filename;
    int err = 0;

    if(argc == 2){
        if(strcmp(argv[1],"-h") == 0){
            h(std::cout);
        }
        else{
            std::cerr << "Error! The argument is entered incorrectly." << std::endl;
            h(std::cerr);
            return 1;
        }
    }

    if(argc == 4){
            if( strcmp(argv[1], "-m") == 0 && (strcmp(argv[2],"adler32") == 0 || strcmp(argv[2],"sum64") == 0)) {
                mode = argv[2];
                filename = argv[3];
                //cout<<"nice 1";
            }
            else{
                err++;
            }

            if( strcmp(argv[2], "-m") == 0 && (strcmp(argv[3],"adler32") == 0 || strcmp(argv[3],"sum64") == 0)) {
                mode = argv[3];
                filename = argv[1];
                //cout<<"nice 2";
            }
            else{
                err++;
            }

            if(err == 2){
                std::cerr << "Error! The argument is entered incorrectly." << std::endl;
                h(std::cerr);
                return 1;
            }

    }



    if(argc != 4 && argc != 2){
        if(argc == 1 || argc == 3){
            std::cerr << "Error! Not enough arguments." << std::endl;
            h(std::cerr);
            return 1;
        }
        if(argc > 4){
            std::cerr << "Error! Too many arguments." << std::endl;
            h(std::cerr);
            return 1;
        }

    }

    file.open(filename, std::ios::binary);

    if(!(file.is_open()) && argc!=2){
        std::cerr << "Error: File is not found"<<std::endl;
        h(std::cerr);
        return 1;
    }

    if(mode == "adler32"){
        std::cout << std::hex << Hash::adler32(file) << std::endl;
    }
    if(mode == "sum64"){
        std::cout << std::hex << Hash::sum64(file) << std::endl;
    }







    return 0;
}
