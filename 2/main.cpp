#include "command_processing.h"

//int main(int argc, char** argv) {
//
//    printf("Initializing gtest \n");
//    ::testing::InitGoogleTest(&argc, argv);
//
//    return RUN_ALL_TESTS();
//}

int main(int argc, char *argv[]) {
    std::string first_path;
    if(argc == 2)
        first_path = argv[1];
    argc = 1;
    std::ifstream file;
    file.open(first_path);
    if (!file.is_open()) {
        return 1;
    } else if (file.peek() == EOF) {
        return 0;
    }
    command_processing(file, argc);
    return 0;
}

