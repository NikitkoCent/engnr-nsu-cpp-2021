cmake_minimum_required(VERSION 3.20)
project(lab4)

set(CMAKE_CXX_STANDARD 17)

include_directories(BattleShip/)
include_directories(BattleShip/Board)

add_executable(lab4 main.cpp BattleShip/View/BattleShipView.cpp BattleShip/View/BattleShipView.h BattleShip/Model/BattleShipModel.cpp BattleShip/Model/BattleShipModel.h BattleShip/Controller/BattleShipController.cpp BattleShip/Controller/BattleShipController.h BattleShip/BaseClasses/BaseView.h BattleShip/BaseClasses/BaseGamer.cpp BattleShip/BaseClasses/BaseGamer.h BattleShip/Gamers/ConsoleGamer.cpp BattleShip/Gamers/ConsoleGamer.h BattleShip/Gamers/RandomGamer.cpp BattleShip/Gamers/RandomGamer.h BattleShip/Gamers/OptimalGamer.cpp BattleShip/Gamers/OptimalGamer.h)
