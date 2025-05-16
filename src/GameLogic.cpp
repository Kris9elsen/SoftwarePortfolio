#include "GameLogic.hpp"

GameLogic::GameLogic() {}
GameLogic::~GameLogic() {
    saveHero();
    std::cout << "Saved game" << std::endl;
}

// Create game takes string "saves file name"
GameLogic::GameLogic(std::string _fileName) {
    fileName = _fileName;
}

// Create new hero
void GameLogic::createHero(std::string name) {
    hero = Hero(name);

    saveHero();

    return;
}

// Load Hero from file
void GameLogic::loadHero() {
    std::ifstream file(fileName);

    std::string line;
    std::vector<Hero> heros = {};

    std::cout << "\n=== HEROES AVAILABLE FOR LOAD ===" << std::endl;

    while (std::getline (file, line)) {
        std::stringstream ss(line);
        std::string name;
        int hp, strength, level, xp, gold;
        std::string value;

        std::getline(ss, name, ',');
        std::getline(ss, value, ','); hp = std::stoi(value);
        std::getline(ss, value, ','); strength = std::stoi(value);
        std::getline(ss, value, ','); level = std::stoi(value);
        std::getline(ss, value, ','); xp = std::stoi(value);
        std::getline(ss, value, ','); gold = std::stoi(value);

        std::cout << heros.size() << ": " << name 
                  << ", Hp = " << hp 
                  << ", Strength = " << strength 
                  << ", Level = " << level 
                  << ", Xp = " << xp
                  << ", Gold = " << gold
                  << std::endl;

        heros.push_back(Hero(name, hp, strength, level, xp, gold));

    }

    file.close();

    if (heros.empty()) {
        std::cout << "No heros saved!!" << std::endl;
        std::cout << "Enter name for your new Hero: ";
        std::cin >> line;

        createHero(line);

        std::cout << "Playing as: " << hero.getName() 
                  << ", Hp = " << hero.getHp() 
                  << ", Strength = " << hero.getStrength() 
                  << ", Level = " << hero.getLevel() 
                  << ", Xp = " << hero.getXp()
                  << ", Gold = " << hero.getGold()
                  << std::endl;

        return;
    }

    std::cout << "Enter number of hero to load: ";
    std::cin >> line;
    hero = heros[std::stoi(line)];

    std::cout << "You chose to play as: " << hero.getName() 
              << ", Hp = " << hero.getHp() 
              << ", Strength = " << hero.getStrength() 
              << ", Level = " << hero.getLevel() 
              << ", Xp = " << hero.getXp() 
              << std::endl;

    return;
}

// Saves heror to txt file or updateds if already exists
void GameLogic::saveHero() {
    std::ifstream file(fileName);
    std::vector<std::string> lines;
    std::string line;
    bool update = false;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string currentHero;
        std::getline(ss, currentHero, ',');

        if (currentHero == hero.getName()) {
            std::stringstream newLine;
            newLine << hero.getName() << "," << hero.getHp() << "," << hero.getStrength() << "," << hero.getLevel() << "," << hero.getXp() << "," << hero.getGold();
            lines.push_back(newLine.str());
            update = true;
        } else {
            lines.push_back(line);
        }
    }

    file.close();

    if (!update) {
        std::stringstream newLine;
        newLine << hero.getName() << "," << hero.getHp() << "," << hero.getStrength() << "," << hero.getLevel() << "," << hero.getXp() << "," << hero.getGold();
        lines.push_back(newLine.str());
    }

    std::ofstream outfile(fileName);
    for (const auto& l : lines) {
        outfile << l << "\n";
    }

    outfile.close();

    return;

}

// Sets Enemies takes vector<Enemy> or sets to default
void GameLogic::setCaves(std::vector<Cave> _caves) {
    if (!_caves.empty()) {
        caves = _caves;
        return;

    } else {
        GoblinCaveFactory goblinFactory;
        caves.push_back(goblinFactory.createCave(hero));

        HorseCaveFactory horseFactory;
        caves.push_back(horseFactory.createCave(hero));

        MonkeyCaveFactory monkeyFactory;
        caves.push_back(monkeyFactory.createCave(hero));

        UnicornCaveFactory unicornFactory;
        caves.push_back(unicornFactory.createCave(hero));

        DragonCaveFactory dragonFactory;
        caves.push_back(dragonFactory.createCave(hero));

        return;
    }

    return;
}

// Sets weapons in armory take vecotr<Weapon> or sets default
void GameLogic::setArmory(std::vector<Weapon> _armory) {
    if (!_armory.empty()) {
        armory = _armory;
        return;

    } else {
        armory.push_back(Weapon("Dagger", 1, 0, 100));
        armory.push_back(Weapon("Sword", 5, 1, 500));
        armory.push_back(Weapon("Morning star", 8, 2, 800));
        armory.push_back(Weapon("LMG", 20, 10, 2000));

        return;
    }

    return;
}

// Display start screen
void GameLogic::startScreen() {
    std::cout << "\n=== WELCOME TO THE GAME ===" << std::endl;
    
    while (true) {
        std::cout << "Enter create or load to get started: ";
        std::string in;
        std::cin >> in;

        if (in == "create")  {
            std::cout << "Enter name of new hero: ";
            std::cin >> in;
            createHero(in);
            return;

        } else if (in == "load") {
            loadHero();
            return;
        } else {
            std::cout << "Not a valid input" << std::endl;
        }
    }
   
    return;
}

// Display Cave selector
void GameLogic::chooseCaveScreen() {
    while (true) {
        std::cout << "\n=== CHOSE A CAVE TO ENTER ===" << std::endl;
        std::cout << "The Caves are " << std::endl;
        int index = 0;
        for (const auto& cave : caves) {
            std::cout << index << " : "
                      << cave.getName()
                      << " Contains " << cave.getGold()
                      << " Gold." <<std::endl;

            index++;
        }

        std::cout << "Chose cave to enter by number (q to quit): ";
        std::string in;
        std::cin >> in;

        if (in == "q") return;

        chooseEnemyScreen(std::stoi(in));

    }

    return;
}

// Display Enemy selector
void GameLogic::chooseEnemyScreen(int cave) {
    while (true) {
        std::cout << "\n=== CHOSE AN ENEMY TO FIGHT" << std::endl;
        std::cout << "Your stats: " 
                << ", Hp = " << hero.getHp() 
                << ", Strength = " << hero.getStrength() 
                << ", Level = " << hero.getLevel() 
                << ", Xp = " << hero.getXp()
                << ", Gold = " << hero.getGold()
                << std::endl;
        
        std::cout << "\n The enemies in the cave are " << std::endl;
        int index = 0;
        for (const auto& enemy : caves[cave].getEnemies()) {
            std::cout << index << " : "
                      << enemy.getName()
                      << ", Hp: " << enemy.getHp()
                      << ", Strength: " << enemy.getStrength()
                      << ", Xp reward: " << enemy.getXpReward()
                      << std::endl;
            
            index++;
        }

        std::cout << "\nChose enemy to fight by number (e to exit cave): ";
        std::string in;
        std::cin >> in;

        if (in == "e") return;

        if (fightEnemy(caves[cave].getEnemies()[std::stoi(in)])) {
            caves[cave].clearEnemy(std::stoi(in));
        }

        if (caves[cave].isClear()) {
            std::cout << "You defeated the " << caves[cave].getName() << std::endl;
            std::cout << "As a reward " << caves[cave].getGold() << " Gold has been added to your Hero." << std::endl;
            hero.addGold(caves[cave].getGold());
            caves.erase(caves.begin()+cave);

            return;
        }

    }
    
    return;
}

void GameLogic::armoryScreen() {
    while (true) {
        std::cout << "\n=== AMORY ===" << std::endl;

        int index = 0;
        for (const auto& weapon : armory) {
            std::cout << index << " : "
                    << weapon.getName() 
                    << " Damage: " << weapon.getDamage() 
                    << " Damage multiplier: " << weapon.getDamageMultiplier() 
                    << " Price: " << weapon.getPrice() << " Gold." 
                    << std::endl;

            index++;
        }

        std::cout << "\nEnter weapon id to by (exit with 'e'): ";
        std::string input;
        std::cin >> input;
        
        if (input == "e") return;

        Weapon weapon = armory[stoi(input)];

        if (weapon.getPrice() > hero.getGold()) {
            std::cout << "\n Not enough gold to by " << weapon.getName() << std::endl;

        } else {
            hero.giveWeapon(weapon);
        }
    }

    return;
}

// Fight against an enemy takes the index of the enemy from the enemies vector
bool GameLogic::fightEnemy(Enemy enemy) {
    int heroHp = hero.getHp();
    int enemyHp = enemy.getHp();

    std::cout << "\n=== YOU ARE FIGHTING AGAINST ===" << std::endl;
    std::cout << enemy.getName()
              << ", Hp " << enemyHp
              << ", Strength " << enemy.getStrength()
              << ", XP Reward" << enemy.getXpReward()
              << std::endl;


    while (heroHp > 0 && enemyHp > 0) {
        enemyHp -= hero.getStrength();

        if (enemyHp > 0) heroHp -= enemy.getStrength();

        std::cout << hero.getName() << ", Hp " << heroHp << std::endl;
        std::cout << enemy.getName() << ", Hp " << enemyHp << std::endl;

    }

    std::cout << "\n=== FIGHT IS OVER ===" << std::endl;
    if (heroHp > 0) {
        std::cout << "You won against " << enemy.getName() << std::endl;
        std::cout << "And recieved " << enemy.getXpReward() << "XP as a reward." << std::endl;

        hero.addXp(enemy.getXpReward());

        return true;

    } else {
        std::cout << "You lost against " << enemy.getName() << std::endl;
        std::cout << "Come back stronger and try again." << std::endl;

        return false;
    }

    return false;
}