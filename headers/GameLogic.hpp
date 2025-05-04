#ifndef GAMELOGIC_HPP
#define GAMELOGIC_HPP

#pragma once

#include "Hero.hpp"
#include "Enemy.hpp"
#include "Cave.hpp"
#include "GoblinCaveFactory.hpp"

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
    void chooseCaveScreen();
    void chooseEnemyScreen(int);
    bool fightEnemy(Enemy);
    void saveHero();
    void setCaves(std::vector<Cave> _caves = {});

protected:
    std::string fileName;
    Hero hero;
    std::vector<Cave> caves;

};

#endif