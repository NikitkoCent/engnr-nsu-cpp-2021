#include "hash.h"

int main(int argc, char *argv[]) {
    unsigned int mode = 0;

    std::string name_mode;
    std::string filename;

    std::ifstream file;

    if (argc == 2) {
        std::cout << "Using:" << std::endl;
        std::cout << "./hasher <filename> -m <mode>" << std::endl;
        std::cout << "./hasher -m <mode> <filename>" << std::endl;
        std::cout << "<mode> = { adler32, sum64 }" << std::endl;
        return 0;
    } else if (argc == 4) {
        if (argv[1] == "-m") {
            name_mode = argv[2];
            filename = argv[3];
        } else {
            name_mode = argv[3];
            filename = argv[1];
        }
    } else {
        throw std::runtime_error("Invalid arguments");
    }

    if (name_mode == "adler32") {
        mode = 2;
    } else if (name_mode == "sum64") {
        mode = 1;
    } else {
        throw std::runtime_error("Invalid mode");
    }

    file.open(filename, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Invalid filename");
    }

    try {
        if (mode == 1) {
            std::cout << std::hex << sum64(file) << std::endl;
        } else {
            std::cout << std::hex << adler32(file) << std::endl;
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
