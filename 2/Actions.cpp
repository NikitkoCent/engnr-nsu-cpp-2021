//
// Created by Mikhail Okan on 15.11.2021.
//

#include "Actions.h"
#include <charconv>
StackActions::Action::Action(std::string &_args) {
    std::string str;
    args = std::istringstream(_args);
    args >> str;
}


bool StackActions::Action::is_number(const std::string &s) {
    return !s.empty() && (std::all_of(s.begin(), s.end(), [](char c) {return ::isdigit(c);}) ||
            (s[0] == '-' && std::all_of(s.begin()+1, s.end(), [](char c) {return ::isdigit(c);})));
}

void StackActions::Push::act(Context &context) {
    std::string value;
    args >> value;
    if (is_number(value)) {
        int64_t result{};
        std::from_chars(value.data(), value.data() + value.size(), result);
        context.st.push(result);
    } else {
        if (context.vars.count(value) == 0) {
            throw StackExceptions::PushException();
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
    std::cout << (int64_t)context.st.top() << std::endl;
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
    SafeInt<int64_t> top = context.st.top(); context.st.pop();
    if (top < 0) top *= -1;
    context.st.push(top);
}

void StackActions::Plus::act(Context &context) {
    if (context.st.size() < 2) {
        throw StackExceptions::StackLack();
    }
    SafeInt<int64_t> b=context.st.top(); context.st.pop(); SafeInt<int64_t> a = context.st.top(); context.st.pop();
    context.st.push(a + b);
}

void StackActions::Minus::act(Context &context) {
    if (context.st.size() < 2) {
        throw StackExceptions::StackLack();
    }
    SafeInt<int64_t> b=context.st.top(); context.st.pop(); SafeInt<int64_t> a = context.st.top(); context.st.pop();
    context.st.push(a - b);
}

void StackActions::Mul::act(Context &context) {
    if (context.st.size() < 2) {
        throw StackExceptions::StackLack();
    }
    SafeInt<int64_t> b=context.st.top(); context.st.pop(); SafeInt<int64_t> a = context.st.top(); context.st.pop();
    context.st.push(a * b);
}

void StackActions::Div::act(Context &context) {
    if (context.st.size() < 2) {
        throw StackExceptions::StackLack();
    }
    SafeInt<int64_t> b=context.st.top(); context.st.pop(); SafeInt<int64_t> a = context.st.top(); context.st.pop();
    if (b == 0) {
        throw StackExceptions::DivisionByZero();
    }
    context.st.push(a / b);
}