#include <thread>
#include <chrono>

#include <cxxopts.hpp>

#include "BattleShip/View/BattleShipView.h"
#include "BattleShip/Controller/BattleShipController.h"
#include "BattleShip/Gamers/OptimalGamer.h"
#include "BattleShip/Gamers/ConsoleGamer.h"
#include "BattleShip/Gamers/RandomGamer.h"
#include "BattleShip/Controller/ScenarioViewer.h"

void clear()
{
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__) || defined (__APPLE__)
    auto a = system("clear"); (void)a;
#endif
}


void start_tutorial() {
    using namespace std::chrono_literals;
    BattleShipModel model;
    BattleShipView view(&model);
    ScenarioViewer viewer(&model);
    viewer.load("../Scenario/game_log_0.txt");
    for (int i = 0; i < 6; i++) {
        std::string coords = viewer.next();
        std::cout << "In the first 6 turns, your or your opponent (or bot) must enter 2 numbers - the first and last coordinates of the ship that you want to place\nFor exmample, as you see on the board, " + coords + "\n";
        std::this_thread::sleep_for(1000ms);
    }

    for (int i = 0; i < 4; i++) {
        viewer.next();
        std::cout << "In the next 4 turns, you need to enter only one coordinate - for a ship of length 1\n\n";
        std::this_thread::sleep_for(1000ms);
    }
    clear();
    std::cout << "Doesn't sound difficult, right?\n"
                 "For this manual I had to use the non-hired labor of two slaves (bots), so you can see what your opponent will do.\n"
                 "Let's see our opponent board.\n"
                 "Enter something to continue...\n";
    getchar();

    for (int i = 0; i < 10; i++) {
        std::string coords = viewer.next();
        std::this_thread::sleep_for(500ms);
    }
    clear();
    std::cout << "Well, now you know about placement stage.\n"
                 "That last thing you want to know is attack stage.\n"
                 "So... Just enter 1 coordinate to attack the enemy in this cell, then еру enemy will attack your cell...\n"
                 "And so until someone destroys all opponent ships.\n"
                 "if you want, you can watch the game, or you can press ctrl + c and exit the tutorial\n"
                 "Anyway, good luck, have fun!";
    getchar();
    model.update_player_status(1, true);
    model.update_player_status(0, false);
    while (!viewer.eof()) {
        std::string coords = viewer.next();
        std::this_thread::sleep_for(100ms);
    }
}

void print_help() {
    char arg;
    std::cout << "Hey! It's time to read the instructions, right? Enter 1 if you want to see the tutorial, otherwise 2 if you just want to see the command line arguments.\n" << std::endl;
    std::cin >> arg;
    if (arg == '1') {
        start_tutorial();
    } else {
        std::cout << "Usage: ./BattleShipGame -f [first player model] -s [second player model] -c [session count]" << std::endl;
        std::cout << "Player models: interactive - play from console, random - random bot, optimal - optimal bot" << std::endl;
    }
}

int main(int argc, char** argv) {

    cxxopts::Options options("BattleShipGame", "");
    options.add_options()
            ("f,first", "First model", cxxopts::value<std::string>())
            ("s,second", "Second model", cxxopts::value<std::string>())
            ("h,help", "Print help", cxxopts::value<bool>()->default_value("false"))
            ("c,count", "Session count", cxxopts::value<int>()->default_value("1"));

    auto result = options.parse(argc, argv);
    if (result["h"].as<bool>()) {
        print_help();
        return 0;
    }
    BattleShipModel model;
    BaseGamer *g1, *g2;
    if (result["f"].as<std::string>() == "interactive") {
        g1 = new ConsoleGamer(&model);
    } else if (result["f"].as<std::string>() == "random") {
        g1 = new RandomGamer(&model);
    } else if (result["f"].as<std::string>() == "optimal") {
        g1 = new OptimalGamer(&model);
    } else {
        std::cerr << "Wrong --first argument!";
        return 1;
    }

    if (result["s"].as<std::string>() == "interactive") {
        g2 = new ConsoleGamer(&model);
    } else if (result["s"].as<std::string>() == "random") {
        g2 = new RandomGamer(&model);
    } else if (result["s"].as<std::string>() == "optimal") {
        g2 = new OptimalGamer(&model);
    } else {
        std::cerr << "Wrong --second argument!";
        return 1;
    }

    BattleShipView view(&model);
    BattleShipController controller(&model, g1, g2);
    controller.start(result["c"].as<int>());

}
