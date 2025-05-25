#ifndef GAMELOGIC_HPP
#define GAMELOGIC_HPP

#pragma once

#include "Hero.hpp"
#include "Enemy.hpp"
#include "Cave.hpp"
#include "GoblinCaveFactory.hpp"
#include "HorseCaveFactory.hpp"
#include "MonkeyCaveFactory.hpp"
#include "UnicornCaveFactory.hpp"
#include "DragonCaveFactory.hpp"
#include "Weapon.hpp"
#include "Database.hpp"

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
    void saveHero();
    void createHero(std::string);
    void setCaves(std::vector<Cave> _caves = {});
    void setArmory(std::vector<Weapon> _weapons = {});
    bool fightEnemy(Enemy);

    // Screens
    void startScreen();
    void menuScreen();
    void chooseCaveScreen();
    void chooseEnemyScreen(int);
    void armoryScreen();
    
protected:
    std::string fileName;
    Database db;
    Hero hero;
    std::vector<Cave> caves;
    std::vector<Weapon> armory;

};

#endif