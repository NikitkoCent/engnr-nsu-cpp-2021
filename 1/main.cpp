//
// Created by Дарья on 12.12.2021.
//
#include <iostream>
#include <cstring>
#include <fstream>
#include "HashFunc.h"

using std::cout;
using std::endl;
using std::string;
using std:: cerr;
using std::ifstream;
using std:: hex;
using std::exception;


int main(int argc, char *argv[]) {
    ifstream file;
    string filename, mode;
    string help = "\nHow to use the program?:\nYou should enter to use it: './helper -m <mode> <filename>' or './helper <filename> -m <mode>' \nYou can choose from this types of modes: adler32 or sum64\n And you can enter: ' ./hasher -h' to print Help";
    if (argc > 4) {
        cerr << help << endl;
    } else if ((argc == 2) && (strcmp(argv[1], "-h") == 0)) {
        cout << help << endl;
        return 0;
    } else if (argc == 4) {
        if (strcmp(argv[1], "-m") == 0) {
            if ((strcmp(argv[3], "adler32") == 0) || (strcmp(argv[3], "sum64") == 0)) {
                mode = argv[3];
                filename = argv[1];
            } else {
                cerr << "Unknown mode!" << help << endl;
                return 1;
            }
            if (strcmp(argv[1], "-m") == 0) {
                if (strcmp(argv[2], "sum64") == 0 || strcmp(argv[2], "adler32") == 0) {
                    mode = argv[2];
                    filename = argv[3];
                } else {
                    cerr << "Unknown mode!" << help << endl;
                    return 1;
                }
            }
        }
    }

    file.open(filename, std::ios::binary);
    if (!(file.is_open())) {
        cerr << "FileNotFound Error" << help << endl;
        return 1;
    }

    try {
        if (mode == "adler32") {
            cout << hex << adler32(file) << endl;
        } else {
            cout << hex << sum64(file) << endl;
        }
    } catch (...) {
        cerr << "There is an exception!" << endl;
        return 1;
    }
    return 0;
}