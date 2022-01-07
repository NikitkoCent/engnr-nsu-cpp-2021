# BattleShip Game

C++ implementation of a battleship game in terminal

# Build
    cd build && cmake .. && make
# Launch settings
    ./BattleShipGame -f [str] -s [str] -c [int] -p [str] -p [str] 

    Important arguments:
    -f   --first      model for first player
    -s   --second     model for second player
    -c   --count      sessions count
    -p   --password   password for first/second player

    Optional arguments:
    -h --help print help/tutorial
# Player models: 
    interactive - play from terminal
    random - random bot
    optimal - optimal bot, optimal placement
    imbalanced - imbalanced bot, optimal placement + optimal attacks

# Gameplay
The game allows two users (bots) to play the classic game of Battleship with a 10x10 board.
Each player has a set with 1x4 2x3 3x2 and 4x1 ships.
In the first stage, players need to place ships on their boards, passing the first and last coordinates of the ship (or only one if they match).
In the second stage, players take turns entering one coordinate - the cell they want to attack.
If you play versus bot, you won't see it's board, if you play with your another person, each time you change a player, 
you will need to enter a password, which is set by the -p argument for this player.
If you want, you can see tutorial in -h

# Screenshot
![screenshot](https://raw.githubusercontent.com/okm-lab/engnr-nsu-cpp-2021/lab5/5/Images/bs_demo.jpeg)