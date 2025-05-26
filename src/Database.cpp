#include "Database.hpp"

Database::Database() : db(nullptr) {}

// Destructor closes DB
Database::~Database() {
    if (db) {
        if (sqlite3_get_autocommit(db) == 0) {
            char* errmsg;

            if (sqlite3_exec(db, "COMMIT;", nullptr, nullptr, &errmsg) != SQLITE_OK) {
            std::cerr << "Failed to commit transaction: " << errmsg << std::endl;
            sqlite3_free(errmsg);
            }
        }

        sqlite3_close(db);
    }

}

// Open database and create tables if missing
Database::Database(std::string dbFileName) {
    int rc = sqlite3_open(dbFileName.c_str(), &db);

    if (rc) {
        std::cerr << "Can't open database" << sqlite3_errmsg(db) << "\n";
    }

    if (!createTables()) {
        std::cerr << "Failed to create tables" << std::endl;
    }

}

// Create tables for the database
bool Database::createTables() {
    const char* heroTable = R"(
        CREATE TABLE IF NOT EXISTS heros (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL UNIQUE,
            hp INTEGER,
            strength INTEGER,
            level INTEGER,
            xp INTEGER,
            gold INTEGER,
            weaponId INTEGER,
            weaponDurability INTEGER,
            FOREIGN KEY(weaponId) REFERENCES weapons(id)
        )
    )";

    const char* weaponTable = R"(
        CREATE TABLE IF NOT EXISTS weapons (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL UNIQUE,
            damage INTEGER NOT NULL,
            multiplier INTEGER NOT NULL,
            durability INTEGER NOT NULL,
            price INTEGER NOT NULL
        )
    )";

    const char* killsTable = R"(
        CREATE TABLE IF NOT EXISTS kills (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            heroId INTEGER NOT NULL,
            weaponId INTEGER NOT NULL,
            FOREIGN KEY(heroId) REFERENCES heros(id),
            FOREIGN KEY(weaponId) REFERENCES weapons(id)
        )
    )";

    char* errmsg = nullptr;

    if (sqlite3_exec(db, heroTable, nullptr, nullptr, &errmsg) != SQLITE_OK) {
        std::cerr << "Failed to create heros table: " << errmsg << std::endl;
        sqlite3_free(errmsg);
        return false;
    }

    if (sqlite3_exec(db, weaponTable, nullptr, nullptr, &errmsg) != SQLITE_OK) {
        std::cerr << "Failed to create weapons table: " << errmsg << std::endl;
        sqlite3_free(errmsg);
        return false;
    }

    if (sqlite3_exec(db, killsTable, nullptr, nullptr, &errmsg) != SQLITE_OK) {
        std::cerr << "Failed to create kills table: " << errmsg << std::endl;
        sqlite3_free(errmsg);
        return false;
    }

    return true;
}

std::vector<Hero> Database::loadHero() {
    std::vector<Hero> heros;

    const char* query = "SELECT name FROM heros;";

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Failed to prepare statement 22 : " << sqlite3_errmsg(db) << std::endl;
        return heros;
    }


    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        int hp = sqlite3_column_int(stmt, 1);
        int strength = sqlite3_column_int(stmt, 2);
        int level = sqlite3_column_int(stmt, 3);
        int xp = sqlite3_column_int(stmt, 4);
        int gold = sqlite3_column_int(stmt, 5);

        std::optional<Weapon> weapon =std::nullopt;
        if (sqlite3_column_type(stmt, 6) != SQLITE_NULL) {
            std::string weaponName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));
            int damage = sqlite3_column_int(stmt, 7);
            int mulitplier = sqlite3_column_int(stmt, 8);
            int durability = sqlite3_column_int(stmt, 9);
            int price = sqlite3_column_int(stmt, 10);

            weapon = Weapon(weaponName, damage, mulitplier, durability, price);
        }

        Hero hero(name, hp, strength, level, xp, gold, weapon);
        heros.push_back(hero);
    }

    sqlite3_finalize(stmt);
    return heros;
}

void Database::saveHero(Hero hero) {
    int weaponId = 0;
    int weaponDurability = 0;

    if (hero.getWeapon().getName() != "") {
        const char* weaponIdQuery = "SELECT id FROM weapons WHERE name = ?;";

        sqlite3_stmt* stmt;
        if(sqlite3_prepare_v2(db, weaponIdQuery, -1, &stmt, nullptr) == SQLITE_OK) {
            sqlite3_bind_text(stmt, 1, hero.getWeapon().getName().c_str(), -1, SQLITE_STATIC);

            if (sqlite3_step(stmt) == SQLITE_ROW) {
                weaponId = sqlite3_column_int(stmt, 0);
            }

            sqlite3_finalize(stmt);
        }

        weaponDurability = hero.getWeapon().getDurability();
    }

    const char* updateOrInsertHero = R"(
        INSERT OR REPLACE INTO heros 
        (id, name, hp, strength, level, xp, gold, weaponId, weaponDurability) 
        VALUES ( 
            (SELECT id FROM heros WHERE name = ?), 
            ?, ?, ?, ?, ?, ?, ?, ? 
        );
    )";

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, updateOrInsertHero, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Failed to save hero: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    sqlite3_bind_text(stmt, 1, hero.getName().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, hero.getName().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, hero.getHp());
    sqlite3_bind_int(stmt, 4, hero.getStrength());
    sqlite3_bind_int(stmt, 5, hero.getLevel());
    sqlite3_bind_int(stmt, 6, hero.getXp());
    sqlite3_bind_int(stmt, 7, hero.getGold());
    if (weaponId > 0) {
        sqlite3_bind_int(stmt, 8, weaponId);
    } else {
        sqlite3_bind_null(stmt, 8);
    }
    sqlite3_bind_int(stmt, 9, weaponDurability);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Failed to execute statement: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(stmt);

    return;
}

std::vector<Weapon> Database::loadWeapons() {
    std::vector<Weapon> weapons = {};

    const char* query = R"(
        SELCET name, damage, multiplier, durability, price FROM weapons ORDER BY price ASC;
    )";

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Faield to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        return weapons;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        int damage = sqlite3_column_int(stmt, 1);
        int multiplier = sqlite3_column_int(stmt, 2);
        int durability = sqlite3_column_int(stmt, 3);
        int price = sqlite3_column_int(stmt, 4);

        weapons.emplace_back(name, damage, multiplier, durability, price);
    }

    sqlite3_finalize(stmt);
    return weapons;
}