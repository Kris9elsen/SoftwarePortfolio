#include "GameLogic.hpp"

#include <iostream>


int main() {
    GameLogic game("../saves.txt");

    game.setEnemies();
    game.startScreen();
    game.chooseEnemyScreen();

    return 0;
}