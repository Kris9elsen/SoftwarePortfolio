#ifndef GAMELOGIC_HPP
#define GAMELOGIC_HPP

#pragma once

#include "Hero.hpp"
#include "Enemy.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class GameLogic {
public:
    GameLogic();
    ~GameLogic();
    GameLogic(std::string);

    void loadHero();
    void createHero(std::string);
    void startScreen();
    void chooseEnemyScreen();
    void fightEnemy(int);
    void saveHero();

protected:
    std::string fileName;
    Hero hero;
    std::vector<Enemy> enemies;

};

#endif