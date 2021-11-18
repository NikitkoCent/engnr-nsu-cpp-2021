#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <bitset>
#include <iterator>
#include <algorithm>
#define ARG_MAX_SIZE 5
#define FILE_ERROR 1
#define MODUL 65521
using namespace std;


uint64_t summ64(const string &name) {

    uint64_t result = 0;

    std::fstream fs(name);

    while (true) {
        char buff[8 + 1]{ 0 };
        fs.read(buff, 8);
        uint64_t tmp = 0;
        int zerosCount = 0;

        for (int i = 0; i < 8; i++) {
            char c = buff[i];
            if (c == 0)
                zerosCount++;
            else
                zerosCount = 0;
            tmp |= (uint64_t)(unsigned char)c << (7 - i) * 8;
        }

        if (zerosCount > 0)
            tmp = tmp >> zerosCount * 8;

        result += tmp;

        if (fs.eof())
            break;
    }

    return result;
}
uint32_t  adler32(const string &name) {
    uint16_t A = 1;
    uint16_t B = 0;
    char byte;

    std::fstream fs(name, std::ios::in | std::ios::binary);

    if (fs.is_open()) {
        while (true) {
            fs.read(&byte, sizeof(char));
            if (fs.eof())
                break;
            A = (A + (unsigned char)byte) % MODUL;
            B = (A + B) % MODUL;
        }
    }

    return (B << 16) + A;
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

int eq(const string &first, const string &str) {
    int result = first == str;
    return result;
}
int callAdler32(const string &fileName) {
    ifstream myfile(fileName);

    if (!myfile) {
        std::cerr << "File failed to open";
        return FILE_ERROR;
    }

    uint32_t result_adler = adler32(fileName);
    std::cout << std::hex << std::setfill('0') << result_adler;
    return 0;
}
int callSumm64(const string &fileName) {
    ifstream myfile(fileName);

    if (!myfile) {
        std::cerr << "File failed to open";
        return FILE_ERROR;
    }

    uint64_t result_sum64 = summ64(fileName);
    std::cout << std::hex  << std::setfill('0') << result_sum64;
    return 0;
}
void remove_twin_spaces(std::string& str)
{
    str.erase(
            std::unique_copy(str.begin(), str.end(), str.begin(),
                             [](char c1, char c2) { return c1 == ' ' && c2 == ' '; }),
            str.end());
}
