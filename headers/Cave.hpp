#ifndef CAVE_HPP
#define CAVE_HPP

#pragma once

#include "Enemy.hpp"

#include <vector>

class Cave
{
public:
    Cave();
    ~Cave();
    Cave(std::vector<Enemy>);

    bool isClear() const;

    int getGold() const;
    std::vector<Enemy> getEnemies() const;


protected:
    std::vector<Enemy> enemies;
    int gold;
    
};

#endif