#include "command_processing.h"

int main(int argc, char *argv[]) {
    try {
        std::ifstream file;
        const char *filepath;
        std::stringstream in_s;
        if (argc > 2 || argc == 0)
            return 1;
        if (argc == 2) {
            filepath = argv[1];
            file.open(filepath);
            if (!file.is_open())
                return 1;
            else if (file.peek() == EOF)
                return 0;
        }
        command_processing(in_s, file, argc);
    } catch (StackException &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
