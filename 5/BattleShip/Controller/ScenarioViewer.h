//
// Created by Mikhail Okan on 06.01.2022.
//

#ifndef LAB4_SCENARIOVIEWER_H
#define LAB4_SCENARIOVIEWER_H
#include "../BattleShip/Model/BattleShipModel.h"
#include <fstream>
class ScenarioViewer {
private:
    BattleShipModel *model;
    std::fstream fs;
    std::string arg1, arg2;
public:
    explicit ScenarioViewer(BattleShipModel *m): model(m) {}
    ~ScenarioViewer() {fs.close();}
    std::string next();

    void load(const std::string& path);

    bool eof();
};


#endif //LAB4_SCENARIOVIEWER_H
