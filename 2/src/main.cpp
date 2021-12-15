#include <iostream>

#include "../inc/ArgParser.h"
#include "../inc/App.h"
#include "../inc/exceptions.h"

int main(int argc, char *argv[])
{
    InputParser input(argc, argv);

    const std::optional<std::string_view> file_name = input.getCmdOption("-f");
    try
    {
        if (file_name.has_value())
            proceedWithArgs(file_name.value().data());
        else
            proceedNoArgs(std::cin);
        return 0;
    }
    catch (const std::exception &error)
    {
        std::cerr << error.what() << std::endl;
        return -1;
    }
}
