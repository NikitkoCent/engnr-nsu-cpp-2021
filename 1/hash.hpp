#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <bitset>
#include <iterator>
#include <algorithm>
#define FILE_ERROR -2
#define ALGO_ERROR -3
#define MODUL 65521
enum Algo
{
    null,
    ADLER32,
    SUM64
};
int eq(std::string first, std::string str) {
    int result = first == str;
    return result;
}

class ArgHelper {
public:
    bool error;
    bool h;
    bool mode;
    std::string path = "";
    Algo algo = Algo::null;

    ArgHelper() {
        error = false;
        h = false;
        mode = false;
    }
    bool isHelp() {
        if (h && !mode && eq(path, "") && algo == Algo::null)
            return true;
        return false;
    }
    bool isMode() {
        if (!h && mode && algo != Algo::null)
            return true;
        return false;
    }
};



