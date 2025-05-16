#include "Hero.hpp"

Hero::Hero() {}
Hero::~Hero() {}

Hero::Hero(std::string _name, int _hp, int _strength, int _level, int _xp, int _gold) {
    name = _name;
    xp = _xp;
    level = _level;
    strength = _strength;
    hp = _hp;
    gold = _gold;
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

// Add gold to hero
void Hero::addGold(int _gold) {
    gold += _gold;
}

// Setters

// Set hero weapon
void Hero::giveWeapon(Weapon _weapon) {
    gold -= _weapon.getPrice();
    weapon = _weapon;
}

// Getters

// Returns Hp
int Hero::getHp() const {
    return hp;
}

// Returns Strength
int Hero::getStrength() const {
    return strength;
}

// Returns level
int Hero::getLevel() const {
    return level;
}

int Hero::getXp() const {
    return xp;
}

int Hero::getGold() const {
    return gold;
}

// Returns Name
std::string Hero::getName() const {
    return name;
}

// Returns heros weapon
Weapon Hero::getWeapon() const {
    return weapon;
}