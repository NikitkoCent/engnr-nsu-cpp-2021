#include <iostream>

#include "../inc/ArgParser.h"
#include "../inc/App.h"
#include "../inc/exceptions.h"

int main(int argc, char *argv[])
{
    try
    {
        if (argc == 2)
            proceedWithArgs(argv[1]);
        else if (argc == 1)
            proceedNoArgs(std::cin);
        else
        {
            std::cerr << "Wrong input : enter filename or input data on your own." << std::endl;
        }
        return 0;
    }
    catch (const std::exception &error)
    {
        std::cerr << error.what() << std::endl;
        return -1;
    }
}
