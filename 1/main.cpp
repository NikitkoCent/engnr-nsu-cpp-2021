#include <iostream>
#include <fstream>
#include <cstring>
#include "funk_adl_sum.h"

using namespace std;


int main(int argc, char **argv) {

    string help = "Используйте\n"
                  "-h                   : для того чтобы вывести справочную информацию\n"
                  "<filename> -m <mode> : для того чтобы посчитать переданный вариант хеша переданного файла\n"
                  "-m <mode> <filename> : для того чтобы посчитать переданный вариант хеша переданного файла\n"
                  "\n"
                  "<mode> ∈ { adler32, sum64 }\n";
    ifstream in;
    string filename, mode;
    bool isHelp = false;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
            isHelp = true;
        } else if (strcmp(argv[i], "-m") == 0) {
            mode = argv[++i];
        } else {
            filename = argv[i];
        }
    }

    if ((isHelp) && (!mode.empty() || !filename.empty())) {
        cerr << "ERROR: invalid help option" << endl;
        cerr << help;
        return 1;
    } else if (isHelp){
        cout << help;
        return 0;
    }
    if ((mode != "adler32") && (mode != "sum64")) {
        cerr << "ERROR: invalid mode. Correct modes are {adler32, sum64}" << endl;
        cerr << help;
        return 1;
    }


    in.open(filename, ios::binary);

    if (!in.is_open()) {
        cerr << "ERROR: can`t open file" << endl;
        cerr << help;
        return 1;
    }

    if (mode == "adler32") {
        cout << hex << adler32(in);
    }

    if (mode == "sum64") {
        cout << hex << sum64(in);
    }

    return 0;
}