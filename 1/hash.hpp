#pragma once
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
class ArgHelper {
public:
    bool error;
    bool h;
    bool mode;
    std::string path = "";
    Algo algo = Algo::null;

    ArgHelper();
    bool isHelp();
    bool isMode();
};

int eq(std::string first, std::string str);
ArgHelper getArg(int argc, char* argv[]);
void show_help();
void show_err();
uint64_t summ64(std::fstream &fs);
uint64_t  adler32(std::fstream &fs);
int call(std::fstream &fs, uint64_t(*func)(std::fstream &), uint64_t& result);





