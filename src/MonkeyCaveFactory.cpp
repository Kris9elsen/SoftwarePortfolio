#include "MonkeyCaveFactory.hpp"

// Returns Cave with enemies of the right strenght
Cave MonkeyCaveFactory::createCave(const Hero& hero) {
    std::vector<Enemy> enemies;

    // Create Monkey
    enemies.push_back(Enemy("Monkey", hero.getHp(), hero.getStrength(), hero.getLevel() * 1000 / 2));
    enemies.push_back(Enemy("Monkey", hero.getHp(), hero.getStrength(), hero.getLevel() * 1000 / 2));
    enemies.push_back(Enemy("Monkey", hero.getHp(), hero.getStrength(), hero.getLevel() * 1000 / 2));

    // Creates Gorilla
    enemies.push_back(Enemy("Gorilla", hero.getHp() + 2, hero.getStrength() + 1, hero.getLevel() * 1000 / 2));
    enemies.push_back(Enemy("Gorilla", hero.getHp() + 2, hero.getStrength() + 1, hero.getLevel() * 1000 / 2));
    enemies.push_back(Enemy("Gorilla", hero.getHp() + 2, hero.getStrength() + 1, hero.getLevel() * 1000 / 2));

    // Creates The Monkey Lords
    enemies.push_back(Enemy("Monkey Queen", hero.getHp() + 4, hero.getStrength() + 2, hero.getLevel() * 1000 / 2));
    enemies.push_back(Enemy("Monkey King", hero.getHp() + 4, hero.getStrength() + 2, hero.getLevel() * 1000 / 2));
    enemies.push_back(Enemy("Monkey God", hero.getHp() + 4, hero.getStrength() + 2, hero.getLevel() * 1000 / 2));

    return Cave("Monkey Cave", enemies, 1000);
}