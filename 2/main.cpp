#include "command_processing.h"

//int main(int argc, char** argv) {
//
//    printf("Initializing gtest \n");
//    ::testing::InitGoogleTest(&argc, argv);
//
//    return RUN_ALL_TESTS();
//}

int main() {
    std::ifstream in;
    in.open("input.txt");

    std::ofstream out;
    out.open("output.txt");
    command_processing(in, out);
    in.close();
    out.close();
    return 0;
}

