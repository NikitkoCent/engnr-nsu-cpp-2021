#include <iostream>
#include <fstream>
#include <string>


int main(int argc, char *argv[]) {
    std::string filepath, mode;
    std::string help = "Usage: ./helper -m <mode> <filename> or ./helper <filename> -m <mode> \nMode types: adler32 or sum64";


    if(argc == 4){
        if (argv[1] == "-m") {
            if (argv[2] == "-m") {
                if (argv[3] == "adler32" || argv[3] == "sum64") {
                    mode = argv[3];
                    filepath = argv[2];
                } else {
                    std::cerr << help << std::endl;
                    return 1;
                }
            } else {
                std::cerr << help << std::endl;
                return 1;
            }
        } else {
            if (argv[2] == "adler32" || argv[2] == "sum64") {
                mode = argv[2];
                filepath = argv[3];
            } else {
                std::cerr << help << std::endl;
                return 1;
            }
        }
    }else{
        std::cerr << help << std::endl;
        return 1;
    }

    std::ifstream file;
    file.open(filepath);

    if(!(file.is_open())){
        std::cerr << help <<  std::endl;
        return 1;
    }

    try{
        if(mode == "adler32"){
            uint32_t a = 1, b = 0;
            while(!file.eof()){
                char s;
                file.read(&s, sizeof(char));
                a = (a + s) % 65521;
                b = (b + a) % 65521;
            }
            std::cout << std::hex << ((b << 16)|a) << std::endl;
        }else{
            uint64_t contr_sum = 0;
            uint64_t block;
            while(!file.eof()){
                file.read((char*)&block, 8);
                contr_sum += block;
            }
            std::cout << std::hex << contr_sum << std::endl;
        }
    }catch(std::exception const& e){
        std::cerr << help <<  std::endl;
        return 1;
    }
    return 0;
}
