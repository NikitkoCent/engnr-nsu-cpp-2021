#include "Lab_2.h"

void split(Param &p, const string& s, char delim) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        p.vst.push_back(item);
    }
}

bool integer_check(Param& s) {
    stringstream ss;
    ss << s.vst[1];
    int64_t num = 0;
    ss >> num;
    if (ss.good()) {
        return false;
    }
    else if (num == 0 && s.vst[1][0] != '0') {
        return false;
    }
    else {
        return true;
    }
    return true;
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

