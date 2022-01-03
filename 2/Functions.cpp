#include "Lab_2.h"
#include "Fabric.cpp"
void split(vector<string>& result, const string& s, char delim) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        result.push_back(item);
    }
}

bool strToInteger(const string& s) {
    int64_t number = 0;
    try {
        number = std::stoull(s);
        if (number - number == 0){
            return true;
        }
    }
    catch (invalid_argument const& ) {
        return false;
    }
    return false;
}

bool check(const vector<string>& s) {
        if (s[0] == "POP") {
            return true;
        }
        else if (s[0] == "PUSH") {
            return true;
        }
        else if (s[0] == "PEEK") {
            return true;
        }
        else if (s[0] == "ABS") {
            return true;
        }
        else if (s[0] == "PLUS") {
            return true;
        }
        else if (s[0] == "MINUS") {
            return true;
        }
        else if (s[0] == "MUL") {
            return true;
        }
        else if (s[0] == "DIV") {
            return true;
        }
        else if (s[0] == "PRINT") {
            return true;
        }
        else if (s[0] == "READ") {
            return true;
        }
    return false;
}
