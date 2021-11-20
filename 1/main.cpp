#include "./inc/Hasher.h"

#include <iostream>
#include <string>
#include <vector>

inline void HelpPrint()
{
    std::cout << "-h, --help                       ==== Help message" << std::endl;
    std::cout << "-m, --mode                       ==== Choose Hash Mode" << std::endl;
    std::cout << "-f, --file                       ==== Filepath" << std::endl;
    return;
}

int main(int argc, char *argv[])
{
    std::vector<std::string*> tokens;
    HashMode h;
    for (int i=0; i < argc; i++)
        tokens.push_back(new std::string(argv[i]));
    
    if (*(tokens[0]) == "-h" || *(tokens[0]) == "--help")
        HelpPrint();

    if (tokens.size() == 1) 
    {
        std::cerr << "No parameters";
        HelpPrint();
    }
    
    if ((*(tokens[0]) == "-m" || *(tokens[0]) == "--mode") && tokens.size( ) == 3)
    {
        if (*tokens[1] == "adler32") h = HashMode::_Adler32;
        if (*tokens[1] == "sum64") h = HashMode::_Hash64;

        if (h == HashMode::_WRONG) 
        {
            std::cerr << "Wrong hash mode";
            HelpPrint();
        }

        hashProccessing(argv[2], h);
    }
    else if ((*(tokens[1]) == "-m" || *(tokens[1]) == "--mode") && tokens.size( ) == 3)
    {
        if (*tokens[2] == "adler32") h = HashMode::_Adler32;
        if (*tokens[2] == "sum64") h = HashMode::_Hash64;

        if (h == HashMode::_WRONG) 
        {
            std::cerr << "Wrong hash mode";
            HelpPrint();
        }

        hashProccessing(argv[0], h);
    }
    else
    {
        std::cerr << "Incorrect Input";
        HelpPrint();
    }
}
