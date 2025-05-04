#ifndef CAVE_HPP
#define CAVE_HPP

#pragma once

#include "Enemy.hpp"

#include <vector>
#include <string>

class Cave
{
public:
    Cave();
    ~Cave();
    Cave(std::string, std::vector<Enemy>, int);

    bool isClear() const;

    int getGold() const;
    std::string getName() const;
    std::vector<Enemy> getEnemies() const;


protected:
    std::string name;
    std::vector<Enemy> enemies;
    int gold;
    
};

#endif