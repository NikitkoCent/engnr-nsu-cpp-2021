#include <iostream>
#include <fstream>

#include "../commands/Command.h"
#include "../commands/Exceptions.h"

using namespace std;




int main(int argc, char **argv) {
    string help = "Usage: ./Calculator <filepath?>\n"
                  "Available commands: #, POP, PUSH <number>, PUSH <varname>, PEEK <varname>, ABS, PLUS, MINUS, MUL, DIV, PRINT, READ.";
    if (argc > 2) {
        cerr << "HELP";
        return 1;
    }

    if (argc == 2) {
        string filename = argv[1];
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "File not found!" << endl << help;
            return 1;

        }
        try {
            Context context(cout);
            parse_stream(file, context);
        } catch (const BaseException &e) {
            std::cerr << e.what() << std::endl;
            return 1;
        } catch (SafeIntException &e) {
            return 1;
        } catch (std::runtime_error &e) {
            std::cerr << e.what() << std::endl;
            return 1;
        }

    }

    try {
        Context context(cout);
        parse_stream(cin, context);
    } catch (const BaseException &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (SafeIntException &e) {
        return 1;
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}

