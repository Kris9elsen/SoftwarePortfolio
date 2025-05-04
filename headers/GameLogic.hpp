#ifndef GAMELOGIC_HPP
#define GAMELOGIC_HPP

#pragma once

#include "Hero.hpp"
#include "Enemy.hpp"

#include <string>
#include <vector>

class GameLogic {
public:
    GameLogic();
    ~GameLogic();

    void loadHero(std::string);
    void createHero(std::string);
    void startScreen();
    void chooseEnemyScreen();
    void fightEnemy(int);

protected:
    Hero hero;
    std::vector<Enemy> enemies;

};

#endif