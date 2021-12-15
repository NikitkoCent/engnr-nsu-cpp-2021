//
// Created by Mikhail Okan on 15.11.2021.
//

#ifndef STACK_CALC_STACKCALC_H
#define STACK_CALC_STACKCALC_H
#include <string>
#include "SpecificActionCreator.h"
#include "SafeInt/SafeInt.hpp"

namespace SC {
    class StackCalc {
    private:
        SafeInt<long> last;
        StackActions::Context context;
    public:
        void act(std::unique_ptr<StackActions::Action> action);
        void execute(std::istream &in);
        SafeInt<long> get_last();
    };
}

#endif //STACK_CALC_STACKCALC_H
