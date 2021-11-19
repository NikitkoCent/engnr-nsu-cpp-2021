#include "Calculator.h"

#include <stdexcept>
#include <cstdint>

void ns_calculator::Calculator::plus() {
    if(values.size() < 2)
        throw std::invalid_argument("Operation: plus, error: expected size of queue more than 2");
    push(pop_elem() + pop_elem());
}

SafeInt<int64_t> ns_calculator::Calculator::pop_elem() {
    if(values.empty())
        throw std::invalid_argument("Operation: pop_elem, error: empty queue");
    SafeInt<int64_t> temp = values.top();
    pop();
    return temp;
}

void ns_calculator::Calculator::minus() {
    if(values.size() < 2)
        throw std::invalid_argument("Operation: minus, error: expected size of queue more than 2");
    SafeInt<int64_t> first = pop_elem();
    SafeInt<int64_t> second = pop_elem();
    push(second - first);
}

void ns_calculator::Calculator::div() {
    if(values.size() < 2)
        throw std::invalid_argument("Operation: div, error: expected size of queue more than 2");
    SafeInt<int64_t> denominator = pop_elem();
    SafeInt<int64_t> numerator = pop_elem();
    if(denominator == 0)
        throw std::invalid_argument("Operation: div, error: zero division");
    push(numerator / denominator);
}

void ns_calculator::Calculator::mul() {
    if(values.size() < 2)
        throw std::invalid_argument("Operation: mul, error: expected size of queue more than 2");
    push(pop_elem() * pop_elem());
}

void ns_calculator::Calculator::push(SafeInt<int64_t> value) {
    values.push(value);
}

void ns_calculator::Calculator::peek(const std::string &varname) {
    names_and_values[varname] = values.top();
}

SafeInt<int64_t> ns_calculator::Calculator::print() const {
    if(values.empty())
        throw std::invalid_argument("Operation: print, error: no value");
    return values.top();
}

SafeInt<int64_t> ns_calculator::Calculator::abs(SafeInt<int64_t> value) {
    if(value < 0)
        return -value;
    return value;
}

void ns_calculator::Calculator::pop() {
    if(!values.empty())
        values.pop();
}

std::istream &ns_calculator::Calculator::read(std::istream &is) {
    push(is.get());
    return is;
}

void ns_calculator::Calculator::push(const std::string &varname) {
    if(names_and_values.find(varname) == names_and_values.end())
        throw std::invalid_argument("Operation: push, varname doesn't exist");
    push(names_and_values[varname]);
}