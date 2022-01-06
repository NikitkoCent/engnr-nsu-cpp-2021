#include "BattleShip/View/BattleShipView.h"
#include "BattleShip/Controller/BattleShipController.h"

#include "BattleShip/Gamers/OptimalGamer.h"
#include "BattleShip/Gamers/ConsoleGamer.h"
#include "BattleShip/Gamers/RandomGamer.h"


int main() {
    BattleShipModel model;
    BattleShipView view(&model);
    OptimalGamer g1(&model);
    RandomGamer g2(&model);
    BattleShipController controller(&model, &g1, &g2);
    controller.start();
    //A0 A3 C0 E0 G0 I0 J2 J3 J5 J6 J8 J9 D4 F6 A9 F8

}
