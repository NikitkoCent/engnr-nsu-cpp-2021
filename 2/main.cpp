#include <iostream>
#include "calc.h"
#include <string>
#define elif else if
namespace std
{
#include <cstdlib>
};

int main(int argc, char *argv[]) {
    try {
        std::ifstream file;
        const char *filename;
        std::stringstream in_s;
        if (argc > 2 || argc == 0)
            return 1;
        if (argc == 2) {
            filename = argv[1];
            file.open(filename);
            if (!file.is_open()) {
                return 1;
            }
            elif (file.peek() == EOF)
                return 0;
        }
        calc_work(in_s, file, argc);
    } catch (CalcExceptions::BaseEx &err) {
        std::cerr << err._what();
        return 1;
    }
    catch (std::exception &err) {
        std::cerr << err.what();
        return 1;
    }
    catch (SafeIntException &) {
        std::cerr << "Overflow exception!";
        return 1;
    }
    return 0;
}

