#include "./inc/Hasher.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void HelpPrint(std::ostream& _os)
{
    _os << "-h, --help                       ==== Help message" << std::endl;
    _os << "-m, --mode                       ==== Choose Hash Mode" << std::endl;
    _os << "-f, --file                       ==== Filepath" << std::endl;
    return;
}

int main(int argc, char *argv[])
{
    std::vector<std::string> tokens; 
    HashMode h = HashMode::_WRONG;
    for (int i=0; i < argc; i++)
        tokens.push_back(argv[i]);

    if (tokens.size() == 1) 
    {
        std::cerr << "No parameters" << std::endl;
        HelpPrint(std::cerr);
        return -1;
    }

    if (tokens[1] == "-h" || tokens[1] == "--help")
    {
        if (tokens.size() > 2) 
        {
            HelpPrint(std::cerr);
            return -1;
        }
        HelpPrint(std::cout);
        return 0;
    }
    
    if (tokens.size() == 2 || tokens.size() == 3)
    {
        std::cerr << "Few Arguements" << std::endl;
        HelpPrint(std::cerr);
        return -1;
    }

    if ((tokens[1] == "-m" || tokens[1] == "--mode") && tokens.size( ) == 4)
    {
        if (tokens[2] == "adler32") h = HashMode::_Adler32;
        if (tokens[2] == "sum64") h = HashMode::_Hash64;

        if (h == HashMode::_WRONG) 
        {
            std::cerr << "Wrong hash mode" << std::endl;
            HelpPrint(std::cerr);
            return -1;
        }
        Status s;
        s = hashProccessing(argv[3], h);
        return s == Status::_SUCCESS ?  0 :  -1;
    }
    else if ((tokens[2] == "-m" || tokens[2] == "--mode") && tokens.size( ) == 4)
    {
        if (tokens[3] == "adler32") h = HashMode::_Adler32;
        if (tokens[3] == "sum64") h = HashMode::_Hash64;

        if (h == HashMode::_WRONG) 
        {
            std::cerr << "Wrong hash mode" << std::endl;
            HelpPrint(std::cerr);
            return -1;
        }
        Status s;
        s = hashProccessing(argv[1], h);
        return s == Status::_SUCCESS ?  0 :  -1;
    }
    else
    {
        std::cerr << "Incorrect Input" << std::endl;
        HelpPrint(std::cerr);
        return -1;
    }
}
