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

/*
bool strToInteger(Param p) {
    stringstream ss;
    ss << p.vst[1];
    int64_t num = 0;
    ss >> num;
    int k = 1;
    if (ss.good()) {
        k = 1;
    }
    else if (num == 0 && p.vst[1][0] != '0') {
        k = 1;
    }
    else {
        k = 0;
    }
    if (k) {
        try {
            SafeInt<int64_t> number = SafeInt<int64_t>::SafeAtoI(p.vst[1].c_str());
            if (number - number == 0) {
                return true;
            }
        }
        catch (invalid_argument const&) {
            return false;
        }
    }
    return false;
}*/

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

