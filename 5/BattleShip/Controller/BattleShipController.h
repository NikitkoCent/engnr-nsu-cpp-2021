//
// Created by Mikhail Okan on 26.12.2021.
//

#ifndef LAB4_BATTLESHIPCONTROLLER_H
#define LAB4_BATTLESHIPCONTROLLER_H
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <filesystem>

#include "../Model/BattleShipModel.h"
#include "../BaseClasses/BaseGamer.h"

class BattleShipController {
protected:
    BattleShipModel *model;
    std::vector<BaseGamer*> gamers;
    std::string path_to_log;
    std::string log;
public:
    explicit BattleShipController(BattleShipModel *bs_model, BaseGamer *g1, BaseGamer *g2);
    ~BattleShipController() = default;

    void start(int c);
};


#endif //LAB4_BATTLESHIPCONTROLLER_H
