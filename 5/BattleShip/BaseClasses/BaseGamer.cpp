//
// Created by Mikhail Okan on 27.12.2021.
//

#include "BaseGamer.h"
#include <iostream>

bool check_second_random(int first, int second, int length) {
    if (length == -1)
        return std::abs(first - second) > 3 || first == second;
    return std::abs(first - second) != length || first == second;
}


std::vector<std::string> BaseBot::random_generate_next_turn() {
    int length = model->get_awaiting_ship();
    std::vector<std::string> v;
    if (length == -1) { // attack stage
        do {
            v.clear();
            v.push_back(alphabet[get_engine()() % 10] + std::to_string(get_engine()() % 10));
        } while (model->check_cell_to_hit(v[0]));
        v.push_back(v[0]);
    }
    else if (length == 0) { // 1-cell ships
        do {
            v.clear();
            v.push_back(alphabet[get_engine()() % 10] + std::to_string(get_engine()() % 10));
        } while (!model->check_possibility_to_set(v[0], v[0]));
        v.push_back(v[0]);
    }
    else { // 2-4 cell ships
        do {
            v.clear();
            int first = static_cast<int>(get_engine()() % 10);      // first x
            int second = static_cast<int>(get_engine()() % 10);     // first y
            int s_first{999};                                       // second x
            int s_second{999};                                      // second y

            if (get_engine()() % 2 == 0) { // x coordinate = const
                v.push_back(alphabet[first] + std::to_string(second) + " ");
                while (check_second_random(second, s_second, length))
                    s_second = static_cast<int>(get_engine()() % 10);
                v.push_back(alphabet[first] + std::to_string(s_second));
            } else {                      // y coordinate = const
                v.push_back(alphabet[first] + std::to_string(second) + " ");
                while (check_second_random(first, s_first, length))
                    s_first = static_cast<int>(get_engine()() % 10);
                v.push_back(alphabet[s_first] + std::to_string(second));
            }
        } while (!model->check_possibility_to_set(v[0], v[1]));
    }
    return v;
}

std::mt19937 &BaseBot::get_engine()  {
    static std::mt19937 engine;
    return engine;
}