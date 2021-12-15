#include <iostream>

#include "../inc/ArgParser.h"
#include "../inc/App.h"
#include "../inc/exceptions.h"

int main(int argc, char *argv[])
{
    try
    {
        if (argc == 2)
            proceedWithArgs(*argv);
        if (argc == 1)
            proceedNoArgs(std::cin);
        else
        {
            std::cerr << "Input name of file or not" << std::endl;
        }
        return 0;
    }
    catch (const std::exception &error)
    {
        std::cerr << error.what() << std::endl;
        return -1;
    }
}
