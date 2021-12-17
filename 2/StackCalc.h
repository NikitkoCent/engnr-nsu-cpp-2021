//
// Created by Mikhail Okan on 15.11.2021.
//

#ifndef STACK_CALC_STACKCALC_H
#define STACK_CALC_STACKCALC_H
#include <string>
#include <memory>
#include "SpecificActionCreator.h"
#include "SafeInt/SafeInt.hpp"

namespace SC {
    class StackCalc {
    private:
        StackActions::Context context;
    public:
        void act(std::unique_ptr<StackActions::Action> action);
        void execute(std::istream &in);
    };
}

#endif //STACK_CALC_STACKCALC_H
