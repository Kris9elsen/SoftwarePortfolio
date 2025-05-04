#ifndef HERO_HPP
#define HERO_HPP

#pragma once

#include <string>

class Hero {
public:
    Hero();
    ~Hero();
    Hero(std::string, int _hp = 10, int _strength = 2, int _level = 1, int _xp = 0);

    // Methods
    void addXp(int);

    // Getters
    int getHp() const;
    int getStrength() const;
    int getLevel() const;
    std::string getName() const;

protected:
    std::string name;
    int xp;
    int level;
    int strength;
    int hp;

};

#endif