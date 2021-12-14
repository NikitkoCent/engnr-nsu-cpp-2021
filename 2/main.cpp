#include "command_processing.h"

//int main(int argc, char** argv) {
//
//    printf("Initializing gtest \n");
//    ::testing::InitGoogleTest(&argc, argv);
//
//    return RUN_ALL_TESTS();
//}

int main(int argc, char* argv[]) {
    argc = 0;
    const char *first_path = argv[1];
    const char *second_path = argv[2];
    if(argc > 1) {
        freopen(first_path, "r", stdin);
        freopen(second_path, "w", stdout);
    }
    std::ifstream in(first_path);
    std::ofstream out(second_path);
    command_processing(in, out, argc);
    return 0;
}

