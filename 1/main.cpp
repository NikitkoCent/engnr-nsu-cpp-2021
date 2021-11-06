#include <iostream>
#include <fstream>
#include <string>


int main(int argc, char *argv[]) {
    std::string filepath, mode;
    std::string help = "Usage: ./helper -m <mode> <filename> or ./helper <filename> -m <mode> \nMode types: adler32 or sum64";

    if(argc == 2){
        if (strcmp(argv[1], "-h") == 0){
            std::cerr << help <<  std::endl;
            return 0;
        }else{
            std::cerr << help <<  std::endl;
            return 0;
        }
    }else if(argc == 4){
        if(strcmp(argv[1], "-m") == 0){
            if(strcmp(argv[2], "adler32") == 0 or strcmp(argv[2], "sum64") == 0){
                mode = argv[2];
                filepath = argv[3];
            }else{
                std::cerr << help <<  std::endl;
                return 0;
            }
        }else if(strcmp(argv[2], "-m") == 0){
            if(strcmp(argv[3], "adler32") == 0 or strcmp(argv[3], "sum64") == 0){
                mode = argv[3];
                filepath = argv[2];
            }else{
                std::cerr << help <<  std::endl;
                return 0;
            }
        }else{
            std::cerr << help <<  std::endl;
            return 0;
        }
    }else{
        std::cerr << help <<  std::endl;
        return 0;
    }

    std::ifstream file;
    file.open(filepath);

    if(!(file.is_open())){
        std::cerr << "FileNotFoundError" <<  std::endl;
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
            std::cout << ((b << 16)|a) << std::endl;
        }else{
            uint64_t contr_sum = 0;
            uint64_t block;
            while(!file.eof()){
                file.read((char*)&block, 8);
                contr_sum += block;
            }
            std::cout << contr_sum << std::endl;
        }
    }catch(std::exception const& e){
        std::cerr << e.what() <<  std::endl;
        return 1;
    }
}
