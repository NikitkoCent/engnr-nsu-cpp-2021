# BattleShip Game

C++ implementation of a battleship game in terminal

# Build
    cd build && cmake .. && make
# Launch settings
    ./BattleShipGame -f [first player model] -s [second player model] -c [session count] -p [password1] -p [password2]
    Player models: interactive - play from terminal, random - random bot, optimal - optimal bot
    All arguments are important

# Gameplay
The game allows two users (bots) to play the classic game of Battleship with a 10x10 board.
Each player has a set with 1x4 2x3 3x2 and 4x1 ships.
In the first stage, players need to place ships on their boards, passing the first and last coordinates of the ship (or only one if they match).
In the second stage, players take turns entering one coordinate - the cell they want to attack.
If you play versus bot, you won't see it's board, if you play with your another person, each time you change a player, 
you will need to enter a password, which is set by the -p argument for this player.

# Screenshot
![plot](images/bs_demo.jpeg)