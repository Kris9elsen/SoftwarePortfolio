#ifndef WEAPON_HPP
#define WEAPON_HPP

#pragma once

#include <string>

class Weapon
{
public:
    Weapon();
    ~Weapon();
    Weapon(std::string, int, int, int);

    // Getters
    std::string getName() const;
    int getPrice() const;
    int getDamage() const;
    int getDamageMultiplier() const;

private:
    std::string name;
    int price;
    int damage;
    int damageMultiplier;

};

#endif