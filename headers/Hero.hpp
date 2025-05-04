#ifndef HERO_HPP
#define HERO_HPP

#include <string>

#pragma once

class Hero {
public:
    Hero();
    ~Hero();
    Hero(std::string);

    // Methods
    void addXp(int);

    // Getters
    int getHp();
    int getStrength();
    int getLevel();
    std::string getName();

protected:
    std::string name;
    int xp;
    int level;
    int strength;
    int hp;

};

#endif