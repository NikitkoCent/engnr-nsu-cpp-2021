#include "hash.hpp"
int main()
{
    while (true)
    {
        string command = "./hasher  -m  adler32 test/file";
        getline(std::cin, command, '\n');
        remove_twin_spaces(command);
        std::stringstream x;
        x << command;

        string nextArg = "";
        string* array = new string[ARG_MAX_SIZE];

        int countarg = 0;
        x >> nextArg;

        // check space
        if (eq(" ", command)) {
            show_err();
            return 1;
        }
        // check enter
        if (eq("", command)) {
            show_err();
            return 1;
        }
        if (!eq("./hasher", nextArg)) {
            show_err();
            return 0;
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
            if (countarg == 2) {
                show_err();
                return 1;
            }
            else if (countarg == 3) {
                if (eq(array[0], "-m")) {
                    if (eq(array[1], "adler32")) {
                        callAdler32(array[2]);
                    }
                    else if (eq(array[1], "sum64")) {
                        callSumm64(array[2]);
                    }
                    else {
                        show_err();
                        return 1;
                    }
                }
                else if (eq(array[1], "-m")) {
                    if (eq(array[2], "adler32")) {
                        callAdler32(array[0]);
                    }
                    else if (eq(array[2], "sum64")) {
                        callSumm64(array[0]);
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