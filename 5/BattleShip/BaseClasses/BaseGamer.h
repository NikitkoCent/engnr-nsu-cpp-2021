//
// Created by Mikhail Okan on 27.12.2021.
//

#ifndef LAB4_BASEGAMER_H
#define LAB4_BASEGAMER_H
#include <random>
#include "../Model/BattleShipModel.h"
class BaseGamer {
protected:
    std::string alphabet;
    const BattleShipModel *model;
public:
    bool show_board{true};
    explicit BaseGamer(const BattleShipModel *m): model(m), alphabet("ABCDEFGHIJ") {}
    virtual std::vector<std::string> turn_set_stage(size_t args_count) {}
    virtual std::vector<std::string> turn_attack_stage(size_t args_count) {}
};


class BaseBot: public BaseGamer {
protected:
    std::vector<std::string> random_generate_next_turn(size_t args_count);
    static std::mt19937& get_engine();
public:
    bool show_board{false};
    explicit BaseBot(BattleShipModel *m): BaseGamer(m) {}
};


#endif //LAB4_BASEGAMER_H
