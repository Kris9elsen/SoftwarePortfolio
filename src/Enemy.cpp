#include "Enemy.hpp"

Enemy::Enemy() {}
Enemy::~Enemy() {}

Enemy::Enemy(std::string _name, int _hp, int _strength, int _xpReward) {
    name = _name;
    hp = _hp;
    strength = _strength;
    xpReward = _xpReward;
}

// Getters

// Returns hp
int Enemy::getHp() const {
    return hp;
}

// Returns Strength
int Enemy::getStrength() const {
    return strength;
}

// Returns xpReward
int Enemy::getXpReward() const {
    return xpReward;
}

// Returns name
std::string Enemy::getName() const {
    return name;
}
