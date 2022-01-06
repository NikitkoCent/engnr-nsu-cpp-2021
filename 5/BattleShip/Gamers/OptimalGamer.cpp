//
// Created by Mikhail Okan on 06.01.2022.
//

#include "OptimalGamer.h"

bool OptimalGamer::is_halo(int (*halos)[10], int x, int y) {
    if (x >= 0 && x <= 9 && y >= 0 && y <= 9)
        return halos[x][y] == 10000;
    return true;
}

void OptimalGamer::set_halo_around_ship(int (*halos)[10], int x, int y) {
    for (int i = std::max(x-1, 0); i <= std::min(x + 1, 9); i++) {
        for (int j = std::max(y-1, 0); j <= std::min(y + 1, 9); j++) {
            halos[i][j] = 10000;
        }
    }
}

void OptimalGamer::evaluate_point(int halos[10][10], int x, int y) {
    // calc halo sums around the point (max intersection with halos -> max free cells for enemy)
    halos[x][y] = 9 - ((x-1 < 0) + (x+1 > 9) + (y-1 < 0) + (y+1 > 9) -
                       ((x-1 < 0) & (y-1 < 0) +
                                    (x+1 > 9) & (y-1 < 0) +
                                                (x-1 < 0) & (y+1 > 9) +
                                                            (x+1 > 9) & (y+1 > 9)));

    for (int i = x-1; i <= x+1; i++) {
        for (int j=y-1; j <= y+1; j++) {
            halos[x][y] -= is_halo(halos, i, j);
        }
    }
}

void OptimalGamer::evaluate_board(std::array<std::array<char, 10>, 10> board, int halo[10][10]) {
    for (int i=0; i < 10; i++) {
        for (int j=0; j < 10; j++) {
            if (board[i][j] == SHIP)
                set_halo_around_ship(halo, i, j);
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (halo[i][j] != 10000) // not halo
                evaluate_point(halo, i, j);
        }
    }
}

int OptimalGamer::evaluate_ship_coords(int halos[10][10], int x0, int y0, int x1, int y1) {
    // calc free cells around the ship (less - better)
    int loc_sum=0;
    for (int i = x0; i <= x1; i++) {
        for (int j = y0; j <= y1; j++) {
            loc_sum += halos[i][j];
        }
    }
    return loc_sum;
}

std::vector<std::string> OptimalGamer::turn_set_stage() {
    std::vector<std::string> v;
    auto board = std::get<0>(model->get_boards());
    int length = model->get_awaiting_ship();
    if (length == 1) {
        return random_generate_next_turn();
    }
    int board_halos[10][10]{};
    evaluate_board(board, board_halos);
    int x0=0, y0=0, x1=0, y1=0, loc_sum, max_s=INT_MAX;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i+length <= 9) {
                loc_sum = evaluate_ship_coords(board_halos, i, j, i + length, j);
                if (loc_sum < max_s || (loc_sum == max_s && get_engine()()%2)) {
                    max_s = loc_sum; y0 = i; x0 = j; y1=i+length; x1=j;
                }
            }
            if (j+length <= 9) {
                loc_sum = evaluate_ship_coords(board_halos, i, j, i, j + length);
                if (loc_sum < max_s || (loc_sum == max_s && get_engine()()%2)) {
                    max_s = loc_sum; y0 = i; x0 = j; y1=i; x1=j+length;
                }
            }
        }
    }
    v.push_back(std::string() + alphabet[x0] + std::to_string(y0));
    v.push_back(std::string() + alphabet[x1] + std::to_string(y1));
    return v;
}

std::vector<std::string> OptimalGamer::turn_attack_stage() {
    return random_generate_next_turn();
}