//
// Created by Mikhail Okan on 15.11.2021.
//

#ifndef STACK_CALC_SPECIFICACTIONCREATOR_H
#define STACK_CALC_SPECIFICACTIONCREATOR_H
#include "Actions.h"
namespace SAC {
    class SpecificActionCreator {
    public:
        static StackActions::Action* getAction(std::istringstream &line);
    };
}


#endif //STACK_CALC_SPECIFICACTIONCREATOR_H
