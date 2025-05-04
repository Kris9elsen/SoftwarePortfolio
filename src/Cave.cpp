#include "Cave.hpp"

Cave::Cave() {}
Cave::~Cave() {}

Cave::Cave(std::string _name, std::vector<Enemy> _enemies, int _gold) {
    name = _name;
    enemies = _enemies;
    gold = _gold;
}

// Checks if cave has been cleared and returns true/false
bool Cave::isClear() const {
    return enemies.empty();
}

// Returns cave name
std::string Cave::getName() const {
    return name;
}
// Returns enemies in cave
std::vector<Enemy> Cave::getEnemies() const {
    return enemies;
}

// Returns Gold for cave completion
int Cave::getGold() const {
    return gold;
}