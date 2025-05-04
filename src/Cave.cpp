#include "Cave.hpp"

Cave::Cave() {}
Cave::~Cave() {}

Cave::Cave(std::vector<Enemy> _enemies) {
    enemies = _enemies;
}

// Checks if cave has been cleared and returns true/false
bool Cave::isClear() const {
    return enemies.empty();
}

// Returns enemies in cave
std::vector<Enemy> Cave::getEnemies() const {
    return enemies;
}

// Returns Gold for cave completion
int Cave::getGold() const {
    return gold;
}