#include "hash.cpp"
int main(int argc, char* argv[])
{
    ArgHelper arg = getArg(argc, argv);
    if (arg.error) {
        show_err();
        return -1;
    }
    if (arg.isHelp()) {
        show_help();
        return 0;
    }
    if (arg.isMode()) {
        uint64_t result;
        std::fstream fs(arg.path, std::ios::in | std::ios::binary);

        if (arg.algo == Algo::ADLER32) {
            if ((call(fs, adler32, result)) == 0)
                std::cout << std::hex<< result;
            else
                return ALGO_ERROR;

        }else if (arg.algo == Algo::SUM64) {
            if(! (call(fs, summ64, result)))
                std::cout << std::hex<< result;
            else
                return ALGO_ERROR;
        }
        else
            return ALGO_ERROR;
    }
}