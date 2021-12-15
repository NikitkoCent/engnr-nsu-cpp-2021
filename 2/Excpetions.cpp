//
// Created by Mikhail Okan on 15.12.2021.
//

#include "Excpetions.h"

std::string StackExceptions::InvalidArgument::what() {
    return default_error + invalid_error;
}

std::string StackExceptions::PushException::what() {
    return default_error + invalid_error + push_error;
}

std::string StackExceptions::StackEmpty::what() {
    return default_error + empty_error;
}

std::string StackExceptions::ReadException::what() {
    return default_error + read_error;
}

std::string StackExceptions::StackLack::what() {
    return default_error + lack_error;
}

std::string StackExceptions::OverflowException::what() {
    return default_error + overflow_error;
}

std::string StackExceptions::DivisionByZero::what() {
    return default_error + zero_error;
}

std::string StackExceptions::InvalidOperation::what() {
    return default_error + operation_error;
}