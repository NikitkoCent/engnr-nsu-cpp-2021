#include <iostream>
#include <sstream>
#include "calculator.hpp"
#define ERROR 1;
int main(int flag, char *argv[]){
    try{
        std::ifstream fl;
        const char *path;
        std::stringstream input;
        if(flag > 2 || flag ==0)
            return ERROR;
        if (flag == 2){
            path = argv[1];
            fl.open(path);
            if (!fl.is_open()){
                return ERROR;
            }
            else if (fl.peek() ==EOF)
                return 0;
        }
        Preprocessing(input,fl,flag);

    } catch (default_error &e) {
        std::cerr << e.what() << std::endl;
        return ERROR;
    }
    return 0;


}