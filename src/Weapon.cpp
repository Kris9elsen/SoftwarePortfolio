#include "Weapon.hpp"

Weapon::Weapon(){}
Weapon::~Weapon(){}

Weapon::Weapon(std::string _name, int _damage, int _damageMultiplier, int _durability, int _price) {
    name = _name;
    price = _price;
    damage = _damage;
    damageMultiplier = _damageMultiplier;
    durability = _durability;
}

// Methods

void Weapon::use() {
    durability -= 1;
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

// Returns durability
int Weapon::getDurability() const {
    return durability;
}