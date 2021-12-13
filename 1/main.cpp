#include <iostream>
#include <cstring>

#include "hash_funcs.h"


enum Results
{
    SUCCESS,
    HELP = 1,
    UNEXPECTED_NUMBER_ARGUMENTS = 1,
    UNEXPECTED_FLAG = 1,
    UNEXPECTED_MODE = 1,
    ERROR_READING_FILE,
};

const char MESSAGES[][256] {
        "Success",
        "Usage:\n"
        "./hasher -h -- print help;\n"
        "./hasher <filepath> -m <mode> -- run calculate a hash of the file;\n"
        "./hasher -m <mode> <filepath> -- alternative run.\n\n"
        "Modes:\n"
        "adler32\n"
        "sum64\n",
        "Cannot open the file",
};


void message(std::ostream &out, const char message[])
{
    out << message << std::endl;
}



int main(int argc, char *argv[])
{
    if(argc == 2 && strcmp(argv[1], "-h") == 0) // -h show help
    {
        message(std::cout, MESSAGES[HELP]);
    }
    else if(argc == 4) // check mode and calculate hash
    {
        char *mode = nullptr;
        char *filepath = nullptr;
        if(strcmp(argv[1], "-m") == 0)
        {
            mode = argv[2];
            filepath = argv[3];
        }
        else if(strcmp(argv[2], "-m") == 0)
        {
            mode = argv[3];
            filepath = argv[1];
        }
        else // incorrect usage
        {
            message(std::cerr, MESSAGES[UNEXPECTED_FLAG]);
            exit(UNEXPECTED_FLAG);
        }

        std::ifstream file(filepath, std::ios::binary );
        if (file.is_open())
        {
            if (strcmp(mode, "adler32") == 0)
            {
                std::cout << std::hex << adler32(file);
            }
            else if (strcmp(mode, "sum64") == 0)
            {
                std::cout << std::hex << sum64(file);
            }
            else // incorrect usage
            {
                message(std::cerr, MESSAGES[UNEXPECTED_MODE]);
                exit(UNEXPECTED_MODE);
            }
        }
        else // error with open file
        {
            message(std::cerr, MESSAGES[ERROR_READING_FILE]);
            exit(ERROR_READING_FILE);
        }
    }
    else // incorrect usage
    {
        message(std::cerr, MESSAGES[UNEXPECTED_NUMBER_ARGUMENTS]);
        exit(UNEXPECTED_NUMBER_ARGUMENTS);
    }
    return SUCCESS;
}