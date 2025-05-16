#include "GameLogic.hpp"

#include <iostream>


int main() {
    GameLogic game("../saves.txt");

    
    game.startScreen();
    game.setCaves();
    game.setArmory();
    game.armoryScreen();
    game.chooseCaveScreen();

    return 0;
}