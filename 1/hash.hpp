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
using namespace std;
int eq(string first, string str) {
    int result = first == str;
    return result;
}
enum Algo
{
    null,
    ADLER32,
    SUM64
};

class ArgHelper {
public:
    bool h;
    bool mode;
    string path = "";
    Algo algo = Algo::null;

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

ArgHelper* getArg(int argc, char* argv[]) {
    ArgHelper* argHelper = new ArgHelper();

    if (argc == 2 && eq(argv[1], "-h")) {
        argHelper->h = true;
    }
    else if (argc == 4 && eq(argv[1], "-m")) {
        argHelper->mode = true;
        if (eq(argv[2], "adler32"))
            argHelper->algo = Algo::ADLER32;
        else if (eq(argv[2], "sum64"))
            argHelper->algo = Algo::SUM64;
        else
            return NULL;
        argHelper->path = argv[3];
    }
    else if (argc == 4 && eq(argv[2], "-m")) {
        argHelper->mode = true;
        if (eq(argv[3], "adler32"))
            argHelper->algo = Algo::ADLER32;
        else if (eq(argv[3], "sum64"))
            argHelper->algo = Algo::SUM64;
        else
            return NULL;
        argHelper->path = argv[1];
    }
    else
        return NULL;

    return argHelper;
}

void show_help() {
    cout << "Background information:" << endl;
    cout << "<filename> -m <mode> - calculate the transmitted version of the hash of the transmitted file;" << endl;
    cout <<"-m <mode> <filename> - calculate the transmitted version of the hash of the transmitted file;" << endl;
    cout << "\twhere\tfilename is the file name (for example, test.txt)" << endl;
    cout << "\t\tmode is the name of the adler32 or sum 64 algorithm" << endl;
}

void show_err() {
    cerr << "Error, arguments are incorrectly set." << endl;
    cerr << "Reference information:" << endl;
    cerr << "<filename> -m <mode> - calculate the transmitted version of the hash of the transmitted file;" << endl;
    cerr <<"-m <mode> <filename> - calculate the transmitted version of the hash of the transmitted file;" << endl;
    cerr << "\twhere\tfilename is the file name (for example, test.txt)" << endl;
    cerr << "\t\tmode is the name of the adler32 or sum 64 algorithm" << endl;
}
uint32_t  adler32(string name) {
    uint16_t A = 1;
    uint16_t B = 0;

    std::fstream fs(name, std::ios::in | std::ios::binary);
    unsigned char c;

    if (fs.is_open()) {
        while (true) {
            fs.read((char*)&c, sizeof(unsigned char));
            if (fs.eof())
                break;
            A = (A + c) % MODUL;
            B = (A + B) % MODUL;
        }
    }
    return (B << 16) + A;
}

uint64_t summ64(string name) {

    uint64_t result = 0;

    std::ifstream  fs(name, std::ios::in | ios::binary);

    while (!fs.eof()) {
        unsigned char c;
        uint64_t tmp = 0;

        for (int i = 0; i < 8; i++) {
            fs.read((char*)&c, sizeof(unsigned char));
            if (fs.eof())
                break;
            tmp = (tmp << 8) | c;
        }

        result += tmp;
    }

    return result;
}


int callAdler32(string fileName) {
    ifstream myfile(fileName);

    if (!myfile) {
        std::cerr << "File failed to open";
        return FILE_ERROR;
    }

    uint32_t result_adler = adler32(fileName);
<<<<<<< HEAD
    std::cout << std::hex<< result_adler;
=======
    std::cout << std::hex << std::setfill('0') << result_adler;
>>>>>>> c740809f3917d2bf5148585d7c634ac29f504b50
    return 0;
}
int callSumm64(string fileName) {
    ifstream myfile(fileName, std::ios::binary);

    if (!myfile) {
        std::cerr << "File failed to open";
        return FILE_ERROR;
    }

    uint64_t result_sum64 = summ64(fileName);
<<<<<<< HEAD
    std::cout << std::hex<< result_sum64;
    return 0;
}

=======
    std::cout << std::hex  << std::setfill('0') << result_sum64;
    return 0;
}

////////////////////////////////////////////////////////////////

>>>>>>> c740809f3917d2bf5148585d7c634ac29f504b50
