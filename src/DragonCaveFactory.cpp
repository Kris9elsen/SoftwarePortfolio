#include "DragonCaveFactory.hpp"

// Returns Cave with enemies of the right strenght
Cave DragonCaveFactory::createCave(const Hero& hero) {
    std::vector<Enemy> enemies;

    // Create poison Dragon
    enemies.push_back(Enemy("Poison Dragon", hero.getHp() + 8, hero.getStrength() + 4, hero.getLevel() * 1000 / 2));
    enemies.push_back(Enemy("Poison Dragon", hero.getHp() + 8, hero.getStrength() + 4, hero.getLevel() * 1000 / 2));
    enemies.push_back(Enemy("Poison Dragon", hero.getHp() + 8, hero.getStrength() + 4, hero.getLevel() * 1000 / 2));

    // Creates Fire Dragon
    enemies.push_back(Enemy("Fire Dragon", hero.getHp() + 10, hero.getStrength() + 5, hero.getLevel() * 1000 / 2));
    enemies.push_back(Enemy("Fire Dragon", hero.getHp() + 10, hero.getStrength() + 5, hero.getLevel() * 1000 / 2));
    enemies.push_back(Enemy("Fire Dragon", hero.getHp() + 10, hero.getStrength() + 5, hero.getLevel() * 1000 / 2));

    // Creates Lightning Dragon
    enemies.push_back(Enemy("Lightning Dragon", hero.getHp() + 12, hero.getStrength() + 6, hero.getLevel() * 1000 / 2));
    enemies.push_back(Enemy("Lightning Dragon", hero.getHp() + 12, hero.getStrength() + 6, hero.getLevel() * 1000 / 2));
    enemies.push_back(Enemy("Lightning Dragon", hero.getHp() + 12, hero.getStrength() + 6, hero.getLevel() * 1000 / 2));

    return Cave("Dragon Cave", enemies, 2000);
}