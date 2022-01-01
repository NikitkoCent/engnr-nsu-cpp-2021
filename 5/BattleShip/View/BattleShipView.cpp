//
// Created by Mikhail Okan on 25.12.2021.
//

#include "BattleShipView.h"
#define SPACE_SIZE 10
#define BOARD_SIZE 10


void show_board_line(char **board, size_t line) {
    std::cout << " | ";
    for (int j = 0; j < BOARD_SIZE; j++) {
        std::cout << board[line][j] << " | ";
    }
    for (int j = 0; j < SPACE_SIZE; j++) {
        std::cout << " ";
    }
}


void show_board_div_line(size_t current_table) {
    for (int j = 0 ; j < BOARD_SIZE + current_table; j++) {
        std::cout << "-+- ";
    }
    for (int j = 0 ; j < SPACE_SIZE-1; j++) {
        std::cout << " ";
    }
}


void show_boards_line(std::array<char**, 2> boards, size_t line) {
    for(int i = 0; i < 2; i++) {
        show_board_line(boards[i], line);
    }
    std::cout << std::endl;
}


void show_div_line() {
    std::cout << "  -+- ";
    for (int b = 0; b < 2; b++) {
        show_board_div_line(b);
    }
    std::cout << std::endl;
}


void show_board(std::array<char**, 2> boards, const std::string &alphabet) {
    std::cout << "     ";
    for (int i = 0; i < 2; i++) { // show letters
        for (int j = 0; j < BOARD_SIZE; j++)
            std::cout << alphabet[j] << "   ";
        for (int j = 0; j < SPACE_SIZE+3; j++)
            std::cout << " ";
    }
    std::cout << std::endl;
    show_div_line();
    for(int line = 0; line < BOARD_SIZE; line++) {
        std::cout << line << " ";
        show_boards_line(boards, line);
        show_div_line();
    }
}


template<typename tuple_t>
constexpr auto get_array_from_tuple(tuple_t&& tuple) {
    constexpr auto get_array = [](auto&& ... x){ return std::array{std::forward<decltype(x)>(x) ... }; };
    return std::apply(get_array, std::forward<tuple_t>(tuple));
}


void BattleShipView::update() const {
    std::cout << "Board for player " << model->get_current_player()+1 << "    Turn: " << model->get_turn_number() << std::endl;
    show_board(get_array_from_tuple(model->get_boards()), "ABCDEFGHIJ");
    std::cout << "\n\n";
    show_game_message();
    if (model->get_winner()) {
        show_win_message();
    }
}


void BattleShipView::show_win_message() const {
    std::cout << "Player " << (1-model->get_current_player())+1 << " win!" << std::endl;
}


void BattleShipView::show_game_message() const {
    std::cout << model->get_game_message() << std::endl;
}


BattleShipView::BattleShipView(BattleShipModel *bs_model) {
    model = bs_model;
    model->add_view(this);
}