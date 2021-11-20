//#include "hash.hpp"
//int main()
//{
//
//    while (true)
//    {
//        //cout << "input command : ";
//        string command = "./hasher -h  -m  adler32 test/file";
//        //getline(std::cin, command, '\n');
//
//        remove_twin_spaces(command);
//
//        std::stringstream x;
//        x << command;
//
//        string nextArg = "";
//        string* array = new string[ARG_MAX_SIZE];
//
//        int countarg = 0;
//        x >> nextArg;
//
//        // check space
//        if (eq(" ", command)) {
//            return 1;
//        }
//        // check enter
//        if (eq("", command)) {
//            return 1;
//        }
//        if (!eq("./hasher", nextArg)) {
//            show_err();
//            return 1;
//        }
//        else {
//            while (x >> nextArg)
//            {
//                array[countarg++] = nextArg;
//
//                if (countarg >= ARG_MAX_SIZE) {
//                    show_err();
//                    return 1;
//                }
//            }
//
//
//            // непосредственно проверка параметров
//            if (countarg == 1) {
//                if (eq(array[0], "-h")) {
//                    show_help();
//                    return 0;
//                }
//                else {
//                    show_err();
//                    return 1;
//                }
//            }
//            else if (countarg == 3) {
//                if (eq(array[0], "-m")) {
//                    if (eq(array[1], "adler32")) {
//                        callAdler32(array[2]);
//                        return 0;
//                    }
//                    else if (eq(array[1], "sum64")) {
//                        callSumm64(array[2]);
//                        return 0;
//                    }
//                    else {
//                        show_err();
//                        return 1;
//                    }
//                }
//                else if (eq(array[1], "-m")) {
//                    if (eq(array[2], "adler32")) {
//                        callAdler32(array[0]);
//                        return 0;
//                    }
//                    else if (eq(array[2], "sum64")) {
//                        callSumm64(array[0]);
//                        return 0;
//                    }
//                    else {
//                        show_err();
//                        return 1;
//                    }
//                }
//                else {
//                    show_err();
//                    return 1;
//                }
//            }
//            else {
//                show_err();
//                return 1;
//            }
//        }
//        break;
//    }
//
//}
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#define ARG_MAX_SIZE 4
#define FILE_ERROR -1

using namespace std;

uint32_t adler32(string);
uint64_t summ64(string);
void show_help();
void show_err();
int eq(string , string );
int callAdler32(string );
int callSumm64(string );
void remove_twin_spaces(std::string& );



int main()
{

    while (true)
    {
        //cout << "input command : ";
        string command = "./hasher -h  -m  adler32 test/file";
        //getline(std::cin, command, '\n');

        remove_twin_spaces(command);

        std::stringstream x;
        x << command;

        string nextArg = "";
        string* array = new string[ARG_MAX_SIZE];

        int countarg = 0;
        x >> nextArg;

        // check space
        if (eq(" ", command)) {
            return 1;
        }
        // check enter
        if (eq("", command)) {
            return 1;
        }
        if (!eq("./hasher", nextArg)) {
            show_err();
            return 1;
        }
        else {
            while (x >> nextArg)
            {
                array[countarg++] = nextArg;

                if (countarg >= ARG_MAX_SIZE) {
                    show_err();
                    return 1;
                }
            }


            // непосредственно проверка параметров
            if (countarg == 1) {
                if (eq(array[0], "-h")) {
                    show_help();
                    return 0;
                }
                else {
                    show_err();
                    return 1;
                }
            }
            else if (countarg == 3) {
                if (eq(array[0], "-m")) {
                    if (eq(array[1], "adler32")) {
                        callAdler32(array[2]);
                        return 0;
                    }
                    else if (eq(array[1], "sum64")) {
                        callSumm64(array[2]);
                        return 0;
                    }
                    else {
                        show_err();
                        return 1;
                    }
                }
                else if (eq(array[1], "-m")) {
                    if (eq(array[2], "adler32")) {
                        callAdler32(array[0]);
                        return 0;
                    }
                    else if (eq(array[2], "sum64")) {
                        callSumm64(array[0]);
                        return 0;
                    }
                    else {
                        show_err();
                        return 1;
                    }
                }
                else {
                    show_err();
                    return 1;
                }
            }
            else {
                show_err();
                return 1;
            }
        }
        break;
    }

}

int callAdler32(string fileName) {
    ifstream myfile(fileName);

    if (!myfile) {
        std::cerr << "File failed to open";
        return FILE_ERROR;
    }

    uint32_t result_adler = adler32(fileName);
    std::cout << std::hex << std::setfill('0') << result_adler;
    return 0;
}
int callSumm64(string fileName) {
    ifstream myfile(fileName);

    if (!myfile) {
        std::cerr << "File failed to open";
        return FILE_ERROR;
    }

    uint64_t result_sum64 = summ64(fileName);
    std::cout << std::hex  << std::setfill('0') << result_sum64;
    return 0;
}

////////////////////////////////////////////////////////////////
uint64_t summ64(string name) {

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




////////////////////////////////////////////////////////////////
#define MODUL 65521
uint32_t  adler32(string name) {
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


////////////////////////////////////////////////////////////////
void show_help() {
    cout << "Справочная информация:" << endl;
    cout << "<filename> -m <mode> - посчитать переданный вариант хеша переданного файла;" << endl;
    cout << "-m <mode> <filename> - посчитать переданный вариант хеша переданного файла;" << endl;
    cout << "\tгде\tfilename - имя файла (например, test.txt)" << endl;
    cout << "\t\tmode - название алгоритма Adler32 или sum 64" << endl;
}

void show_err() {
    cerr << "Ошибка, неверно заданы аргументы." << endl;

    cerr << "Справочная информация:" << endl;
    cerr << "<filename> -m <mode> - посчитать переданный вариант хеша переданного файла;" << endl;
    cerr << "-m <mode> <filename> - посчитать переданный вариант хеша переданного файла;" << endl;
    cerr << "\tгде\tfilename - имя файла (например, test.txt)" << endl;
    cerr << "\t\tmode - название алгоритма adler32 или sum 64" << endl;
}

int eq(string first, string str) {
    int result = first == str;
    return result;
}

void remove_twin_spaces(std::string& str)
{
    str.erase(
            std::unique_copy(str.begin(), str.end(), str.begin(),
                             [](char c1, char c2) { return c1 == ' ' && c2 == ' '; }),
            str.end());
}