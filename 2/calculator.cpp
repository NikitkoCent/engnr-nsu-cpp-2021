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
    int64_t v1 = context.mystack.top();
    context.mystack.pop();
    int64_t v2 = context.mystack.top();
    context.mystack.pop();
    int64_t res;
    SafeAdd(v2, v1, res);
    if (SafeAdd(v2, v1, res) == 0)
        throw FatalErr();
    context.mystack.push(res);
}

void minus::cmd(Context &context, std::vector<std::string> &str) {
    if (context.mystack.size() < 2)
        throw minusexc();
    int64_t v1 = context.mystack.top();
    context.mystack.pop();
    int64_t v2 = context.mystack.top();
    context.mystack.pop();
    int64_t res;
    SafeSubtract(v2, v1, res);
    if (SafeSubtract(v2, v1, res) == 0)
        throw FatalErr();
    context.mystack.push(res);
}

void mul::cmd(Context &context, std::vector<std::string> &str) {
    if (context.mystack.size() < 2)
        throw mulexc();
    int64_t v1 = context.mystack.top();
    context.mystack.pop();
    int64_t v2 = context.mystack.top();
    context.mystack.pop();
    int64_t res;
    SafeMultiply(v2, v1, res);
    if (SafeMultiply(v2, v1, res) == 0)
        throw FatalErr();
    context.mystack.push(res);
}

void divn::cmd(Context &context, std::vector<std::string> &str) {
    if (context.mystack.size() < 2)
        throw divexc();
    int64_t v1 = context.mystack.top();
    context.mystack.pop();
    int64_t v2 = context.mystack.top();
    context.mystack.pop();
    if (v1 == 0) {
        throw DivideByZero();
    }
    int64_t res;
    SafeDivide(v2, v1, res);
    if (SafeDivide(v2, v1, res) == 0)
        throw FatalErr();
    context.mystack.push(res);
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

std::unique_ptr<Command>Cmdcreate::Fmethod(std::vector<std::string> &vec) {
    if (vec[0] == "#") {
        return  std::make_unique<com>();
    } else if (vec[0] == "MUL") {
        return  std::make_unique<mul>();
    } else if (vec[0] == "MINUS") {
        return  std::make_unique<minus>();
    } else if (vec[0] == "PLUS") {
        return  std::make_unique<plus>();
    } else if (vec[0] == "DIV") {
        return  std::make_unique<divn>();
    } else if (vec[0] == "PUSH") {
        return  std::make_unique<push>();
    } else if (vec[0] == "POP") {
        return  std::make_unique<pop>();
    } else if (vec[0] == "PRINT") {
        return  std::make_unique<print>();
    } else if (vec[0] == "PEEK") {
        return  std::make_unique<peek>();
    } else if (vec[0] == "READ") {
        return  std::make_unique<readd>();
    } else if (vec[0] == "ABS") {
        return  std::make_unique<abss>();
    } else
        throw commandexc();

}