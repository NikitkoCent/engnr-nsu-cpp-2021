#include <cmath>
#include <vector>
#include "BattleShip/View/BattleShipView.h"
#include "BattleShip/Controller/BattleShipController.h"
#include <climits>

class RandomGamer: public BaseBot {
public:
    explicit RandomGamer(BattleShipModel *m): BaseBot(m) {
        get_engine().seed(std::time(nullptr));
        alphabet = "ABCDEFGHIJ";
    }
    std::vector<std::string> turn_set_stage(size_t args_count) override {
        return random_generate_next_turn(args_count);
    }
    std::vector<std::string> turn_attack_stage(size_t args_count) override {
        return random_generate_next_turn(args_count);
    }

};


class ConsoleGamer: public BaseGamer {
public:
    explicit ConsoleGamer(BattleShipModel *m): BaseGamer(m) {}
    std::vector<std::string> turn_set_stage(size_t args_count) override {
        std::string s;
        std::vector<std::string> v;
        for (int i = 0; i < args_count; i++) {
            std::cin >> s;
            v.push_back(s);
        }
        return v;
    }

    std::vector<std::string> turn_attack_stage(size_t args_count) override {
        return turn_set_stage(args_count);
    }
};


class OptimalGamer: public BaseBot {
private:
    struct Coords {
        int x0, y0, x1, y1;
    };

    static void mark_as_halo(int halos[10][10], int x, int y) {
        if (x >= 0 && x <= 9 && y >= 0 && y <= 9)
            halos[x][y] = 10000;
    }

    static bool is_halo(int halos[10][10], int x, int y) {
        if (x >= 0 && x <= 9 && y >= 0 && y <= 9)
            return halos[x][y] == 10000;
        return true;
    }

    static void set_halo_around_ship(int halos[10][10], int x, int y) {
        for (int i = x-1; i <= x+1; i++) {
            for (int j=y-1; j <= y+1; j++) {
                mark_as_halo(halos, i, j);
            }
        }
    }

    static void evaluate_point(int halos[10][10], int x, int y) {
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

    static void mark_halos(std::array<std::array<char, 10>, 10> board, int halo[10][10]) {
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

    static int evaluate_ship_coords(int halos[10][10], int x0, int y0, int x1, int y1) {
        int loc_sum=0;
        for (int i = x0; i <= x1; i++) {
            for (int j = y0; j <= y1; j++) {
                loc_sum += halos[i][j];
            }
        }
        return loc_sum;
    }

public:
    explicit OptimalGamer(BattleShipModel *m) : BaseBot(m) {}

    Coords get_optimal_points() {
        auto board = std::get<0>(model->get_boards());
        int length = model->get_awaiting_ship();
        int board_halos[10][10]{0};
        mark_halos(board, board_halos);
        int x0, y0, x1, y1, loc_sum, max_s=INT_MAX;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (i+length <= 9) {
                    loc_sum = evaluate_ship_coords(board_halos, i, j, i + length, j);
                    if (loc_sum < max_s) {max_s = loc_sum; x0 = i; y0 = j; x1=i+length; y1=j;}
                }
                if (j+length <= 9) {
                    loc_sum = evaluate_ship_coords(board_halos, i, j, i, j + length);
                    if (loc_sum < max_s) {max_s = loc_sum; x0 = i; y0 = j; x1=i; y1=j+length;}
                }
            }
        }
        return Coords{y0, x0, y1, x1};
    }

    std::vector<std::string> turn_set_stage(size_t args_count) override {
        std::vector<std::string> v;
        Coords cds = get_optimal_points();
        v.push_back(std::string() + alphabet[cds.x0] + std::to_string(cds.y0));
        v.push_back(std::string() + alphabet[cds.x1] + std::to_string(cds.y1));
        return v;
    }

    std::vector<std::string> turn_attack_stage(size_t args_count) override {
        return random_generate_next_turn(args_count);
    }
};


int main() {
    BattleShipModel model;
    BattleShipView view(&model);
    OptimalGamer g1(&model);
    ConsoleGamer g2(&model);
    BattleShipController controller(&model, &g1, &g2);
    controller.start();
}
