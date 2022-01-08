#include "hash.h"

int main(int argc, char *argv[]) {
    std::string help_message = "Using:\n"
                               "./hasher <filename> -m <mode>\n"
                               "./hasher -m <mode> <filename>\n"
                               "<mode> = { adler32, sum64 }\n";
    try {
        unsigned int mode = 0;

        std::string name_mode;
        std::string filename;

        std::ifstream file;

        if (argc == 2) {
            if (argv[1] == "-h") {
                std::cout << help_message;
                return 0;
            } else {
                std::cerr << help_message;
                return 1;
            }
        } else if (argc == 4) {
            if (argv[1] == "-m") {
                name_mode = argv[2];
                filename = argv[3];
            } else if (argv[2] == "-m") {
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
            throw std::runtime_error("Invalid filename");
        }

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
