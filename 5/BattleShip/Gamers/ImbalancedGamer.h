//
// Created by Mikhail Okan on 07.01.2022.
//

#ifndef BATTLESHIPGAME_IMBALANCEDGAMER_H
#define BATTLESHIPGAME_IMBALANCEDGAMER_H
#include <memory>

#include "OptimalGamer.h"

class ImbalancedGamer: public OptimalGamer {
private:
    std::string coord_to_str(int x, int y);
    int strategy;

    static bool strategy1_formula_for_4(int x, int y);
    static bool strategy2_formula_for_4(int x, int y);
    static bool strategy1_formula_for_2(int x, int y);
    static bool strategy2_formula_for_2(int x, int y);
public:
    explicit ImbalancedGamer(BattleShipModel *m): OptimalGamer(m) {strategy = static_cast<int>(get_engine()()%2);}
    ~ImbalancedGamer() = default;

    std::vector<std::string> turn_attack_stage() override;
};


#endif //BATTLESHIPGAME_IMBALANCEDGAMER_H
