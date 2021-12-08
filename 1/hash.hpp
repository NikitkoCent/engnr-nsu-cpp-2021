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



<<<<<<< HEAD
=======
int callAdler32(string fileName) {
    ifstream myfile(fileName);

    if (!myfile) {
        std::cerr << "File failed to open";
        return FILE_ERROR;
    }

    uint32_t result_adler = adler32(fileName);
    std::cout << std::hex<< result_adler;
    return 0;
}
int callSumm64(string fileName) {
    ifstream myfile(fileName, std::ios::binary);

    if (!myfile) {
        std::cerr << "File failed to open";
        return FILE_ERROR;
    }

    uint64_t result_sum64 = summ64(fileName);
    std::cout << std::hex<< result_sum64;
    return 0;
}

>>>>>>> 8a482a7b84a359cba63f9c858ac91a24862ef370
