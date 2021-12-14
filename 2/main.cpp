#include "command_processing.h"

//int main(int argc, char** argv) {
//
//    printf("Initializing gtest \n");
//    ::testing::InitGoogleTest(&argc, argv);
//
//    return RUN_ALL_TESTS();
//}

int main(int argc, char *argv[]) {
    std::string filepath;
    bool flag = false;

    if (argc > 1) {
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "-help") == 0) {
            return 0;
        }
        if (argc == 2) {
            filepath = argv[1];
        } else {
            return 1;
        }
    } else {
        flag = true;
    }
    std::ifstream file;
    file.open(filepath);
    if (!file.is_open()) {
        return 1;
    } else if (file.peek() == EOF) {
        return 0;
    }
    command_processing(file, argc);
    return 0;
}
