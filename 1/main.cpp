#include <iostream>
#include <iterator>
//#include <boost/program_options.hpp>
#include <exception>
#include <string>
#include <map>

#include "HashCalc.h"

using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::string;
using std::ifstream;
using std::runtime_error;
using std::map;


map<string, string> parse_args(int ac, char** av){
    map<string, string> m;
    m["help"] = "0";
    m["mode"] = "";
    m["filename"] = "";
    for (int i = 0; i < ac; i++){
        if (strcmp(av[i], "-h") == 0){
            m["help"] = "1";
            return m;
        } else if (strcmp(av[i], "-m") == 0){
            m["mode"] = string(av[i + 1]);
            i++;
        } else {
            m["filename"] = string(av[i]);
        }
    }
    return m;
}

int main(int ac, char** av){
    string filename, mode;
    ifstream file;
//    po::options_description desc("Варианты запуска программы");
    string desc = "Варианты запуска программы:\n"
                  "\t-h - вывести help\n"
                  "\t<filename> -m <mode> - запуск по имени файла и режиму (adler32, sum64)\n"
                  "\t-m <mode> <filename>\n";
    try {
        map<string, string> args = parse_args(ac, av);

        if (args["help"] == "1" || args["mode"] == "" || args["filename"] == "") {
            cout << desc << "\n";
            return 0;
        }
        mode = args["mode"];
        filename = args["filename"];

//        cout << "file name: [" << filename << "]" << endl;
//        cout << "mode: [" << mode << "]" << endl;

        if (mode != "adler32" && mode != "sum64")
            throw runtime_error("Mode should be adler32 or sum64");

        file.open(filename, std::ios::binary);

        if (!file.is_open())
            throw runtime_error("File not found!");

        if (mode == "adler32"){
            uint32_t hash = HashCalc::adler32(file);

            cout << "Hash: 0x" << std::hex << hash << "\n";
        } else {
            uint64_t hash = HashCalc::sum64(file);

            cout << "Hash: 0x" << std::hex << hash << "\n";
        }

    } catch(exception& e) {
        cerr << "error: " << e.what() << "\n";
        cerr << "help: " << desc << "\n";
        return 1;
    } catch(...) {
        cerr << "Exception of unknown type!\n";
        return 1;
    }
    return 0;
}