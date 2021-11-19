#pragma once

#include <vector>
#include <string>

class InputParser{
public:
    InputParser(int &argc, char* argv[]);

    [[nodiscard]] const std::string& getCmdOption(const std::string &option) const;

private:
    std::vector<std::string> tokens{};
};
