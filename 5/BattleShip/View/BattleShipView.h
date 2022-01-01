//
// Created by Mikhail Okan on 25.12.2021.
//

#ifndef LAB4_BATTLESHIPVIEW_H
#define LAB4_BATTLESHIPVIEW_H

#include <iostream>
#include <array>

#include "../BaseClasses/BaseView.h"
#include "../Model/BattleShipModel.h"


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
