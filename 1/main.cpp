#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#include "HashCalc.h"


// ./hasher -h  => ac = 2 av = ["hasher", "-h" ]
// ./hasher -m sum64  => ac = 3 av = ["hasher", "-m", "sum64" ]

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
                std::cerr << "usage: [-h | --help] [-m <adler32; sum64> | --mode <adler32; sum64>] <filename>";
                return 1;
            }
            filename = std::string(av[i]);
        }
    }

    if (mode != "adler32" && mode != "sum64") {
        // std::cerr << mode << std::endl;

//        if (help_mode) {
//            std::cout << "Mode must be adler32 or sum64" << std::endl;
//            std::cout << "usage: [-h | --help] [-m <adler32; sum64> | --mode <adler32; sum64>] <filename>";
//            return 1;
//        }
        std::cerr << "Mode must be adler32 or sum64" << std::endl;
        std::cerr << "usage: [-h | --help] [-m <adler32; sum64> | --mode <adler32; sum64>] <filename>";
        return 1;
    }
    file.open(filename, std::ios::binary);
    if (!file.is_open()) {

//        if (help_mode) {
//            std::cout << "File doesn't exists" << std::endl;
//            std::cout << "usage: [-h | --help] [-m <adler32; sum64> | --mode <adler32; sum64>] <filename>";
//            return 1;
//        }
        std::cerr << "File doesn't exists" << std::endl;
        std::cerr << "usage: [-h | --help] [-m <adler32; sum64> | --mode <adler32; sum64>] <filename>";
        return 1;
    }

    if (help_mode) {
        std::cout << "usage: [-h | --help] [-m <adler32; sum64> | --mode <adler32; sum64>] <filename>";
        return 0;
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