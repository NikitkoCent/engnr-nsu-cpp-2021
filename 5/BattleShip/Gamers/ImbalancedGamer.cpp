//
// Created by Mikhail Okan on 07.01.2022.
//

#include "ImbalancedGamer.h"


std::string ImbalancedGamer::coord_to_str(int x, int y) {
    return std::string() + alphabet[x] + std::to_string(y);
}

bool ImbalancedGamer::strategy1_formula_for_4(int x, int y) {
    return (bool)((x+y+1)%4);
}

bool ImbalancedGamer::strategy2_formula_for_4(int x, int y) {
    return (bool)((x-y-2)%4);
}

bool ImbalancedGamer::strategy1_formula_for_2(int x, int y) {
    return (bool)((x+y+3)%4);
}

bool ImbalancedGamer::strategy2_formula_for_2(int x, int y) {
    return (bool)((x-y-4)%4);
}


std::vector<std::string> ImbalancedGamer::turn_attack_stage() {
    std::vector<std::string> res;
    auto free_diag_4 = std::make_unique<std::vector<std::string>>();
    auto free_diag_2 = std::make_unique<std::vector<std::string>>();
    auto board = std::get<1>(model->get_boards());
    auto strat_formula_for_4 = strategy == 0 ? strategy1_formula_for_4 : strategy2_formula_for_4;
    auto strat_formula_for_2 = strategy == 0 ? strategy1_formula_for_2 : strategy2_formula_for_2;

    for (int y = 0; y < BOARD_SIZE; y++) { // y
        for (int x = 0; x < BOARD_SIZE; x++) { // x
            if (board[y][x] == HITTED_SHIP) { // try to kill any ship to mark more cells
                if (y + 1 <= 9 && board[y + 1][x] == EMPTY_CELL) {
                    res.insert(res.end(), {coord_to_str(x, y + 1), coord_to_str(x, y + 1)});
                    return res;
                }
                if (y - 1 >= 0 && board[y - 1][x] == EMPTY_CELL) {
                    res.insert(res.end(), {coord_to_str(x, y - 1), coord_to_str(x, y - 1)});
                    return res;
                }
                if (x + 1 <= 9 && board[y][x + 1] == EMPTY_CELL) {
                    res.insert(res.end(), {coord_to_str(x + 1, y), coord_to_str(x + 1, y)});
                    return res;
                }
                if (x - 1 >= 0 && board[y][x - 1] == EMPTY_CELL) {
                    res.insert(res.end(), {coord_to_str(x - 1, y), coord_to_str(x - 1, y)});
                    return res;
                }
            }
            if (strat_formula_for_4(x, y) && (board[y][x] == EMPTY_CELL)) { // try to find 4-cell ship
                free_diag_4->push_back(coord_to_str(x, y));
            }
            if (strat_formula_for_2(x, y) && (board[y][x] == EMPTY_CELL)) { // try to find 2 or 3 cell ship
                free_diag_2->push_back(coord_to_str(x, y));
            }
        }
    }
    if (!free_diag_4->empty()) {
        size_t elem = get_engine()()%free_diag_4->size();
        res.insert(res.end(), {free_diag_4->at(elem), free_diag_4->at(elem)});
    } else if (!free_diag_2->empty()) {
        size_t elem = get_engine()()%free_diag_2->size();
        res.insert(res.end(), {free_diag_2->at(elem), free_diag_2->at(elem)});
    } else {
        res = random_generate_next_turn();
    }

    return res;
}