#ifndef HERO_HPP
#define HERO_HPP

#pragma once

#include <string>

class Hero {
public:
    Hero();
    ~Hero();
    Hero(std::string, int, int, int, int);

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