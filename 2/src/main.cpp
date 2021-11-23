#include <iostream>
#include <filesystem>

#include "../inc/ArgParser.h"
#include "../inc/App.h"

int main(int argc, char *argv[]) {
    InputParser input(argc, argv);

    const std::string &file_name = input.getCmdOption("-f");
    try {
        if (file_name.empty()) {
            auto path = std::filesystem::current_path() / std::filesystem::path(file_name);
            proceedWithArgs(path.string().c_str());
        } else {
            proceedNoArgs();
        }
    } catch (std::exception &error) {
        std::cerr << error.what() << std::endl;
    }
}
