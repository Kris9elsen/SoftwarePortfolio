#ifndef WEAPON_HPP
#define WEAPON_HPP

#pragma once

#include <string>

class Weapon
{
public:
    Weapon();
    ~Weapon();

    // string Name, int Damage, int Damage Multiplier, int durability, int Price
    Weapon(std::string, int, int, int, int);

    // Methods

    // Use weapon remove one durability
    void use();

    // Getters
    std::string getName() const;
    int getPrice() const;
    int getDamage() const;
    int getDamageMultiplier() const;
    int getDurability() const;

private:
    std::string name;
    int price;
    int damage;
    int damageMultiplier;
    int durability;

};

#endif