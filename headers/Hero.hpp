#ifndef HERO_HPP
#define HERO_HPP

#pragma once

#include "Weapon.hpp"

#include <string>

class Hero {
public:
    Hero();
    ~Hero();
    Hero(std::string, int _hp = 10, int _strength = 2, int _level = 1, int _xp = 0, int _gold = 0);

    // Methods
    void addXp(int);
    void addGold(int);
    void giveWeapon(Weapon);
    void removeWeapon();
    int useWeapon();

    // Getters
    int getHp() const;
    int getStrength() const;
    int getLevel() const;
    int getXp() const;
    int getGold() const;
    std::string getName() const;
    Weapon getWeapon() const;

protected:
    std::string name;
    int xp;
    int level;
    int strength;
    int hp;
    int gold;

    Weapon weapon;

};

#endif