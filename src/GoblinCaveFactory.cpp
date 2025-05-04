#include "GoblinCaveFactory.hpp"

// Returns Cave with enemies of the right strenght
Cave GoblinCaveFactory::createCave(const Hero& hero) {
    std::vector<Enemy> enemies;

    // Create Weak Goblins
    enemies.push_back(Enemy("Weak Goblin", hero.getHp() / 2, hero.getStrength() / 2, hero.getLevel() * 1000 / 2));
    enemies.push_back(Enemy("Weak Goblin", hero.getHp() / 2, hero.getStrength() / 2, hero.getLevel() * 1000 / 2));
    enemies.push_back(Enemy("Weak Goblin", hero.getHp() / 2, hero.getStrength() / 2, hero.getLevel() * 1000 / 2));

    // Creates Strong Goblins
    enemies.push_back(Enemy("Strong Goblin", hero.getHp(), hero.getStrength(), hero.getLevel() * 1000 / 2));
    enemies.push_back(Enemy("Strong Goblin", hero.getHp(), hero.getStrength(), hero.getLevel() * 1000 / 2));
    enemies.push_back(Enemy("Strong Goblin", hero.getHp(), hero.getStrength(), hero.getLevel() * 1000 / 2));

    // Creates The strongest Goblins
    enemies.push_back(Enemy("The Strongest Goblin", hero.getHp() + 2, hero.getStrength() + 1, hero.getLevel() * 1000 / 2));
    enemies.push_back(Enemy("The Strongest Goblin", hero.getHp() + 2, hero.getStrength() + 1, hero.getLevel() * 1000 / 2));
    enemies.push_back(Enemy("The Strongest Goblin", hero.getHp() + 2, hero.getStrength() + 1, hero.getLevel() * 1000 / 2));

    return Cave("Goblin Cave", enemies, 500);
}