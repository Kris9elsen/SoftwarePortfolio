#include "Hero.hpp"

Hero::Hero() {}
Hero::~Hero() {}

Hero::Hero(std::string _name) {
    name = _name;
    xp = 0;
    level = 1;
    strength = 2;
    hp = 10;
}

// Add xp and check for level up
void Hero::addXp(int xpToAdd) {
    xp += xpToAdd;

    int xpScaler = 1000;

    while (true) {
        int xpToLevel = level * xpScaler;

        if (xpToLevel <= xp) {
            level += 1;
            strength += 1;
            hp += 2;
            xp -= xpToLevel;

        } else {
            return;
        }
    }

    return;
}

// Getters

// Returns Hp
int Hero::getHp() {
    return hp;
}

// Returns Strength
int Hero::getStrength() {
    return strength;
}

// Returns level
int Hero::getLevel() {
    return level;
}

// Returns Name
std::string Hero::getName() {
    return name;
}