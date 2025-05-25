#include "GameLogic.hpp"

#include <iostream>


int main() {
    GameLogic game("../saves.txt");

    
    game.startScreen();
    game.setCaves();
    game.setArmory();
    game.menuScreen();

    return 0;
}