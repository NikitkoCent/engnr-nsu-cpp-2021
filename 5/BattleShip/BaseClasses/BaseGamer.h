//
// Created by Mikhail Okan on 27.12.2021.
//

#ifndef LAB4_BASEGAMER_H
#define LAB4_BASEGAMER_H
#include <random>
#include <ctime>
#include <utility>

#include "../Model/BattleShipModel.h"


class BaseGamer {
protected:
    std::string alphabet;
    const BattleShipModel *model;

public:
    bool is_bot;
    std::string pass; // da, da, password v pablike, i 4to?

    BaseGamer(const BattleShipModel *m, std::string p): alphabet("ABCDEFGHIJ"), model(m), is_bot(false), pass(std::move(p)) {}
    virtual std::vector<std::string> turn_set_stage() {return std::vector<std::string>{"A0", "A0"};}
    virtual std::vector<std::string> turn_attack_stage() {return std::vector<std::string>{"A0", "A0"};}
    virtual std::string show_pass() {return pass;}
};


class BaseBot: public BaseGamer {
protected:
    std::vector<std::string> random_generate_next_turn();
    static std::mt19937& get_engine();
public:
    explicit BaseBot(BattleShipModel *m): BaseGamer(m, std::to_string(get_engine()())) {get_engine().seed((unsigned int)std::time(nullptr)); is_bot = true;}
};


#endif //LAB4_BASEGAMER_H
