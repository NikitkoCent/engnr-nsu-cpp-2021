//
// Created by Mikhail Okan on 06.01.2022.
//

#include "ConsoleGamer.h"

std::vector<std::string> ConsoleGamer::turn_set_stage() {
    std::string s;
    std::vector<std::string> v;
    int length = model->get_awaiting_ship();
    if (length == -1 || length == 1) { // attack stage or 1-cell ship
        std::cin >> s;
        v.push_back(s);
        v.push_back(s);
    } else { // 2-4 cells ships
            for (int i = 0; i < 2; i++) {
            std::cin >> s;
            v.push_back(s);
        }
    }
    return v;
}

std::vector<std::string> ConsoleGamer::turn_attack_stage() {
    return turn_set_stage();
}