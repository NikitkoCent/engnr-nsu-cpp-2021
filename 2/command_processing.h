#pragma once

#include "Calculator.h"
#include "lib/SafeInt/SafeInt.hpp"

#include <cstdint>
#include <iostream>
#include <vector>
#include <sstream>
#include <istream>


//void command_processing(const std::vector<std::string> &commands) {
//    CommandCreator creator;
//    std::vector<std::string> words;
//    std::string word;
//    Command* c;
//    std::stack<SafeInt<int64_t>> values;
//    std::map<std::string, SafeInt<int64_t>> names_and_values;
//    int64_t result = 0;
//    for (const auto& command : commands) {
//        c = creator.factoryMethod(command);
//        std::stringstream ss(command);
//        while(getline(ss, word, ' '))
//            words.push_back(word);
//        c->exec(words, values, names_and_values, result);
//        words.clear();
//        delete c;
//    }
//}


void command_processing() {
    CommandCreator creator;
    std::vector<std::string> words;
    std::string word;
    Command* c;
    std::stack<SafeInt<int64_t>> values;
    std::map<std::string, SafeInt<int64_t>> names_and_values;
    int64_t result = 0;
    std::string command;
    std::string cmds;
    while(getline(std::cin, cmds)) {
        std::stringstream ss(cmds);
        while(getline(ss, word, ' ')) {
            words.push_back(word);
        }
        c = creator.factoryMethod(words[0]);
        c->exec(words, values, names_and_values, result);
        words.clear();
        delete c;
    }
}
