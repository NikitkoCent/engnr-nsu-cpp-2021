//
// Created by gav on 08/10/2021.
//

#ifndef CPP_LABS_COMMANDFACTORY_H
#define CPP_LABS_COMMANDFACTORY_H

#include <memory>
#include <sstream>
#include <string>

#include "Commands.h"

class CommandFactory {
public:
    static std::unique_ptr<Command> parseCmd(stringstream &cmd);
};

#endif //CPP_LABS_COMMANDFACTORY_H
