//
// Created by Mikhail Okan on 26.12.2021.
//

#include "BattleShipController.h"


std::size_t number_of_files_in_directory(const std::filesystem::path& path)
{
    using std::filesystem::directory_iterator;
    return std::distance(directory_iterator(path), directory_iterator{});
}


BattleShipController::BattleShipController(BattleShipModel *bs_model, BaseGamer *g1, BaseGamer *g2) {
    model = bs_model;
    gamers.push_back(g1);
    gamers.push_back(g2);
    model->update_player_status(0, g1->is_bot);
    model->update_player_status(1, g2->is_bot);
    model->set_password(0, g1->pass);
    model->set_password(1, g2->pass);
}


void BattleShipController::start(int c) {
    int ans;
    int cur_sess = 0;
    std::vector<std::string> v;
    std::fstream fs;
    std::string path_to_log_dir = "../Scenario";
    while (cur_sess != c) {
        model->reset();
        path_to_log = path_to_log_dir + '/' + "game_log_" + std::to_string(number_of_files_in_directory(path_to_log_dir)) + ".txt";
        log = "";
        //stage 1 - placement
        for (auto &g: gamers) {
            while (model->get_awaiting_password()) {model->check_password(g->show_pass());}
            for (int turn = 0; turn < 10; turn++) {
                do {
                    v = g->turn_set_stage();
                    log += v[0] + " " + v[1] + "\n";
                } while (model->set(v[0], v[1]) == 0);
            }
        }
        //stage 2 - attack
        while (model->get_winner() == 0) {
            while (model->get_awaiting_password()) {model->check_password(gamers[model->get_current_player()]->show_pass());}
            do {
                v = gamers[model->get_current_player()]->turn_attack_stage();
                ans = model->hit(v[0]);
                log += v[0] + "\n";
            } while ((ans == -1 || ans == 0) && model->get_winner() == 0);
        }
        cur_sess += 1;
        fs.open(path_to_log, std::fstream::out);
        fs << log;
        fs.close();
        getchar();
    }
}