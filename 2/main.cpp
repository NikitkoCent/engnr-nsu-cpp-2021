#include "command_processing.h"

//int main(int argc, char** argv) {
//
//    printf("Initializing gtest \n");
//    ::testing::InitGoogleTest(&argc, argv);
//
//    return RUN_ALL_TESTS();
//}

int main() {
    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);
    command_processing();
    return 0;
}

