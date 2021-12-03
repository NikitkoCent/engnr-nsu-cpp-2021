#pragma once

#include <vector>
#include <string>
#include <optional>
#include <string_view>

class InputParser{
public:
    InputParser(int &argc, char* argv[]);

    [[nodiscard]] const std::optional<std::string_view> getCmdOption(const std::string &option) const;

private:
    std::vector<std::string> tokens{};
};
