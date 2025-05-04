#ifndef ENEMY_HPP
#define ENEMY_HPP

#pragma once

#include <string>

class Enemy
{
public:
    Enemy();
    ~Enemy();
    Enemy(std::string, int, int, int);

    int getHp() const;
    int getStrength() const;
    int getXpReward() const;
    std::string getName() const;

protected:
    std::string name;
    int hp;
    int strength;
    int xpReward;

};

#endif