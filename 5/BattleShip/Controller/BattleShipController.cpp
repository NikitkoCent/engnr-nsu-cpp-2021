//
// Created by Mikhail Okan on 26.12.2021.
//

#include "BattleShipController.h"
BattleShipController::BattleShipController(BattleShipModel *bs_model, BaseGamer *g1, BaseGamer *g2) {
    model = bs_model;
    gamers.push_back(g1);
    gamers.push_back(g2);
    model->update_player_status(0, g1->is_bot);
    model->update_player_status(1, g2->is_bot);
};


void BattleShipController::start() {
    int ans;
    //stage 1 - placement
    std::vector<std::string> v;
    for(auto &g: gamers) {
        for (int turn = 0; turn < 10; turn++) {
            do {
                v = g->turn_set_stage();
            } while (model->set(v[0], v[1]) == 0);
        }
    }
    //stage 2 - attack
    while (model->get_winner() == 0) {
        do {
            v = gamers[model->get_current_player()]->turn_attack_stage();
            ans = model->hit(v[0]);
        } while ((ans == -1 || ans == 0) && model->get_winner() == 0);
    }
}