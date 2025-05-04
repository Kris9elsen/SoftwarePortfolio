#include "HorseCaveFactory.hpp"

// Returns Cave with enemies of the right strenght
Cave HorseCaveFactory::createCave(const Hero& hero) {
    std::vector<Enemy> enemies;

    // Create Colt/Filly Horse
    enemies.push_back(Enemy("Colt Horse", hero.getHp() / 2, hero.getStrength() / 2, hero.getLevel() * 1000 / 2));
    enemies.push_back(Enemy("Filly Horse", hero.getHp() / 2, hero.getStrength() / 2, hero.getLevel() * 1000 / 2));
    enemies.push_back(Enemy("Colt Horse", hero.getHp() / 2, hero.getStrength() / 2, hero.getLevel() * 1000 / 2));

    // Creates Horse
    enemies.push_back(Enemy("Horse", hero.getHp(), hero.getStrength(), hero.getLevel() * 1000 / 2));
    enemies.push_back(Enemy("Horse", hero.getHp(), hero.getStrength(), hero.getLevel() * 1000 / 2));
    enemies.push_back(Enemy("Horse", hero.getHp(), hero.getStrength(), hero.getLevel() * 1000 / 2));

    // Creates Mutated Horse
    enemies.push_back(Enemy("Mutated Horse", hero.getHp() + 2, hero.getStrength() + 1, hero.getLevel() * 1000 / 2));
    enemies.push_back(Enemy("Mutated Horse", hero.getHp() + 2, hero.getStrength() + 1, hero.getLevel() * 1000 / 2));
    enemies.push_back(Enemy("Mutated Horse", hero.getHp() + 2, hero.getStrength() + 1, hero.getLevel() * 1000 / 2));

    return Cave("Horse Cave", enemies, 500);
}