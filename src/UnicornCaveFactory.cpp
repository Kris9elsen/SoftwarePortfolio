#include "UnicornCaveFactory.hpp"

// Returns Cave with enemies of the right strenght
Cave UnicornCaveFactory::createCave(const Hero& hero) {
    std::vector<Enemy> enemies;

    // Create Colt/Filly Unicorn
    enemies.push_back(Enemy("Colt Unicorn", hero.getHp() + 4, hero.getStrength() + 2, hero.getLevel() * 1000 / 2));
    enemies.push_back(Enemy("Filly Unicorn", hero.getHp() + 4, hero.getStrength() + 2, hero.getLevel() * 1000 / 2));
    enemies.push_back(Enemy("Colt Unicorn", hero.getHp() + 4, hero.getStrength() + 2, hero.getLevel() * 1000 / 2));

    // Creates Unicorns
    enemies.push_back(Enemy("Unicorn", hero.getHp() + 6, hero.getStrength() + 3, hero.getLevel() * 1000 / 2));
    enemies.push_back(Enemy("Unicorn", hero.getHp() + 6, hero.getStrength() + 3, hero.getLevel() * 1000 / 2));
    enemies.push_back(Enemy("Unicorn", hero.getHp() + 6, hero.getStrength() + 3, hero.getLevel() * 1000 / 2));

    // Creates Mutated Unicorns
    enemies.push_back(Enemy("Mutated Unicorn", hero.getHp() + 8, hero.getStrength() + 4, hero.getLevel() * 1000 / 2));
    enemies.push_back(Enemy("Mutated Unicorn", hero.getHp() + 8, hero.getStrength() + 4, hero.getLevel() * 1000 / 2));
    enemies.push_back(Enemy("Mutated Unicorn", hero.getHp() + 8, hero.getStrength() + 4, hero.getLevel() * 1000 / 2));

    return Cave("Unicorn Cave", enemies, 1500);
}