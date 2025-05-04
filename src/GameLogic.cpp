#include "GameLogic.hpp"

GameLogic::GameLogic() {}
GameLogic::~GameLogic() {}

// Create new hero
void GameLogic::createHero(std::string name) {
    hero = Hero(name);
}

// Load Hero from file
void GameLogic::loadHero(std::string fileName) {
    
}