//
// Created by Mikhail Okan on 26.12.2021.
//

#include "BattleShipController.h"
BattleShipController::BattleShipController(BattleShipModel *bs_model, BaseGamer *g1, BaseGamer *g2) {
    model = bs_model;
    gamers.push_back(g1);
    gamers.push_back(g2);
};
#include <iostream>
void BattleShipController::start() {
    model->set_current_player(0);
    //stage 1 - placement
    std::vector<std::string> v;
    for(auto &g: gamers) {
        for (int turn = 0; turn < 10; turn++) {
            if (turn < 6) {
                v = g->turn_set_stage(2);
                while (model->set(v[0], v[1]) == 0) {
                    v = g->turn_set_stage(2);
                }
            } else {
                v = g->turn_set_stage(1);
                while (model->set(v[0]) == 0) {
                    v = g->turn_set_stage(1);
                }
            }
        }
    }
    //stage 2 - attack
    int ans = 0;
    while (ans <= 0) {
        v = gamers[model->get_current_player()]->turn_attack_stage(1);
        ans = model->hit(v[0]);
        while (ans == -1) {
            v = gamers[model->get_current_player()]->turn_attack_stage(1);
            ans = model->hit(v[0]);
        }
    }

}