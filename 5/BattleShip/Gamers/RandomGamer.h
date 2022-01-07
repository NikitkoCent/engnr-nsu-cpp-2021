//
// Created by Mikhail Okan on 06.01.2022.
//

#ifndef LAB4_RANDOMGAMER_H
#define LAB4_RANDOMGAMER_H

#include <BaseClasses/BaseGamer.h>

#include <utility>

class RandomGamer: public BaseBot {
public:
    explicit RandomGamer(BattleShipModel *m): BaseBot(m) {}

    std::vector<std::string> turn_set_stage() override;
    std::vector<std::string> turn_attack_stage() override;
};


#endif //LAB4_RANDOMGAMER_H
