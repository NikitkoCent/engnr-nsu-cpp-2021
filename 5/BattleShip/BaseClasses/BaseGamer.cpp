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

std::vector<std::string> BaseBot::random_generate_next_turn(size_t args_count) {
//    std::cout << args_count << length << std::endl;
    int length = model->get_awaiting_ship();
    std::vector<std::string> v;

    if (args_count == 2) {
        int first = get_engine()()%10;
        int second = get_engine()()%10;
        int s_first{999};
        int s_second{999};

        if (get_engine()() % 2 == 0) { // 1st coordinate = const
            v.push_back(alphabet[first] + std::to_string(second) + " ");
            while (check_second_random(second, s_second, length))
                s_second = get_engine()()%10;
            v.push_back(alphabet[first] + std::to_string(s_second));
        } else { // 2nd coordinate = const
            v.push_back(alphabet[first] + std::to_string(second) + " ");
            while (check_second_random(first, s_first, length))
                s_first = get_engine()()%10;
            v.push_back(alphabet[s_first] + std::to_string(second));
        }
    } else {
        for (int i = 0; i < args_count; i++)
            v.push_back(alphabet[get_engine()() % 10] + std::to_string(get_engine()() % 10));
    }
//    for(auto &vv: v) {
//        std::cout << vv << " ";
//    }
//    std::cout << std::endl;
    return v;
}

std::mt19937 &BaseBot::get_engine()  {
    static std::mt19937 engine;
    return engine;
}