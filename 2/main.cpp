#include <iostream>
#include <fstream>
#include "StackCalc.h"


int main(int argc, char** argv) {
    SC::StackCalc calc;
    try {
        if (argc > 1) {
            std::ifstream input;
            input.open(argv[1]);
            calc.execute(input);
        } else {
            calc.execute(std::cin);
        }
    }
    catch (StackExceptions::SCException &err) {
        std::cerr << err.what();
        return 1;
    }
    catch (std::exception &err) {
        std::cerr << err.what();
        return 2;
    }
    catch (SafeIntException &err) {
        std::cerr << "Integer operation exception";
        return 3;
    }
    return 0;
}
