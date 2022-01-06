cmake_minimum_required(VERSION 3.20)


set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
        CACHE STRING "Vcpkg toolchain file")

project(BattleShipGame)

set(CMAKE_CXX_STANDARD 17)

include_directories(BattleShip/)
include_directories(BattleShip/Board)




add_executable(BattleShipGame main.cpp BattleShip/View/BattleShipView.cpp BattleShip/View/BattleShipView.h BattleShip/Model/BattleShipModel.cpp BattleShip/Model/BattleShipModel.h BattleShip/Controller/BattleShipController.cpp BattleShip/Controller/BattleShipController.h BattleShip/BaseClasses/BaseView.h BattleShip/BaseClasses/BaseGamer.cpp BattleShip/BaseClasses/BaseGamer.h BattleShip/Gamers/ConsoleGamer.cpp BattleShip/Gamers/ConsoleGamer.h BattleShip/Gamers/RandomGamer.cpp BattleShip/Gamers/RandomGamer.h BattleShip/Gamers/OptimalGamer.cpp BattleShip/Gamers/OptimalGamer.h BattleShip/Controller/ScenarioViewer.cpp BattleShip/Controller/ScenarioViewer.h)


find_package(cxxopts CONFIG REQUIRED)

target_link_libraries(BattleShipGame PRIVATE cxxopts::cxxopts)