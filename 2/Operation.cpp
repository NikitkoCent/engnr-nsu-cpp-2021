#include "Lab_2.h"
#include "Fabric.cpp"


class Factory {
public:
    virtual Operations* Create(const vector<string>& s) = 0;
    virtual ~Factory() {}
};

class OperationsFactory: public Factory {
public:
    Operations* Create(const vector<string>& s) {
        if (s[0] == "POP") {
            return new pop_cmd();
        }
        else if (s[0] == "PUSH") {
            return new push_cmd();
        }
        else if (s[0] == "PEEK") {
            return new peek_cmd();
        }
        else if (s[0] == "ABS") {
            return new abs_cmd();
        }
        else if (s[0] == "PLUS") {
            return new plus_cmd();
        }
        else if (s[0] == "MINUS") {
            return new minus_cmd();
        }
        else if (s[0] == "MUL") {
            return new mul_cmd();
        }
        else if (s[0] == "DIV") {
            return new div_cmd();
        }
        else if (s[0] == "PRINT") {
            return new print_cmd();
        }
        else if (s[0] == "READ") {
            return new read_cmd();
        }
        else {
            return nullptr;
        }
    }
};
