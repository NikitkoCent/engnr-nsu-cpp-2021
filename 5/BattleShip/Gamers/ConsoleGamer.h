//
// Created by Mikhail Okan on 06.01.2022.
//

#ifndef LAB4_CONSOLEGAMER_H
#define LAB4_CONSOLEGAMER_H
#include "BaseClasses/BaseGamer.h"
#include <iostream>

class ConsoleGamer: public BaseGamer {
public:
    explicit ConsoleGamer(BattleShipModel *m): BaseGamer(m) {}

    std::vector<std::string> turn_set_stage() override;

    std::vector<std::string> turn_attack_stage() override;
};

#endif //LAB4_CONSOLEGAMER_H
