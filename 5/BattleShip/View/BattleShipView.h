//
// Created by Mikhail Okan on 25.12.2021.
//

#ifndef LAB4_BATTLESHIPVIEW_H
#define LAB4_BATTLESHIPVIEW_H

#include <iostream>
#include <array>

#include "../BaseClasses/BaseView.h"
#include "../Model/BattleShipModel.h"

#if defined _WIN32
#include <windows.h>
#define RED "Color 04"
#define GREEN "Color 02"
#define YELLOW "Color 06"
#define BLUE "Color 0B"
#define RESET "Color 07"
#else
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[36m"
#endif

class BattleShipView: BaseView {
private:
    BattleShipModel *model;
public:

    explicit BattleShipView(BattleShipModel *bs_model);

    ~BattleShipView() = default;

    void update() const override;

    void show_win_message() const;

    void show_game_message() const;

};



#endif //LAB4_BATTLESHIPVIEW_H
