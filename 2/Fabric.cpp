#include "Lab_2.h"
#include "Exceptions.cpp"


class Operations {
public:
    virtual void execute(const vector<string>& s, stack<int64_t>& str, map<string, int64_t>& mp) = 0;
    virtual ~Operations() {}
};

class pop_cmd : public Operations {
public:
    void execute(const vector<string>&, stack<int64_t>& str, map<string, int64_t>&) {
        if (!str.empty()) {
            str.pop();
        }
        else {
            throw EmptyStack();
        }
    }
};

class push_cmd : public Operations {
public:
    void execute(const vector<string>& s, stack<int64_t>& str, map<string, int64_t>& mp) {
        if (strToInteger(s[1]) && s.size() >= 2) {
            str.push(std::stoull(s[1]));
        }
        else {
            if (mp.count(s[1])) {
                str.push(mp[s[1]]);
            }
            else {
                throw VarNotFound();
            }                        
        }
    }
};

class peek_cmd : public Operations {
public:
     void execute(const vector<string>& s, stack<int64_t>& str, map<string, int64_t>& mp) {
        if (!str.empty() && s.size() >= 2) {
            mp[s[1]] = str.top();
        }
        else if (str.empty()) {
            throw EmptyStack();
        }
        else {
            throw ArgNotEntered();
        }
    }
};

class abs_cmd : public Operations {
public:
    void execute(const vector<string>& , stack<int64_t>& str, map<string, int64_t>& )  {
        int64_t absvar = 0;
        if (!str.empty()) {
            absvar = abs(str.top());
            str.pop();
            str.push(absvar);
        }
        else {
            throw EmptyStack();
        }
    }
};

class plus_cmd : public Operations {
public:
    void execute(const vector<string>& , stack<int64_t>& str, map<string, int64_t>& ) {
        int64_t val1 = 0;
        int64_t val2 = 0;
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
                throw OneArgumentStack();
            }
        }
        else {
            throw EmptyStack();
        }
    }
};

class  mul_cmd : public Operations {
public:
    void execute(const vector<string>& , stack<int64_t>& str, map<string, int64_t>& )  {
        int64_t val1 = 0;
        int64_t val2 = 0;
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
                throw OneArgumentStack();
            }
        }
        else {
            throw EmptyStack();
        }
    }
};

class  minus_cmd : public Operations {
public:
    void execute(const vector<string>& , stack<int64_t>& str, map<string, int64_t>& )  {
        int64_t val1 = 0;
        int64_t val2 = 0;
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
                throw OneArgumentStack();
            }
        }
        else {
            throw EmptyStack();
        }
    }
};

class  div_cmd : public Operations {
public:
    void execute(const vector<string>& , stack<int64_t>& str, map<string, int64_t>& )  {
        int64_t val1 = 0;
        int64_t val2 = 0;
        if (!str.empty()) {
            val1 = str.top();
            str.pop();
            if (!str.empty() && str.top() != 0) {
                val2 = str.top();
                str.pop();
                str.push(val2 / val1);
            }
            else if (str.top() == 0) {
                throw divByZero();
            }
            else {
                str.push(val1);
                throw OneArgumentStack();
            }
        }
        else {
            throw EmptyStack();
        }
    }
};

class  print_cmd : public Operations {
public:
    void execute(const vector<string>& , stack<int64_t>& str, map<string, int64_t>& )  {
        if (!str.empty()) {
            cout << str.top() << endl;
        }
        else {
            throw EmptyStack();
        }
    }
};

class  read_cmd : public Operations {
public:
    void execute(const vector<string>& , stack<int64_t>& str, map<string, int64_t>& )  {
        int64_t enterval = 0;
        cin >> enterval;
        str.push(enterval);
    }
};

