#include "Lab_2.h"
#include "Fabric.h"

class Factory {
public:
    virtual Operations* Create(Param s) = 0;
    virtual ~Factory() {}
};

class OperationsFactory: public Factory {
public:
    Operations* Create(Param s) {
        if (s.vst[0] == "POP") {
            return new pop_cmd();
        }
        else if (s.vst[0] == "PUSH") {
            return new push_cmd();
        }
        else if (s.vst[0] == "PEEK") {
            return new peek_cmd();
        }
        else if (s.vst[0] == "ABS") {
            return new abs_cmd();
        }
        else if (s.vst[0] == "PLUS") {
            return new plus_cmd();
        }
        else if (s.vst[0] == "MINUS") {
            return new minus_cmd();
        }
        else if (s.vst[0] == "MUL") {
            return new mul_cmd();
        }
        else if (s.vst[0] == "DIV") {
            return new div_cmd();
        }
        else if (s.vst[0] == "PRINT") {
            return new print_cmd();
        }
        else if (s.vst[0] == "READ") {
            return new read_cmd();
        }
        else {
            return nullptr;
        }
    }
};

