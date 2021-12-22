//
// Created by gav on 08/10/2021.
//

#include <iostream>
#include <sstream>
#include <fstream>

#include "StackCalculator.hpp"
#include "CommandFactory.h"

int main(int argc, char** argv){
    std::ifstream in;
    vector<Command*> cmds;
    StackCalculator stackCalculator;
    try {
        if (argc > 1) {
            in.open(argv[1]);
            stackCalculator.parse_stream(in);
        } else {
            stackCalculator.parse_stream(cin);
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << endl;
        return 1;
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << endl;
        return 1;
    }
    return 0;
}
