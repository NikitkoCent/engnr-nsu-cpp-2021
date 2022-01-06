//
// Created by Mikhail Okan on 25.12.2021.
//

#include "BattleShipModel.h"


auto parse_coords(const std::string& coords) {
    return std::make_tuple((int)coords[1] - '0', (int)coords[0] - 'A');
}


BattleShipModel::BattleShipModel() {
    reset();
    is_bot[0] = is_bot[1] = false;
}


void BattleShipModel::reset() {
    current_player = false;
    winner = 0;
    turn_number = 0;
    awaiting_ship = 3;
    player_scores[0] = player_scores[1] = 20;
    next_place_message();

    for (auto & board : boards) {
        for (int i = 0; i < BOARD_SIZE; i++) {
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
}


void BattleShipModel::mark_halos_around_destroyed_ship(size_t board_number, size_t enemy_board_number, int x, int y) {
    for (int i = std::max(x-1, 0); i <= std::min(x+1, 9); i++) {
        for (int j = std::max(y-1, 0); j <= std::min(y+1, 9); j++) {
            if (boards[enemy_board_number][i][j] == EMPTY_CELL) boards[board_number][i][j] = MISS;
            else if (boards[enemy_board_number][i][j] == HITTED_SHIP) {
                boards[enemy_board_number][i][j] = PROCESSING_CELL;
                mark_halos_around_destroyed_ship(board_number, enemy_board_number, i, j);
                boards[enemy_board_number][i][j] = HITTED_SHIP;
            }
        }
    }
}


bool BattleShipModel::check_ship_destroyed(size_t board_number, int x, int y) {
    if (boards[board_number][x][y] == SHIP) return false;
    if (boards[board_number][x][y] == MISS || boards[board_number][x][y] == EMPTY_CELL || boards[board_number][x][y] == PROCESSING_CELL) return true;
    boards[board_number][x][y] = PROCESSING_CELL;
    bool destroyed = true;
    for (int i = std::max(x-1, 0); i <= std::min(x+1, 9); i++) {
        for (int j = std::max(y-1, 0); j <= std::min(y+1, 9); j++) {
            destroyed &= check_ship_destroyed(board_number, i, j);
        }
    }
    boards[board_number][x][y] = HITTED_SHIP;
    return destroyed;
}


int BattleShipModel::check_cell_to_hit(const string &c) const {
    try {
        auto[x, y] = parse_coords(c);
        if (x < 0 || x > 9 || y < 0 || y > 9) return 1; // wrong coords
        size_t can_see_board_number = (current_player == 0) ? 2 : 3; // current player can see this enemy board
        if (boards[can_see_board_number][x][y] == MISS || boards[can_see_board_number][x][y] == HITTED_SHIP) return 2; // cell already opened
    } catch (...) {
        return 1; // wrong coords
    }
    return 0;
}


int BattleShipModel::hit(const std::string& c) {
    int status = check_cell_to_hit(c);
    if (status) {
        game_message = status == 1 ? "Please, enter right coordinates!" :  "This cell is already opened!";
        update_view();
        game_message = "";
        return -1;
    }

    auto[x, y] = parse_coords(c);

    size_t can_see_board_number = 2; // current player can see this enemy board
    size_t enemy_board_number   = 1; // real enemy board
    if (current_player == 1)  {
        can_see_board_number = 3;
        enemy_board_number   = 0;
    }

    game_message += "\nPlayer " + std::to_string(current_player + 1) + " hitted cell " + c + "!";

    if (boards[enemy_board_number][x][y] == SHIP) {
        boards[enemy_board_number][x][y]   = HITTED_SHIP;
        boards[can_see_board_number][x][y] = HITTED_SHIP;
        if (check_ship_destroyed(enemy_board_number, x, y)) {
            mark_halos_around_destroyed_ship(can_see_board_number, enemy_board_number, x, y);
        }
        player_scores[1-current_player]--;
        check_winner();
        update_view();
        turn_number++;
        return 0;
    } else {
        boards[enemy_board_number][x][y]   = MISS;
        boards[can_see_board_number][x][y] = MISS;
        current_player = 1-current_player;
        check_winner();
        update_view();
        game_message = "";
        turn_number++;
        return 1;
    }

}


bool BattleShipModel::set(const std::string& c0, const std::string& c1) {
    if (check_possibility_to_set(c0, c1) == 0 || turn_number > 20) {
        game_message = "You can't place this ship here!";
        update_view();
        return false;
    }
    auto [x0, y0] = parse_coords(c0);
    auto [x1, y1] = parse_coords(c1);
    if (x0 > x1) std::swap(x0, x1);
    if (y0 > y1) std::swap(y0, y1);

    int length = std::max(abs(x1 - x0), abs(y1 - y0));
    if (length != awaiting_ship || (sets[current_player][length] <= 0)) {
        game_message = "You can't place this type of ships!";
        update_view();
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
    if (cond_to_change_player) {
        current_player = 1 - current_player;
        awaiting_ship = 3;
        if (current_player == 0) {
            game_message = "Game Starts!";
            awaiting_ship = -1;
        }
    }
    update_view();
    game_message = "";
    return true;
}


bool BattleShipModel::check_neighbour_ships(int x, int y) const {
    for (int i1 = std::max(x-1, 0); i1 <= std::min(x+1, 9); i1++) {
        for (int j1 = std::max(y-1, 0); j1 <= std::min(y+1, 9); j1++) {
            if (boards[current_player][i1][j1] == SHIP) {
                return true;
            }
        }
    }
    return false;
}


bool BattleShipModel::check_possibility_to_set(const std::string& c0, const std::string& c1) const {
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
                if (check_neighbour_ships(i, j)) {
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


void BattleShipModel::update_player_status(int player, bool bot) {
    is_bot[player] = bot;
}


void BattleShipModel::check_winner() {
    if (player_scores[0] == 0) winner = 2;
    else if (player_scores[1] == 0) winner = 1;
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


std::tuple<std::array<std::array<char, 10>, 10>, std::array<std::array<char, 10>, 10>> BattleShipModel::get_boards() const {
    if (current_player == 0) {
        return std::make_tuple(boards[0], boards[2]);
    }
    return std::make_tuple(boards[1], boards[3]);
}


void BattleShipModel::add_view(BaseView *bs_view) {
    view = bs_view;
    update_view();
}


int BattleShipModel::get_awaiting_ship() const {
    return awaiting_ship;
}


void BattleShipModel::update_view() {
    if (!is_bot[current_player] || (is_bot[current_player] && is_bot[1-current_player]))
        view->update();
}