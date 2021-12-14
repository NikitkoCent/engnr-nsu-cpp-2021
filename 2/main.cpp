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
    const char *first_path = argv[1];
//    const char *first_path = "input.txt";
    if(argc > 1) {
        freopen(first_path, "r", stdin);
    }
    std::ifstream in(first_path);
    command_processing(in, argc);
    return 0;
}
