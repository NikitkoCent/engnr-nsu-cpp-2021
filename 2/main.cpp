#include "command_processing.h"

//int main(int argc, char** argv) {
//
//    printf("Initializing gtest \n");
//    ::testing::InitGoogleTest(&argc, argv);
//
//    return RUN_ALL_TESTS();
//}

int main(int argc, char *argv[]) {
    const char *filepath;
    std::ifstream file;
    if(argc > 2 && argc == 0)
        return 1;
    if(argc == 2) {
        filepath = argv[1];
//        filepath = "input.txt";
        file.open(filepath);
        if(!file.is_open())
            return 1;
        else if(file.peek() == EOF)
            return 0;
    }
    command_processing(file, argc);

    return 0;
}
