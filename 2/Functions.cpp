#include "Lab_2.h"

void split(Param &p, const string& s, char delim) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        p.vst.push_back(item);
    }
}

bool strToInteger(Param p) {
    //SafeInt<int64_t, IntOverflow> number = 0;
    try {
        SafeInt<int64_t> number = SafeInt<int64_t>::SafeAtoI(p.vst[1].c_str());
        if (number - number == 0) {
            return true;
        }
    }
    catch (invalid_argument const&) {
        return false;
    }
    return false;
}

bool check(Param s) {
        if (s.vst[0] == "POP") {
            return true;
        }
        else if (s.vst[0] == "PUSH") {
            return true;
        }
        else if (s.vst[0] == "PEEK") {
            return true;
        }
        else if (s.vst[0] == "ABS") {
            return true;
        }
        else if (s.vst[0] == "PLUS") {
            return true;
        }
        else if (s.vst[0] == "MINUS") {
            return true;
        }
        else if (s.vst[0] == "MUL") {
            return true;
        }
        else if (s.vst[0] == "DIV") {
            return true;
        }
        else if (s.vst[0] == "PRINT") {
            return true;
        }
        else if (s.vst[0] == "READ") {
            return true;
        }
    return false;
}

