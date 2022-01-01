//
// Created by Mikhail Okan on 26.12.2021.
//

#ifndef LAB4_BATTLESHIPCONTROLLER_H
#define LAB4_BATTLESHIPCONTROLLER_H
#include "../Model/BattleShipModel.h"
#include "../BaseClasses/BaseGamer.h"

class BattleShipController {
private:
    BattleShipModel *model;
    std::vector<BaseGamer*> gamers;
public:
    explicit BattleShipController(BattleShipModel *bs_model, BaseGamer *g1, BaseGamer *g2);
    ~BattleShipController() = default;

    void start();
};


#endif //LAB4_BATTLESHIPCONTROLLER_H
