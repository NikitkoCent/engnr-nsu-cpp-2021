#include "Lab_2.h"

void split(vector<string>& result, const string& s, char delim) {
    //   vector<string> result;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        result.push_back(item);
    }
}

bool strToInteger(const string& s) {
    try {
        int number = std::stod(s);
        return true;
    }
    catch (invalid_argument const& s) {
        return false;
        //        std::cout << "Input value is not a number"<<endl;
    }
    return false;
}
void stack_case(const vector<string>& s, stack<double>& str, map<string, double>& mp) {
    double val1 = 0;
    double val2 = 0;
    double absvar = 0;
    double enterval = 0;
    if (s[0] == "POP") {
        if (!str.empty()) {
            cout << str.top() << endl;
            str.pop();

        }
        else {
            cout << "Empty stack" << endl;
        }
    }
    else if (s[0] == "PUSH") {
        strToInteger(s[1]);
        if (strToInteger(s[1])) {
            str.push(std::stod(s[1]));
            cout << s[1] << endl;
        }
        else {
            try {
                str.push(mp[s[1]]);
                cout << mp[s[1]] << endl;
            }
            catch (...) {
                cout << "No such variable" << endl;
            }

        }
    }
    else if (s[0] == "PEEK") {
        if (!str.empty() && s.size() >= 2) {
            mp[s[1]] = str.top();
        }
        else if (str.empty()) {
            cout << "Empty stack" << endl;
        }
        else {
            cout << "Argument not found" << endl;
        }
    }
    else if (s[0] == "ABS") {
        if (!str.empty()) {
            absvar = abs(str.top());
            str.pop();
            str.push(absvar);
        }
        else {
            cout << "Empty stack" << endl;
        }
    }
    else if (s[0] == "PLUS") {
        if (!str.empty()) {
            val1 = str.top();
            str.pop();
            if (!str.empty()) {
                val2 = str.top();
                str.pop();
                str.push(val1 + val2);
            }
            else {
                str.push(val1);
                cout << "Only 1 argument" << endl;
            }
        }
        else {
            cout << "Empty stack" << endl;
        }
    }
    else if (s[0] == "MINUS") {
        if (!str.empty()) {
            val1 = str.top();
            str.pop();
            if (!str.empty()) {
                val2 = str.top();
                str.pop();
                str.push(val2 - val1);
            }
            else {
                str.push(val1);
                cout << "Only 1 argument" << endl;
            }
        }
        else {
            cout << "Empty stack" << endl;
        }
    }
    else if (s[0] == "MUL") {
        if (!str.empty()) {
            val1 = str.top();
            str.pop();
            if (!str.empty()) {
                val2 = str.top();
                str.pop();
                str.push(val1 * val2);
            }
            else {
                str.push(val1);
                cout << "Only 1 argument" << endl;
            }
        }
        else {
            cout << "Empty stack" << endl;
        }
    }
    else if (s[0] == "DIV") {
        if (!str.empty()) {
            val1 = str.top();
            str.pop();
            if (!str.empty() && str.top() != 0) {
                val2 = str.top();
                str.pop();
                str.push(val2 / val1);
            }
            else if (str.top() == 0) {
                cout << "Division by 0" << endl;
            }
            else {
                str.push(val1);
                cout << "Only 1 argument" << endl;
            }
        }
        else {
            cout << "Empty stack" << endl;
        }
    }
    else if (s[0] == "PRINT") {
        if (!str.empty()) {
            cout << str.top() << endl;
        }
        else {
            cout << "Stack is empty" << endl;
        }
    }
    else if (s[0] == "READ") {
        cin >> enterval;
        str.push(enterval);
    }

}
