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

    std::cout << "\n=== HERORS TO LOAD ===" << std::endl;

    while (std::getline (file, line)) {
        std::stringstream ss(line);
        std::string name;
        int hp, strength, level, xp;
        std::string value;

        std::getline(ss, name, ',');
        std::getline(ss, value, ','); hp = std::stoi(value);
        std::getline(ss, value, ','); strength = std::stoi(value);
        std::getline(ss, value, ','); level = std::stoi(value);
        std::getline(ss, value, ','); xp = std::stoi(value);

        std::cout << heros.size() << ": " << name 
                  << ", Hp = " << hp 
                  << ", Strength = " << strength 
                  << ", Level = " << level 
                  << ", Xp = " << xp 
                  << std::endl;

        heros.push_back(Hero(name, hp, strength, level, xp));

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
            newLine << hero.getName() << "," << hero.getHp() << "," << hero.getStrength() << "," << hero.getLevel() << "," << hero.getXp();
            lines.push_back(newLine.str());
            update = true;
        } else {
            lines.push_back(line);
        }
    }

    file.close();

    if (!update) {
        std::stringstream newLine;
        newLine << hero.getName() << "," << hero.getHp() << "," << hero.getStrength() << "," << hero.getLevel() << "," << hero.getXp();
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
void GameLogic::setEnemies(std::vector<Enemy> _enemies) {
    if (!_enemies.empty()) {
        enemies = _enemies;
        return;

    } else {
        enemies.push_back(Enemy("Horse", 4, 1, 100));
        enemies.push_back(Enemy("Weak Goblin", 4, 2, 200));
        enemies.push_back(Enemy("Strong Goblin", 8, 3, 400));
        enemies.push_back(Enemy("Stronger Goblin", 10, 4, 500));
        enemies.push_back(Enemy("The strongest Goblin", 15, 5, 800));
        enemies.push_back(Enemy("Mokey King", 30, 5, 1000));
        enemies.push_back(Enemy("Unicorn", 5, 8, 1500));

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

// Display Enemy selector
void GameLogic::chooseEnemyScreen() {
    while (true) {
        std::cout << "\n=== CHOSE AN ENEMY TO FIGHT" << std::endl;
        std::cout << "Your stats: " 
                << ", Hp = " << hero.getHp() 
                << ", Strength = " << hero.getStrength() 
                << ", Level = " << hero.getLevel() 
                << ", Xp = " << hero.getXp() 
                << std::endl;
        
        std::cout << "\n The enemies are " << std::endl;
        int index = 0;
        for (const auto& enemy : enemies) {
            std::cout << index << " : "
                      << enemy.getName()
                      << ", Hp: " << enemy.getHp()
                      << ", Strength: " << enemy.getStrength()
                      << ", Xp reward: " << enemy.getXpReward()
                      << std::endl;
            
            index++;
        }

        std::cout << "\nChose enemy to fight by number (q to quit): ";
        std::string in;
        std::cin >> in;

        if (in == "q") return;
        fightEnemy(std::stoi(in));
    }
    
}

void GameLogic::fightEnemy(int index) {
    return;
}