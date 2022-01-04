#include <iostream>
#include "calc.h"
#include <string>
namespace std
{
#include <cstdlib>
};

int main(int argc, char *argv[]) {
    try {
        std::ifstream file;
        const char *filepath;
        std::stringstream in_s;
        if (argc > 2 || argc == 0)
            return 1;
        if (argc == 2) {
            filepath = argv[1];
            file.open(filepath);
            if (!file.is_open()) {
                return 1;
            }
            else if (file.peek() == EOF)
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

