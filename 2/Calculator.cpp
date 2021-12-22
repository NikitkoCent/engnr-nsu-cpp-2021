#include "Calculator.h"

bool is_number(const std::string &line) {
    char *p;
    strtol(line.c_str(), &p, 10);
    return *p == 0;
}

void Plus::exec(const std::vector<std::string> &tokens,
                calculator_data &data,
                int args) {
    if (data.values.size() < 2) {
        throw PlusEmptyStack();
    }
    int64_t first_element = data.values.top();
    data.values.pop();
    int64_t second_element = data.values.top();
    data.values.pop();

    int64_t operation_result;
    SafeAdd(second_element, first_element, operation_result);
    data.values.push(operation_result);
}

void Print::exec(const std::vector<std::string> &tokens,
                 calculator_data &data,
                 int args) {
    if (data.values.empty()) {
        throw PrintEmptyStack();
    }
    std::cout << std::to_string((int64_t) data.values.top()) << std::endl;
}

void Minus::exec(const std::vector<std::string> &tokens,
                 calculator_data &data,
                 int args) {
    if (data.values.size() < 2) {
        throw MinusEmptyStack();
    }
    int64_t first_element = data.values.top();
    data.values.pop();
    int64_t second_element = data.values.top();
    data.values.pop();

    int64_t operation_result;
    SafeSubtract(second_element, first_element, operation_result);
    data.values.push(operation_result);
}

void Mul::exec(const std::vector<std::string> &tokens,
               calculator_data &data,
               int args) {
    if (data.values.size() < 2) {
        throw MulEmptyStack();
    }
    int64_t first_element = data.values.top();
    data.values.pop();
    int64_t second_element = data.values.top();
    data.values.pop();

    int64_t operation_result;
    SafeMultiply(second_element, first_element, operation_result);
    data.values.push(operation_result);
}

void Div::exec(const std::vector<std::string> &tokens,
               calculator_data &data,
               int args) {
    if (data.values.size() < 2) {
        throw DivEmptyStack();
    }
    int64_t first_element = data.values.top();
    data.values.pop();
    int64_t second_element = data.values.top();
    data.values.pop();
    if (first_element == 0) {
        throw DivException();
    }
    int64_t operation_result;
    SafeDivide(second_element, first_element, operation_result);
    data.values.push(operation_result);
}

void Push::exec(const std::vector<std::string> &tokens,
                calculator_data &data,
                int args) {
    std::string varname = tokens[1];
    if (varname.empty())
        throw PushEmptyVarname();
    if (is_number(varname)) {
        data.values.push(std::stoll(varname));
    } else {
        auto it = data.names_and_values.find(varname);
        if (it == data.names_and_values.end()) {
            throw PushException();
        }
        data.values.push(it->second);
    }
}

void Peek::exec(const std::vector<std::string> &tokens,
                calculator_data &data,
                int args) {
    if (data.values.empty()) {
        throw PeekEmptyStack();
    }
    if (tokens.size() < 2)
        throw PeekEmptyStack();
    std::string varname = tokens[1];
    data.names_and_values[varname] = data.values.top();
}

void Abs::exec(const std::vector<std::string> &tokens,
               calculator_data &data,
               int args) {
    if (data.values.empty()) {
        throw AbsStackEmpty();
    }
    SafeInt<int64_t> value = data.values.top();
    data.values.pop();
    value = value > 0 ? value : -value;
    data.values.push(value);
}

void Pop::exec(const std::vector<std::string> &tokens,
               calculator_data &data,
               int args) {
    if (!data.values.empty())
        data.values.pop();
    else {
        throw PopStackEmpty();
    }
}

void Read::exec(const std::vector<std::string> &tokens,
                calculator_data &data,
                int args) {
    std::string varname = tokens[1];
    data.values.push(std::stoll(varname));
}

void Comment::exec(const std::vector<std::string> &tokens,
                   calculator_data &data,
                   int args) {
//nothing
}

Command *CommandCreator::factoryMethod(const std::vector<std::string> &commands) {
    std::string tag = commands[0];
    if (tag == "#") {
        return new Comment();
    } else if (tag == "PRINT") {
        return new Print();
    } else if (tag == "PLUS") {
        return new Plus();
    } else if (tag == "DIV") {
        return new Div();
    } else if (tag == "MINUS") {
        return new Minus();
    } else if (tag == "MUL") {
        return new Mul();
    } else if (tag == "READ") {
        return new Read();
    } else if (tag == "PUSH") {
        return new Push();
    } else if (tag == "PEEK") {
        return new Peek();
    } else if (tag == "ABS") {
        return new Abs();
    } else if (tag == "POP") {
        return new Pop();
    } else {
        throw CommandException();
    }
}