#include "hash.hpp"
int main(int argc, char* argv[])
{
    ArgHelper* arg = getArg(argc, argv);
    if (arg == NULL) {
        show_err();
        return -1;
    }
    if (arg->isHelp()) {
        show_help();
        return 0;
    }
    if (arg->isMode()) {
        if (arg->algo == Algo::ADLER32) {
            callAdler32(arg->path); cout << endl;
        }else if (arg->algo == Algo::SUM64) {
            callSumm64(arg->path); cout << endl;
        }
        else
            return ALGO_ERROR;
    }
}