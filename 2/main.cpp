#include "command_processing.h"

//int main(int argc, char** argv) {
//
//    printf("Initializing gtest \n");
//    ::testing::InitGoogleTest(&argc, argv);
//
//    return RUN_ALL_TESTS();
//}

int main(int argc, char** argv) {
    if(argc > 1) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");
    command_processing(in, out, argc);
    return 0;
}

