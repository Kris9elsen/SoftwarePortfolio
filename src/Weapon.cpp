#include "Weapon.hpp"

Weapon::Weapon(){}
Weapon::~Weapon(){}

Weapon::Weapon(int _price, int _damage, int _damageMultiplier) {
    price = _price;
    damage = _damage;
    damageMultiplier = _damageMultiplier;
}

// Getters

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