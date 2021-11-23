#pragma once

#include <stack>
#include <map>
#include <string>
#include <cstdint>

#include "SafeInt.hpp"

namespace ns_Calc {
    class CalcContext {
    public:
        std::stack<SafeInt<int64_t>> m_stack;
        std::map<std::string, SafeInt<int64_t>> m_varmap;
        CalcContext() : m_stack(), m_varmap{} {};
    };
}

