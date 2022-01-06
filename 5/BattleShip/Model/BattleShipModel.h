//
// Created by Mikhail Okan on 25.12.2021.
//

#ifndef LAB4_BATTLESHIPMODEL_H
#define LAB4_BATTLESHIPMODEL_H

#include <cctype>
#include <tuple>
#include <string>
#include <array>
#include "../BaseClasses/BaseView.h"

#define EMPTY_CELL  ' '
#define SHIP 'x'
#define HITTED_SHIP '#'
#define MISS '.'

#define BOARD_SIZE 10

class BattleShipModel {
private:
    typedef std::array<std::array<char, 10>, 10> board_type;

    BaseView*       view{};
    int             winner{0};                  // 0 - no winner, 1 or 2 - winner and end of the game
    board_type      boards[4]{};                // 0 - p1, 1 - p2, 2 - p1 can see, 3 - p2 can see
    int             sets[2][4]{};               // sets of ships for 1st and 2nd player
    int             player_scores[2]{};         // 20 - default, 4*1+3*2+2*3+1*4, 0 = lose
    bool            current_player{false};      // 0 or 1
    std::string     game_message{};
    size_t          turn_number{0};
    size_t          awaiting_ship{3};

    bool check_possibility_to_set(const std::string& c0, const std::string& c1);

    void is_end();
public:
    BattleShipModel();
    ~BattleShipModel() = default;

    void add_view(BaseView *bs_view);

    int  hit(const std::string& c);
    bool set(const std::string& c) {return set(c, c);}
    bool set(const std::string& c0, const std::string& c1);

    void set_current_player(bool player);

    void next_place_message();

    [[nodiscard]] int                                   get_winner()           const;
    [[nodiscard]] size_t                                get_turn_number()      const;
    [[nodiscard]] bool                                  get_current_player()   const;
    [[nodiscard]] std::string                           get_game_message()     const;
    [[nodiscard]] std::tuple<board_type, board_type>    get_boards()           const;
    [[nodiscard]] size_t                                get_awaiting_ship()    const;
};


#endif //LAB4_BATTLESHIPMODEL_H
