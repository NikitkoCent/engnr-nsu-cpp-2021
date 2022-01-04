#include "calc.h"
#define elif else if


bool is_number(const std::string &str) {
    return !str.empty() && (std::all_of(str.begin(), str.end(), [](char c) { return ::isdigit(c); }) ||
                            (str[0] == '-' &&
                             std::all_of(str.begin() + 1, str.end(), [](char c) { return ::isdigit(c); })));
}


void Pop::rep(const std::vector<std::string> &command_str,
              calculator_data &data
) {
    if (!data.values.empty())
        data.values.pop();
    else {
        throw CalcExceptions::Empty();
    }
}


void Plus::rep(const std::vector<std::string> &command_str,
               calculator_data &data
) {
    if (data.values.size() < 2) { // проверка на то, что у нас есть два слагаемых
        throw CalcExceptions::StackDeficit();
    } else {
        int64_t first_summand = data.values.top();
        data.values.pop();
        int64_t second_summand = data.values.top();
        data.values.pop();

        int64_t result;
        SafeAdd(first_summand, second_summand, result);
        data.values.push(result);
    }
}

void Minus::rep(const std::vector<std::string> &command_str,
                calculator_data &data
) {
    if (data.values.size() < 2) {
        throw CalcExceptions::StackDeficit();
    } else {
        int64_t first_min = data.values.top();
        data.values.pop();
        int64_t second_min = data.values.top();
        data.values.pop();

        int64_t result;
        SafeSubtract(second_min, first_min, result);
        data.values.push(result);
    }
}

void Print::rep(const std::vector<std::string> &command_str,
                calculator_data &data
) {
    if (data.values.empty()) {
        throw CalcExceptions::StackEmpty();
    }
    std::cout << (int64_t) data.values.top() << std::endl;
}


void Mul::rep(const std::vector<std::string> &command_str,
              calculator_data &data
) {
    if (data.values.size() < 2) {
        throw CalcExceptions::StackDeficit();
    } else {
        int64_t first_mul = data.values.top();
        data.values.pop();
        int64_t second_mul = data.values.top();
        data.values.pop();

        int64_t result;
        SafeMultiply(first_mul, second_mul, result);
        data.values.push(result);
    }

}

void Div::rep(const std::vector<std::string> &command_str,
              calculator_data &data
) {
    if (data.values.size() < 2) {
        throw CalcExceptions::StackDeficit();
    } else {
        int64_t first_del = data.values.top();
        data.values.pop();
        int64_t second_del = data.values.top();
        data.values.pop();
        if (first_del == 0) {
            throw CalcExceptions::DivisionByZero();
        }
        int64_t result;
        SafeDivide(second_del, first_del, result);
        data.values.push(result);
    }

}

void Push::rep(const std::vector<std::string> &command_str,
               calculator_data &data
) {
    std::string name = command_str[1];

    if (name.empty())
        throw CalcExceptions::EmptyVarName();
    if (is_number(name)) { // положить число на стек
        data.values.push(std::stoll(name));
    } else { // положить число, хранящееся в переменной
        auto find_count = data.compare_names.find(name);
        if (find_count == data.compare_names.end()) {
            throw CalcExceptions::InvalidInput();
        }
        data.values.push(find_count->second);// че такое second????//////////////////////////////
    }
}

void Peek::rep(const std::vector<std::string> &command_str,
               calculator_data &data
) {
    if (data.values.empty()) {
        throw CalcExceptions::StackEmpty();
    } elif (command_str.size() < 2) {
        throw CalcExceptions::StackDeficit();
    }

    std::string name = command_str[1]; // запоминаем число, которое будем записывать
    data.compare_names[name] = data.values.top();
}

void Abs::rep(const std::vector<std::string> &command_str,
              calculator_data &data
) {
    if (data.values.empty()) {
        throw CalcExceptions::StackEmpty();
    } else {
        SafeInt<int64_t> aboba = data.values.top();
        if (aboba < 0) {
            aboba = -aboba;
        }
        data.values.pop();
        data.values.push(aboba);
    }

}


void Read::rep(const std::vector<std::string> &command_str,
               calculator_data &data
) {
    if (command_str.size() < 2) {
        throw CalcExceptions::EmptyName();
    } else {
        data.values.push(std::stoll(command_str[1]));
    }

}

void Comment::rep(const std::vector<std::string> &command_str,
                  calculator_data &data) {
    //provotorov_the_best.ru
}

Command *CommandCreator::factoryMethod(const std::vector<std::string> &commands) {
    std::string tag = commands[0];
    if (tag == "#" || tag == " ") {
        return new Comment();
    } elif (tag == "POP") {
        return new Pop();
    } elif (tag == "PUSH") {
        return new Push();
    } elif (tag == "PEEK") {
        return new Peek();
    } elif (tag == "ABS") {
        return new Abs();
    } elif (tag == "PLUS") {
        return new Plus();
    } elif (tag == "MINUS") {
        return new Minus();
    } elif (tag == "MUL") {
        return new Mul();
    } elif (tag == "DIV") {
        return new Div();
    } elif (tag == "PRINT") {
        return new Print();
    } elif (tag == "READ") {
        return new Read();
    } else {
        throw CalcExceptions::InvalidOperation();
    }
}


void calc_work(std::stringstream &test_str, std::ifstream &file, int args) {
    CommandCreator creator;
    calculator_data data;

    std::vector<std::string> phrase;
    std::string word;

    Command *calc_command;

    std::string command;
    std::string cmd_s;
    if (args == 2) { // считывание из файла (есть название)

        while (getline(file, cmd_s, '\n')) {
            if (cmd_s.empty()) // пропуск пустых строк
                continue;
            std::stringstream ss(cmd_s);
            while (getline(ss, word, ' ')) {
                phrase.push_back(word);
            }
            calc_command = creator.factoryMethod(phrase);
            calc_command->rep(phrase, data);
            phrase.clear();
            delete calc_command;
        }
    } elif (args == 1) {
        while (std::getline(std::cin, cmd_s, '\n')) {
            if (cmd_s.empty())
                continue;
            std::stringstream ss(cmd_s);
            while (getline(ss, word, ' ')) {
                phrase.push_back(word);
            }
            calc_command = creator.factoryMethod(phrase);
            calc_command->rep(phrase, data);
            phrase.clear();
            delete calc_command;
        }
    } elif (args == 3) {
        while (getline(test_str, cmd_s, '\n')) {
            if (cmd_s.empty())
                continue;
            std::stringstream ss(cmd_s);
            while (getline(ss, word, ' ')) {
                phrase.push_back(word);
            }
            calc_command = creator.factoryMethod(phrase);
            calc_command->rep(phrase, data);
            phrase.clear();
            delete calc_command;
        }
    }
}