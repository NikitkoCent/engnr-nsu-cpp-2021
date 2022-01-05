#include "calculator.hpp"

bool is_number(const std::string &s) {
    return !s.empty() && (std::all_of(s.begin(), s.end(), [](char c) { return ::isdigit(c); }) ||
                          (s[0] == '-' && std::all_of(s.begin() + 1, s.end(), [](char c) { return ::isdigit(c); })));
}

void pop::cmd(Context &context, std::vector<std::string> &str) {
    if (!context.mystack.empty()) {
        context.mystack.pop();
    } else
        throw popexc();
}

void push::cmd(Context &context, std::vector<std::string> &str) {
    if (str.size() < 2)
        throw noargsexc();
    try {
        if (is_number(str[1])) {
            context.mystack.push(std::stoll(str[1]));
        } else if (!is_number(str[1])) {
            context.mystack.push(context.mp[str[1]]);
        }
    }  catch (...) {
        throw pushexc();
    }
}

void plus::cmd(Context &context, std::vector<std::string> &str) {
    if (context.mystack.size() < 2)
        throw plusexc();
    try {
        int64_t v1 = context.mystack.top();
        context.mystack.pop();
        int64_t v2 = context.mystack.top();
        context.mystack.pop();
        int64_t res;
        if (v2+v1 != (long long int)v2+(long long int) v1){
            throw FatalErr();
        }
        SafeAdd(v2, v1, res);
        context.mystack.push(res);
    }catch(...){
        throw FatalErr();
    }
}

void minus::cmd(Context &context, std::vector<std::string> &str) {
    if (context.mystack.size() < 2)
        throw minusexc();
    try {
        int64_t v1 = context.mystack.top();
        context.mystack.pop();
        int64_t v2 = context.mystack.top();
        context.mystack.pop();
        int64_t res;
        if (v2-v1 != (long long int)v2-(long long int) v1){
            throw FatalErr();
        }
        SafeSubtract(v2, v1, res);
        context.mystack.push(res);
    }catch(...){
        throw FatalErr();
    }
}

void mul::cmd(Context &context, std::vector<std::string> &str) {
    if (context.mystack.size() < 2)
        throw mulexc();
    try {
        int64_t v1 = context.mystack.top();
        context.mystack.pop();
        int64_t v2 = context.mystack.top();
        context.mystack.pop();
        int64_t res;
        if (v2*v1 != (long long int)v2*(long long int) v1){
            throw FatalErr();
        }
        SafeMultiply(v2, v1, res);
        context.mystack.push(res);
    }catch(...){
        throw FatalErr();
    }
}

void divn::cmd(Context &context, std::vector<std::string> &str) {
    if (context.mystack.size() < 2)
        throw divexc();
    try {
        int64_t v1 = context.mystack.top();
        context.mystack.pop();
        int64_t v2 = context.mystack.top();
        context.mystack.pop();
        if (v1 == 0) {
            throw DivideByZero();
        }
        int64_t res;
        if (v2/v1 != (long long int)v2/(long long int) v1){
            throw FatalErr();
        }
        SafeDivide(v2, v1, res);
        context.mystack.push(res);
    }catch(...){
        throw FatalErr();
    }
}

void print::cmd(Context &context, std::vector<std::string> &str) {
    if (str.size() > 1)
        throw manyargsexc();
    if (!context.mystack.empty()) {
        std::cout << (int64_t) context.mystack.top() << std::endl;
    } else
        throw printexc();
}

void peek::cmd(Context &context, std::vector<std::string> &str) {
    if (context.mystack.empty() || str.size() < 2) {
        throw peekexc();
    } else
        context.mp[str[1]] = context.mystack.top();
}

void abss::cmd(Context &context, std::vector<std::string> &str) {
    try {
        if (!context.mystack.empty() && str.size() == 1) {
            SafeInt<int64_t> val = context.mystack.top();
            context.mystack.pop();
            val = val > 0 ? val : -val;
            context.mystack.push(val);
        } else
            throw absexc();
    }catch(...){
        throw FatalErr();
    }
}

void readd::cmd(Context &context, std::vector<std::string> &str) {
    if (str.size() < 2)
        throw noargsexc();
    try {
        context.mystack.push(std::stoll(str[1]));
    } catch (...) {
        throw readexc();
    }
}

void com::cmd(Context &context, std::vector<std::string> &str) {
//     (0_0)
//    --=|=--
//     _/ \_

}

Command *Cmdcreate::Fmethod(std::vector<std::string> &vec) {
    if (vec[0] == "#") {
        return new com();
    } else if (vec[0] == "MUL") {
        return new mul();
    } else if (vec[0] == "MINUS") {
        return new minus();
    } else if (vec[0] == "PLUS") {
        return new plus();
    } else if (vec[0] == "DIV") {
        return new divn();
    } else if (vec[0] == "PUSH") {
        return new push();
    } else if (vec[0] == "POP") {
        return new pop();
    } else if (vec[0] == "PRINT") {
        return new print();
    } else if (vec[0] == "PEEK") {
        return new peek();
    } else if (vec[0] == "READ") {
        return new readd();
    } else if (vec[0] == "ABS") {
        return new abss();
    } else
        throw commandexc();

}