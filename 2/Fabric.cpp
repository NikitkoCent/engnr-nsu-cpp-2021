#include "Lab_2.h"
#include "Exceptions.cpp"

class Operations {
public:
    virtual void execute(Param &p) = 0;
    virtual ~Operations() {}
};

class pop_cmd : public Operations {
public:
    void execute(Param &p) {
        if (!p.stk.empty()) {
            p.stk.pop();
        }
        else {
            throw EmptyStack();
        }
    }
};

class push_cmd : public Operations {
public:
    void execute(Param &p) {
        if (strToInteger(p) && p.vst.size() >= 2) {
            p.stk.push(std::stoull(p.vst[1]));
        }
        else {
            if (p.var.count(p.vst[1])) {
                p.stk.push(p.var[p.vst[1]]);
            }
            else {
                throw VarNotFound();
            }                        
        }
    }
};

class peek_cmd : public Operations {
public:
     void execute(Param &p) {
        if (!p.stk.empty() && p.vst.size() >= 2) {
            p.var[p.vst[1]] = p.stk.top();
        }
        else if (p.stk.empty()) {
            throw EmptyStack();
        }
        else {
            throw ArgNotEntered();
        }
    }
};

class abs_cmd : public Operations {
public:
    void execute(Param &p)  {
        int64_t absvar = 0;
        if (!p.stk.empty()) {
            absvar = abs(p.stk.top());
            p.stk.pop();
            p.stk.push(absvar);
        }
        else {
            throw EmptyStack();
        }
    }
};

class plus_cmd : public Operations {
public:
    void execute(Param &p) {
        //int64_t val1 = 0;
        //int64_t val2 = 0;
        if (!p.stk.empty()) {
            SafeInt<int64_t> val1(p.stk.top());
            p.stk.pop();
            if (!p.stk.empty()) {
                SafeInt<int64_t> val2(p.stk.top());
                p.stk.pop();
                p.stk.push(val1+val2);
            }
            else {
                p.stk.push(val1);
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
    void execute(Param &p)  {
        //int64_t val1 = 0;
        //int64_t val2 = 0;
        if (!p.stk.empty()) {

            SafeInt<int64_t,IntOverflow> val1(p.stk.top());
            p.stk.pop();
            if (!p.stk.empty()) {
                SafeInt<int64_t,IntOverflow> val2(p.stk.top());
                p.stk.pop();
                p.stk.push(val1 * val2);
            }
            else {
                p.stk.push(val1);
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
    void execute(Param &p)  {
        //int64_t val1 = 0;
        //int64_t val2 = 0;
        if (!p.stk.empty()) {
            SafeInt<int64_t,IntOverflow> val1(p.stk.top());
            p.stk.pop();
            if (!p.stk.empty()) {
                SafeInt<int64_t,IntOverflow> val2(p.stk.top());
                p.stk.pop();
                p.stk.push(val2 - val1);
            }
            else {
                p.stk.push(val1);
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
    void execute(Param &p)  {
        //int64_t val1 = 0;
        //int64_t val2 = 0;
        if (!p.stk.empty()) {
            SafeInt<int64_t,IntOverflow> val1(p.stk.top());
            p.stk.pop();
            if (!p.stk.empty() && p.stk.top() != 0) {
                SafeInt<int64_t,IntOverflow> val2(p.stk.top());
                p.stk.pop();
                p.stk.push((int64_t)val2/(int64_t)val1);
            }
            else if (p.stk.top() == 0) {
                throw divByZero();
            }
            else {
                p.stk.push(val1);
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
    void execute(Param &p)  {
        if (!p.stk.empty()) {
            cout << p.stk.top() << endl;
        }
        else {
            throw EmptyStack();
        }
    }
};

class  read_cmd : public Operations {
public:
    void execute(Param &p)  {
        int64_t enterval = 0;
        cin >> enterval;
        p.stk.push((SafeInt<int64_t, IntOverflow>) enterval);
    }
};

