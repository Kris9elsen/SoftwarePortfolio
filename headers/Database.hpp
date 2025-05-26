#ifndef DATABASE_HPP
#define DATABASE_HPP

#pragma once

#include <sqlite3.h>
#include <string>
#include <iostream>
#include <vector>
#include <optional>

#include "Hero.hpp"
#include "Weapon.hpp"

class Database
{
public:
    Database();
    ~Database();
    Database(std::string);

    // Methods for gamelogic
    bool createTables();
    std::vector<Hero> loadHero();
    void saveHero(Hero);
    std::vector<Weapon> loadWeapons();
    void addKill(const std::string heroName, const std::string weaponName);

    // See statistics
    void seeHeros();
    void seeKillsPerHero();
    void killsByWeaponForHero(std::string);
    void killsByHeroForWeapon(std::string);

private:
    sqlite3* db;

};

#endif