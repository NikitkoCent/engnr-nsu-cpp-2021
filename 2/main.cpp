#include "command_processing.h"

//int main(int argc, char** argv) {
//
//    printf("Initializing gtest \n");
//    ::testing::InitGoogleTest(&argc, argv);
//
//    return RUN_ALL_TESTS();
//}

int main(int argc, char *argv[]) {
//    argc = 0;
    std::string first_path = argv[1];
    std::ifstream in;
//    const char *first_path = "input.txt";
    if(argc > 1) {
        if(argc == 2)
            first_path = argv[1];
        else
            return 1;
    } else {
        in.open(first_path);
        if (!in.is_open()) {
            return 1;
        }
    }
    command_processing(in, argc);
    return 0;
}
