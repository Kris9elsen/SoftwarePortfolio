#ifndef WEAPON_HPP
#define WEAPON_HPP

#pragma once

class Weapon
{
public:
    Weapon();
    ~Weapon();
    Weapon(int, int, int);

    // Getters
    int getPrice() const;
    int getDamage() const;
    int getDamageMultiplier() const;

private:
    int price;
    int damage;
    int damageMultiplier;

};

#endif