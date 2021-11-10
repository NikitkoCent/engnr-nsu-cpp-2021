#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#ifdef __linux__
#include <arpa/inet.h>
#endif

#ifdef _WIN32
#include <Ws2_32.li>
#endif

int main(int argc, char *argv[]) {
    std::string filepath, mode;
    std::string help = "Usage: ./helper -m <mode> <filename> or ./helper <filename> -m <mode> \nMode types: adler32 or sum64";



    if (argc == 4) {
        if (strcmp(argv[1], "-m") == 0) {
            if (strcmp(argv[2], "adler32") == 0 || strcmp(argv[2], "sum64") == 0) {
                mode = argv[2];
                filepath = argv[3];
            } else {
                std::cerr << help << 1 << std::endl;
                return 1;
            }
        } else {
            if ((strcmp(argv[3], "adler32") == 0) || (strcmp(argv[3], "sum64") == 0)) {
                mode = argv[3];
                filepath = argv[1];
            } else {
                std::cerr << help << 3 << std::endl;
                return 1;
            }
        }
    } else if (argc == 1){
        std::cerr << help << std::endl;
        return 1;
    } else {
        if(strcmp(argv[1], "-h") == 0 && argc == 2){
            std::cout << help << 4 << std::endl;
            return 0;
        }else{
            std::cerr << help << 5 << std::endl;
        }
        return 1;
    }

    std::ifstream file;
    file.open(filepath);

    if (!(file.is_open())) {
        std::cerr << help << 6 << std::endl;
        return 1;
    }else if(file.peek() == EOF){
        if(mode == "adler32"){
            std::cout << 1 << std::endl;
        }else{
            std::cout << 0 << std::endl;
        }
        return 0;
    }

    try {
        if (mode == "adler32") {
            uint32_t a = 1, b = 0;
            unsigned char s;
            while (file.read((char *)(&s), sizeof(unsigned char))) {
                a = (a + s) % 65521;
                b = (b + a) % 65521;
            }
            std::cout << std::hex << ((b << 16) | a) << std::endl;
        } else {
            uint64_t contr_sum = 0;
            while (!file.eof()) {
                uint64_t block;
                file.read((char *) &block, sizeof(uint64_t));
                block = NTOHLL(block);
//                block = (((uint64_t)ntohl((block) & 0xFFFFFFFFFF)) << 32) | ntohl((uint32_t)((block) >> 32));
                if (file.gcount() != 8){
                    block >>= 64-8*file.gcount();
                }
                contr_sum += block;
            }
            std::cout << std::hex << contr_sum << std::endl;
        }
    } catch (std::exception const &e) {
        std::cerr << help << 6 << std::endl;
        return 1;
    }
    return 0;
}

