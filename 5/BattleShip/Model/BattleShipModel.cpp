//
// Created by Mikhail Okan on 25.12.2021.
//

#include "BattleShipModel.h"


auto parse_coords(const std::string& coords) {
    return std::make_tuple((int)coords[1] - '0', (int)coords[0] - 'A');
}


BattleShipModel::BattleShipModel(): current_player(false) {
    for (auto & board : boards) {
        board = new char *[BOARD_SIZE];
        for (int i = 0; i < BOARD_SIZE; i++) {
            board[i] = new char[BOARD_SIZE];
            for (int j = 0; j < BOARD_SIZE; j++) {
                board[i][j] = EMPTY_CELL;
            }
        }
    }
    for (auto & set : sets) {
        for (int j = 0; j <= 3; j++) {
            set[j] = 4 - j;
        }
    }
    player_scores[0] = player_scores[1] = 20;
}


int BattleShipModel::hit(const std::string& c) {
    try {
        auto[x, y] = parse_coords(c);
        size_t can_see_board_number = 2;
        size_t enemy_board_number = 1;
        if (current_player == 1)  {
            can_see_board_number = 3;
            enemy_board_number = 0;
        }

        if (boards[enemy_board_number][x][y] == SHIP) {
            boards[enemy_board_number][x][y] = HITTED_SHIP;
            boards[can_see_board_number][x][y] = HITTED_SHIP;
            player_scores[1-current_player]--;
        } else if ((boards[enemy_board_number][x][y] == MISS) or (boards[enemy_board_number][x][y] == HITTED_SHIP)) {
            game_message = "This cell is already opened!";
            view->update();
            return -1;
        } else {
            boards[enemy_board_number][x][y] = MISS;
            boards[can_see_board_number][x][y] = MISS;
        }
        is_end();
        game_message = "Player " + std::to_string(current_player + 1) + " hitted cell " + c + "!";
        current_player = 1-current_player;
        view->update();
        turn_number++;
        return winner;
    } catch(...) {
        game_message = "Please, enter right coordinates!";
        view->update();
        return -1;
    }
}


bool BattleShipModel::set(const std::string& c0, const std::string& c1) {
    if (check_possibility_to_set(c0, c1) == 0 || turn_number > 20) {
        game_message = "You can't place this ship here!";
        view->update();
        return false;
    }
    auto [x0, y0] = parse_coords(c0);
    auto [x1, y1] = parse_coords(c1);
    if (x0 > x1) std::swap(x0, x1);
    if (y0 > y1) std::swap(y0, y1);

    int length = std::max(abs(x1 - x0), abs(y1 - y0));
    if (length != awaiting_ship || (sets[current_player][length] <= 0)) {
        game_message = "You can't place this type of ships!";
        view->update();
        return false;
    }
    sets[current_player][length]--;
    for (int i = x0; i <= x1; i++) {
        for (int j = y0; j <= y1; j++) {
            boards[current_player][i][j] = SHIP;
        }
    }
    bool cond_to_change_player = true;
    for (int i = 0; i < 4; i++) {
        cond_to_change_player &= (sets[current_player][i] == 0);
    }
    turn_number++;
    next_place_message();
//    view->update();
    if (cond_to_change_player) {
        current_player = 1 - current_player;
        awaiting_ship = 3;
        if (current_player == 0) {
            game_message = "Game Starts!";
        }
    }
    view->update();
    return true;
}


bool BattleShipModel::check_possibility_to_set(const std::string& c0, const std::string& c1) {
    try {
        auto[x0, y0] = parse_coords(c0);
        auto[x1, y1] = parse_coords(c1);

        if (x0 > x1) std::swap(x0, x1);
        if (y0 > y1) std::swap(y0, y1);

        if (x0 < 0 || y0 < 0 || x1 < 0 || y1 < 0 || x0 >= 10 || x1 >= 10 || y0 >= 10 || y1 >= 10) return false;

        if (x1 != x0 && y1 != y0) return false;

        if (boards[current_player][x0][y0] == SHIP || boards[current_player][x1][y1] == SHIP) return false;

        for (int i = x0; i <= x1; i++) {
            for (int j = y0; j <= y1; j++) {
                if (i - 1 >= 0 && boards[current_player][i - 1][j] == SHIP ||
                    i + 1 <= 9 && boards[current_player][i + 1][j] == SHIP ||
                    j - 1 >= 0 && boards[current_player][i][j - 1] == SHIP ||
                    j + 1 <= 9 && boards[current_player][i][j + 1] == SHIP ||
                    j - 1 >= 0 && i - 1 >= 0 && boards[current_player][i - 1][j - 1] == SHIP ||
                    j + 1 <= 9 && i + 1 <= 9 && boards[current_player][i + 1][j + 1] == SHIP ||
                    j - 1 >= 0 && i + 1 <= 9 && boards[current_player][i + 1][j - 1] == SHIP ||
                    j + 1 <= 9 && i - 1 >= 0 && boards[current_player][i - 1][j + 1] == SHIP) {
                    return false;
                }
            }
        }
        return true;
    } catch (...) {
        return false;
    }
}


void BattleShipModel::next_place_message() {
    game_message = "Please, enter coordinates (XX YY) for ship with length ";
    if (turn_number % 10 == 0) {
        awaiting_ship = 3;
        game_message += "4 (xxxx): ";
    }
    else if (turn_number % 10 == 1 || turn_number % 10 == 2) {
        awaiting_ship = 2;
        game_message += "3 (xxx): ";
    }
    else if (turn_number % 10 >= 3 && turn_number % 10 <= 5) {
        awaiting_ship = 1;
        game_message += "2 (xx): ";
    }
    else if (turn_number % 10 >= 6 && turn_number % 10 <= 9) {
        awaiting_ship = 0;
        game_message += "1 (x): ";
    }
}


void BattleShipModel::is_end() {
    if (player_scores[0] == 0) winner = 2;
    else if (player_scores[1] == 0) winner = 1;
}


void BattleShipModel::set_current_player(bool player) {
    current_player = player;
}


int BattleShipModel::get_winner() const {
    return winner;
}


bool BattleShipModel::get_current_player() const {
    return current_player;
}


size_t BattleShipModel::get_turn_number() const {
    return turn_number;
}


std::string BattleShipModel::get_game_message() const {
    return game_message;
}


std::tuple<char**, char**> BattleShipModel::get_boards() const {
    if (current_player == 0) {
        return std::make_tuple(boards[0], boards[2]);
    }
    return std::make_tuple(boards[1], boards[3]);
}


void BattleShipModel::add_view(BaseView *bs_view) {
    view = bs_view;
    view->update();
}

size_t BattleShipModel::get_awaiting_ship() const {
    return awaiting_ship;
}