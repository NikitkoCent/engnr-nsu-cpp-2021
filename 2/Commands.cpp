//
// Created by gav on 22/12/2021.
//

#include "Commands.h"

#include <charconv>

bool Push::is_number(const std::string &line) {
    char *p;
    strtol(line.c_str(), &p, 10);
    return *p == 0;
}

void Push::exec(StackCalculatorContext &ctx) {
    string varname;
    args >> varname;
    if (is_number(varname)) {
        int64_t converted_num;
        auto res =  std::from_chars(varname.data(), varname.data() + varname.size(), converted_num);
        if (res.ec == std::errc::result_out_of_range){
            throw OverflowException();
        }
        ctx.get_stack().push(converted_num);
    } else {
        if (ctx.get_map().count(varname) == 0)
            throw InvalidArgumentsException();
        ctx.get_stack().push(ctx.get_map()[varname]);
    }
}

void Pop::exec(StackCalculatorContext &ctx) {
//        cout << "Pop " << (int64_t)stack.top() << endl;
    if (ctx.get_stack().empty()) throw StackEmptyException();
    ctx.get_stack().pop();
}

void Peek::exec(StackCalculatorContext &ctx) {
    string varname;
    args >> varname;
    if (varname.empty())
        throw InvalidArgumentsException();
//        cout << "Peek m[" << varname << "]=" << (int64_t)stack.top() << endl;
    ctx.get_map()[varname] = ctx.get_stack().top();
}

void Abs::exec(StackCalculatorContext &ctx) {
    if (ctx.get_stack().empty()) throw StackEmptyException();

    auto t = ctx.get_stack().top();
//        cout << "Abs " << (int64_t)t << endl;
    ctx.get_stack().pop();
    try {
        if (t < 0)
            ctx.get_stack().push(-t);
        else
            ctx.get_stack().push(t);
    } catch (SafeIntException &) {
        throw OverflowException();
    }
}

void Plus::exec(StackCalculatorContext &ctx) {
    if (ctx.get_stack().size() < 2) throw StackEmptyException();

    auto a = ctx.get_stack().top();
    ctx.get_stack().pop();
    auto b = ctx.get_stack().top();
    ctx.get_stack().pop();
//        cout << (int64_t)a << " + " << (int64_t)b << endl;
    ctx.get_stack().push(a + b);
}

void Minus::exec(StackCalculatorContext &ctx) {
    if (ctx.get_stack().size() < 2) throw StackEmptyException();

    auto a = ctx.get_stack().top();
    ctx.get_stack().pop();
    auto b = ctx.get_stack().top();
    ctx.get_stack().pop();
//        cout << (int64_t)b << " - " << (int64_t)a << endl;
    ctx.get_stack().push(b - a);
}

void Mul::exec(StackCalculatorContext &ctx) {
    if (ctx.get_stack().size() < 2) throw StackEmptyException();

    auto a = ctx.get_stack().top();
    ctx.get_stack().pop();
    auto b = ctx.get_stack().top();
    ctx.get_stack().pop();
//        cout << (int64_t)a << " * " << (int64_t)b << endl;
    ctx.get_stack().push(a * b);
}

void Div::exec(StackCalculatorContext &ctx) {
    if (ctx.get_stack().size() < 2) throw StackEmptyException();
    auto a = ctx.get_stack().top();
    ctx.get_stack().pop();
    auto b = ctx.get_stack().top();
    ctx.get_stack().pop();
//        cout << (int64_t)b << " / " << (int64_t)a << endl;
    ctx.get_stack().push(b / a);
}

void Print::exec(StackCalculatorContext &ctx) {
    if (ctx.get_stack().empty()) throw StackEmptyException();
    auto a = ctx.get_stack().top();
    std::cout << (int64_t) a << std::endl;
    ctx.get_map()["last_print_don_t_use_me_as_variable_name_pleeeeezzzzzzzzz"] = a;
}

void Read::exec(StackCalculatorContext &ctx) {
    int64_t a;
    std::cin >> a;
    ctx.get_stack().push((SafeInt<int64_t>) a);
}
