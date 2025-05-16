#include "Weapon.hpp"

Weapon::Weapon(){}
Weapon::~Weapon(){}

Weapon::Weapon(std::string _name, int _price, int _damage, int _damageMultiplier) {
    name = _name;
    price = _price;
    damage = _damage;
    damageMultiplier = _damageMultiplier;
}

// Getters

// Returns weapon name
std::string Weapon::getName() const {
    return name;
}

// Returns weapon price
int Weapon::getPrice() const {
    return price;
}

// Returns weapon damage
int Weapon::getDamage() const {
    return damage;
}

// Returns damage multiplier
int Weapon::getDamageMultiplier() const {
    return damageMultiplier;
}