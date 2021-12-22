//
// Created by gav on 08/10/2021.
//

#include <iostream>
#include <fstream>

#include "StackCalculator.hpp"

int main(int argc, char** argv){
    std::ifstream in;
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
