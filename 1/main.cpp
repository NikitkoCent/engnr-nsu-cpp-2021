#include "hash.h"

#include <string>
#include <cstring>

int main(int argc, char *argv[]) {
    std::string help_message = "Using:\n"
                               "./hasher <filename> -m <mode>\n"
                               "./hasher -m <mode> <filename>\n"
                               "<mode> = { adler32, sum64 }\n";
    std::string name_mode;
    std::string filename;

    std::ifstream file;

    if (argc == 2) {
        if (strcmp(argv[1], "-h") == 0) {
            std::cout << help_message;
            return 0;
        } else {
            std::cerr << "bruh";
            return 1;
        }
    } else if (argc == 4) {
        if (strcmp(argv[1], "-m") == 0) {
            name_mode = argv[2];
            filename = argv[3];
        } else if (strcmp(argv[2], "-m") == 0) {
            name_mode = argv[3];
            filename = argv[1];
        } else {
            std::cerr << help_message;
            return 1;
        }
    } else {
        std::cerr << help_message;
        return 1;
    }

    file.open(filename, std::ios_base::binary);
    if (!file.is_open()) {
        std::cerr << "Invalid filename" << std::endl;
        std::cerr << help_message;
        return 1;
    }
    try {
        if (name_mode == "sum64") {
            std::cout << std::hex << sum64(file) << std::endl;
        } else if (name_mode == "adler32") {
            std::cout << std::hex << adler32(file) << std::endl;
        } else {
            std::cerr << help_message;
            return 1;
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::cerr << help_message;
        return 1;
    }
    return 0;
}
