#include "command_processing.h"

//int main(int argc, char** argv) {
//
//    printf("Initializing gtest \n");
//    ::testing::InitGoogleTest(&argc, argv);
//
//    return RUN_ALL_TESTS();
//}

int main(int argc, char *argv[]) {
    const char *first_path = argv[1];
//    argc = 2;
//    const char *first_path = "input.txt";
    std::ifstream in;
    in.open(first_path);
    if(!in.is_open())
        return 1;
    freopen(first_path, "r", stdin);
    command_processing(in, argc);
    return 0;
}
