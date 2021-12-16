#include "exception.h"

std::string WrongArgument::what() {
    return text + wrong;
}

std::string EmptyStack::what() {
    return text + empty;
}

std::string FewElementError::what() {
    return text + few_elem;
}

std::string PopException::what() {
    return text + empty + pop;
}

std::string PushException::what() {
    return text + wrong + push;
}

std::string PeekException::what() {
    return text + empty + peek;
}


std::string AbsException::what() {
    return text + empty + abs;
}


std::string PlusException::what() {
    return text + few_elem + plus;
}

std::string MinusException::what() {
    return text + few_elem + minus;
}

std::string MultiplyException::what() {
    return text + few_elem + mul;
}


std::string DivisionException::what() {
    return text + few_elem + div;
}


std::string PrintException::what() {
    return text + empty + print;
}


