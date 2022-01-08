#include "hash.h"

int main(int argc, char *argv[]) {
    unsigned int mode = 0;

    std::string help_message = "Using:\n"
                               "./hasher <filename> -m <mode>\n"
                               "./hasher -m <mode> <filename>\n"
                               "<mode> = { adler32, sum64 }\n";

    std::string name_mode;
    std::string filename;

    std::ifstream file;

    if (argc == 2) {
        if(argv[1] == "-h") {
            std::cout << help_message;
            return 0;
        } else {
            throw std::runtime_error("Invalid arguments");
        }
    } else if (argc == 4) {
        if (argv[1] == "-m") {
            name_mode = argv[2];
            filename = argv[3];
        } else if(argv[2] == "-m") {
            name_mode = argv[3];
            filename = argv[1];
        } else {
            throw std::runtime_error("Invalid arguments");
        }
    } else {
        throw std::runtime_error("Invalid arguments");
    }

    file.open(filename, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Invalid filename");
    }

    try {
        if (name_mode == "sum64") {
            std::cout << std::hex << sum64(file) << std::endl;
        } else if(name_mode == "adler32") {
            std::cout << std::hex << adler32(file) << std::endl;
        } else {
            throw std::runtime_error("Invalid mode");
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::cerr << help_message;
        return 1;
    }
    return 0;
}
