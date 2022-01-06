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
#define SHIP '#'
#define HITTED_SHIP 'x'
#define MISS '@'
#define PROCESSING_CELL '*'
#define BOARD_SIZE 10

using std::string;


class BattleShipModel {
private:
    typedef std::array<std::array<char, 10>, 10> btype;

    BaseView*       view{};
    int             winner{0};                  // 0 - no winner, 1 or 2 - winner and end of the game
    btype           boards[4]{};                // 0 - p1, 1 - p2, 2 - p1 can see, 3 - p2 can see
    int             sets[2][4]{};               // sets of ships for 1st and 2nd player
    int             player_scores[2]{};         // 20 - default, 4*1+3*2+2*3+1*4, 0 = lose
    bool            current_player{false};      // 0 or 1
    std::string     game_message{};
    size_t          turn_number{0};
    int          awaiting_ship{3};           // awaiting len - 1, exactly YY - XX
    bool            is_bot[2]{};

    void mark_halos_around_destroyed_ship(size_t board_number, size_t enemy_board_number, int x, int y); // x, y - one pair of points that the ship contains
    bool check_ship_destroyed(size_t board_number, int x, int y);
    void next_place_message();
    void check_winner();
    void update_view();

public:
    BattleShipModel();
    ~BattleShipModel() = default;

    void add_view(BaseView *bs_view);
    void update_player_status(int player, bool bot);

    int  hit(const std::string& c);
    bool set(const std::string& c) {return set(c, c);}
    bool set(const std::string& c0, const std::string& c1);

    void reset();

    [[nodiscard]] std::tuple<btype, btype>    get_boards()                                                    const;
    [[nodiscard]] int                         get_winner()                                                    const;
    [[nodiscard]] size_t                      get_turn_number()                                               const;
    [[nodiscard]] std::string                 get_game_message()                                              const;
    [[nodiscard]] int                         get_awaiting_ship()                                             const;
    [[nodiscard]] bool                        get_current_player()                                            const;
    [[nodiscard]] bool                        check_neighbour_ships(int x, int y)                             const;
    [[nodiscard]] int                         check_cell_to_hit(const string& c)                              const;
    [[nodiscard]] bool                        check_possibility_to_set(const string& c0, const string& c1)    const;
};


#endif //LAB4_BATTLESHIPMODEL_H
