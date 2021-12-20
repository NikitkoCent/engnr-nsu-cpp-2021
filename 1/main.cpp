#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "Hash.h"

using namespace std;

void h(ostream &c){
    c<<"Possible command inputs:"<<endl;
    c<<"1) ./hasher -h"<<endl;
    c<<"2) ./hasher -m <mode> <filename>"<<endl;
    c<<"3) ./hasher <filename> -m <mode>"<<endl;
    c<<"where <mode>: adler32 or sum64";
}

int main(int argc, char *argv[]) {
    ifstream file;
    string mode, filename;
    int err = 0;

    if(argc == 2){
        if(strcmp(argv[1],"-h") == 0){
            h(cout);
        }
        else{
            cerr << "Error! The argument is entered incorrectly." << endl;
            h(cerr);
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
                cerr << "Error! The argument is entered incorrectly." << endl;
                h(cerr);
                return 1;
            }

    }

    if(argc != 4 && argc != 2){
        if(argc == 1 | argc == 3){
            cerr << "Error! Not enough arguments." << endl;
            h(cerr);
            return 1;
        }
        if(argc > 4){
            cerr << "Error! Too many arguments." << endl;
            h(cerr);
            return 1;
        }

    }

    file.open(filename, ios::binary);

    if(!(file.is_open()) && argc!=2){
        cerr << "Error: File is not found"<<endl;
        h(cerr);
        return 1;
    }

    if(mode == "adler32"){
        cout << std::hex << Hash::adler32(file) << endl;
    }
    if(mode == "sum64"){
        cout << hex << Hash::sum64(file) << endl;
    }







    return 0;
}
