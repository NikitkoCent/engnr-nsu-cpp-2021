#include "hash.hpp"

ArgHelper getArg(int argc, char* argv[]) {
    ArgHelper argHelper;

    if (argc == 2 && eq(argv[1], "-h")) {
        argHelper.h = true;
    }
    else if (argc == 4 && eq(argv[1], "-m")) {
        argHelper.mode = true;
        if (eq(argv[2], "adler32"))
            argHelper.algo = Algo::ADLER32;
        else if (eq(argv[2], "sum64"))
            argHelper.algo = Algo::SUM64;
        else {
            argHelper.error = true;
        }
        argHelper.path = argv[3];
    }
    else if (argc == 4 && eq(argv[2], "-m")) {
        argHelper.mode = true;
        if (eq(argv[3], "adler32"))
            argHelper.algo = Algo::ADLER32;
        else if (eq(argv[3], "sum64"))
            argHelper.algo = Algo::SUM64;
        else {
            argHelper.error = true;
        }
        argHelper.path = argv[1];
    }
    else
        argHelper.error = true;

    return argHelper;
}
void show_program_help(std::ostream& os) {
    os << "Background information:" << std::endl;
    os << "<filename> -m <mode> - calculate the transmitted version of the hash of the transmitted file;" << std::endl;
    os << "-m <mode> <filename> - calculate the transmitted version of the hash of the transmitted file;" << std::endl;
    os << "\twhere\tfilename - file name (for example, test.txt )" << std::endl;
    os << "\t\tmode - the name of the algorithm is Adler32 or sum 64" << std::endl;

}
void show_help() {
    show_program_help(std::cout);

}
void show_err() {
    std::cerr << "Error, arguments are incorrectly set." << std::endl;
    show_program_help(std::cerr);
}

uint64_t summ64(std::fstream &fs) {
    uint64_t result = 0;

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

uint64_t  adler32(std::fstream &fs) {
    uint16_t A = 1;
    uint16_t B = 0;

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
int call(std::fstream &fs, uint64_t(*func)(std::fstream &), uint64_t& result){

    if (!fs) {
        std::cerr << "File failed to open";
        return FILE_ERROR;
    }
    try {
        result = func(fs);
    }
    catch (...) {
        std::cerr << "ALGO error";
        return ALGO_ERROR;
    }
    return 0;
}