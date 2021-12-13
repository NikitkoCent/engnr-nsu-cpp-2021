#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#include "HashCalc.h"


// ./hasher -h  => ac = 2 av = ["hasher", "-h" ]
// ./hasher -m sum64  => ac = 3 av = ["hasher", "-m", "sum64" ]
void help_msg(std::ostream &os) {
    os << "usage: [-h | --help] [-m <adler32; sum64> | --mode <adler32; sum64>] <filename>";
}

int main(int ac, char **av) {
    std::string mode, filename;
    std::ifstream file;
    // region ParseArgs
    bool help_mode = false;

    for (int i = 1; i < ac; i++) {
        if (strcmp(av[i], "-h") == 0 || strcmp(av[i], "--help") == 0) {
            help_mode = true;

        } else if ((strcmp(av[i], "-m") == 0) || (strcmp(av[i], "--mode") == 0)) {
            mode = std::string(av[++i]);
        } else {
            if (!filename.empty()) {
                std::cerr << "Only one file can be used" << std::endl;
                help_msg(std::cerr);
                return 1;
            }
            filename = std::string(av[i]);
        }
    }
    if (help_mode) {
        if (ac > 2) {
            help_msg(std::cerr);
        } else {
            help_msg(std::cout);
        }
        return ac > 2;
    }
    if (mode != "adler32" && mode != "sum64") {
        std::cerr << "Mode must be adler32 or sum64" << std::endl;
        help_msg(std::cerr);
        return 1;
    }
    file.open(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "File doesn't exists" << std::endl;
        help_msg(std::cerr);
        return 1;
    }


    // endregion
    if (mode == "adler32") {
        auto result = HashCalc::Adler32(file);
        std::cout << std::hex << result << std::endl;
    } else if (mode == "sum64") {
        auto result = HashCalc::Sum64(file);
        std::cout << std::hex << result << std::endl;
    }


    return 0;
}