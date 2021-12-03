#include "../../inc/ArgParser.h"
#include <algorithm>
#include <optional>
#include <string_view>

InputParser::InputParser(int &argc, char* argv[]) : tokens() {
    for (int i = 1; i < argc; ++i)
        this->tokens.emplace_back(std::string(argv[i]));
}

const std::optional<std::string_view> InputParser::getCmdOption(const std::string &option) const {
    auto itr = std::find(this->tokens.begin(), this->tokens.end(), option);
    if (itr != this->tokens.end() && ++itr != this->tokens.end()) {
        return {*itr};
    }
    return {};
}





