//
// Created by Mikhail Okan on 06.01.2022.
//

#ifndef LAB4_OPTIMALGAMER_H
#define LAB4_OPTIMALGAMER_H
#include <BaseClasses/BaseGamer.h>
#include <climits>
#include <utility>

class OptimalGamer: public BaseBot {
private:
    static bool is_halo(int halos[10][10], int x, int y);

    static void set_halo_around_ship(int halos[10][10], int x, int y);

    static void evaluate_point(int halos[10][10], int x, int y);

    static void evaluate_board(std::array<std::array<char, 10>, 10> board, int halo[10][10]);

    static int evaluate_ship_coords(int halos[10][10], int x0, int y0, int x1, int y1);

public:
    explicit OptimalGamer(BattleShipModel *m) : BaseBot(m) {}

    std::vector<std::string> turn_set_stage() override;

    std::vector<std::string> turn_attack_stage() override;
};


#endif //LAB4_OPTIMALGAMER_H
