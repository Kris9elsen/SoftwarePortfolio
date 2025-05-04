#include "GameLogic.hpp"

GameLogic::GameLogic() {}
GameLogic::~GameLogic() {
    saveHero();
}

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
                  << " Hp = " << hp 
                  << " Strength = " << strength 
                  << " Level = " << level 
                  << " Xp = " << xp 
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
                  << " Hp = " << hero.getHp() 
                  << " Strength = " << hero.getStrength() 
                  << " Level = " << hero.getLevel() 
                  << " Xp = " << hero.getXp() 
                  << std::endl;

        return;
    }

    std::cout << "Enter number of hero to load: ";
    std::cin >> line;
    hero = heros[std::stoi(line)];

    std::cout << "You chose to play as: " << hero.getName() << std::endl;

    return;
}

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