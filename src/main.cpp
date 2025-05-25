#include "GameLogic.hpp"

#include <iostream>


int main() {
    GameLogic game("../gameData.db");

    
    game.startScreen();
    game.setCaves();
    game.setArmory();
    game.menuScreen();

    return 0;
}