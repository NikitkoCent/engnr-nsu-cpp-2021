//
// Created by Mikhail Okan on 15.11.2021.
//

#include "Actions.h"

StackActions::Action::Action(std::string &_args) {
    std::string str;
    args = std::istringstream(_args);
    args >> str;
}

bool StackActions::Action::is_number(const std::string &line) {
    // stupid but simple way to check if input is num or var :)
    // in real project it will be better to iterate through all chars and check them in '0' <= c <= '9'
    try {
        std::stol(line);
        return true;
    }
    catch (const std::invalid_argument &err) {
        return false;
    }
}

SafeInt<long> StackActions::ArithmeticAction::pop(std::stack<SafeInt<long>> &st) {
    SafeInt<long> val = st.top();
    st.pop();
    return val;
}

void StackActions::Push::act(Context &context) {
    std::string value;
    args >> value;
    if (is_number(value)) {
        context.st.push(std::stol(value));
    } else {
        if (context.vars.count(value) == 0) {
            throw StackExceptions::PushException(value);
        }
        context.st.push(context.vars[value]);
    }
}

void StackActions::Pop::act(Context &context) {
    if (context.st.empty()) {
        throw StackExceptions::StackEmpty();
    }
    context.st.pop();
}

void StackActions::Peek::act(Context &context)  {
    std::string value;
    args >> value;
    if (context.st.empty()) {
        throw StackExceptions::StackEmpty();
    }
    context.vars[value] = context.st.top();
}

void StackActions::Print::act(Context &context)  {
    if (context.st.empty()) {
        throw StackExceptions::StackEmpty();
    }
    context.vars["0x0badc0de"] = context.st.top();
    std::cout << (long)context.st.top() << std::endl;
}

void StackActions::Read::act(Context &context) {
    std::string value;
    std::cin >> value;
    if (!is_number(value)) {
        throw StackExceptions::ReadException();
    }
    context.st.push(std::stol(value));
}

void StackActions::Abs::act(Context &context) {
    if (context.st.empty()) {
        throw StackExceptions::StackEmpty();
    }
    context.st.push(context.st.top() * (pop(context.st) > 0 ? 1 : -1));
}

void StackActions::Plus::act(Context &context) {
    if (context.st.size() < 2) {
        throw StackExceptions::StackLack(context.st.size());
    }
    SafeInt<long> b=context.st.top(); context.st.pop(); SafeInt<long> a = context.st.top(); context.st.pop();
    try {
        context.st.push(a + b);
    }
    catch (SafeIntException &err){
        throw StackExceptions::OverflowException((long)a, "+", (long)b);
    }
}

void StackActions::Minus::act(Context &context) {
    if (context.st.size() < 2) {
        throw StackExceptions::StackLack(context.st.size());
    }
    SafeInt<long> b=context.st.top(); context.st.pop(); SafeInt<long> a = context.st.top(); context.st.pop();
    try {
        context.st.push(a - b);
    }
    catch (SafeIntException &err){
        throw StackExceptions::OverflowException((long)a, "-", (long)b);
    }
}

void StackActions::Mul::act(Context &context) {
    if (context.st.size() < 2) {
        throw StackExceptions::StackLack(context.st.size());
    }
    SafeInt<long> b=context.st.top(); context.st.pop(); SafeInt<long> a = context.st.top(); context.st.pop();
    try {
        context.st.push(a * b);
    }
    catch (SafeIntException &err){
        throw StackExceptions::OverflowException((long)a, "*", (long)b);
    }
}

void StackActions::Div::act(Context &context) {
    if (context.st.size() < 2) {
        throw StackExceptions::StackLack(context.st.size());
    }
    SafeInt<long> b=context.st.top(); context.st.pop(); SafeInt<long> a = context.st.top(); context.st.pop();
    if (b == 0) {
        throw StackExceptions::DivisionByZero();
    }
    context.st.push(a / b);
}