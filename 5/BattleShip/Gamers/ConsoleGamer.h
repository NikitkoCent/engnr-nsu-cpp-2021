//
// Created by Mikhail Okan on 06.01.2022.
//

#ifndef LAB4_CONSOLEGAMER_H
#define LAB4_CONSOLEGAMER_H
#include "BaseClasses/BaseGamer.h"
#include <iostream>
#include <utility>

class ConsoleGamer: public BaseGamer {
public:
    explicit ConsoleGamer(BattleShipModel *m, std::string p): BaseGamer(m, std::move(p)) {}

    std::vector<std::string> turn_set_stage() override;
    std::string show_pass() override;
    std::vector<std::string> turn_attack_stage() override;
};

#endif //LAB4_CONSOLEGAMER_H
