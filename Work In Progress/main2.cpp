#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

// Forward declaration of Enemy class
class Enemy;

enum PlayerRace
{
    Human = 1,
    Elf,
    Dwarf,
    Orc,
    Halfling
};

// Enumeration for Player types
enum PlayerClass
{
    Warrior = 1,
    Archer,
    Mage
};

// Declaration of Player class
class Player
{
private:
    int health;
    int maxHealth;
    int attack;
    int healingPotions;

public:
    Player();
    Player(int &hp, int &maxHp, int &atk, int Potions);
    Player(int &playerClass);

    void heal();
    void attackEnemy(Enemy &enemy);
    void takeDamage(int damage);
    int getHealth() const;
    int getMaxHealth() const;
    int getAttack() const;
    int getPotions() const;
    void viewPlayerHealth(string &playerName) const;
};

// Declaration of Enemy class inheriting from Player
class Enemy : public Player
{
private:
    string name;

public:
    Enemy();
    Enemy(string name, int hp, int maxHp, int atk, int noPotions);
    void attackPlayer(Player &player) const;
    string getEnemyName() const;
    void viewEnemyHealth() const;
};

// Function declarations
bool checkPlayerDeath(Player &player);
bool checkEnemyDeath(Enemy &enemy);
bool checkPlayerNotMaxHealth(Player &player);
void playerTurn(Player &player, Enemy &enemy, bool &isAttacking, bool &isHealing, int &turnCounter, string &playerName);
void enemyTurn(Player &player, Enemy &enemy, string &playerName);
void userInput(Player &player, Enemy &enemy, int &turnCounter, string &playerName);
void enemyEncounter(Player &player, Enemy &enemy, string &playerName);
void pauseGame(int seconds);
void nextEnemy(vector<Enemy> &enemies, Enemy &currentEnemy, int &enemyIndex);

bool inputPlayerName(string &name);
bool inputPlayerGender(char &gender);
bool inputPlayerAge(int &age);
bool inputPlayerRace(string &playerRace);
bool inputPlayerClass(int &playerClass, string &className);

string getPlayerName(string &playerName);
void playerDetails(string &playerName, int &playerAge, char &playerGender, string &playerRace, string &className);
void playerStats(Player &player);
/*












*/
// Player class implementations
Player::Player() : health(100), maxHealth(100), attack(10), healingPotions(1) {}

Player::Player(int &hp, int &maxHp, int &atk, int potions)
    : health(hp), maxHealth(maxHp), attack(atk), healingPotions(potions) {}

Player::Player(int &playerClass)
{
    switch (playerClass)
    {
    case PlayerClass::Warrior:
        health = 125;
        maxHealth = 125;
        attack = 20;
        healingPotions = 1;
        break;
    case PlayerClass::Archer:
        health = 110;
        maxHealth = 110;
        attack = 25;
        healingPotions = 1;
        break;
    case PlayerClass::Mage:
        health = 100;
        maxHealth = 100;
        attack = 30;
        healingPotions = 1;
        break;
    default:
        cout << "Invalid player type!" << endl;
        break;
    }
}

// Player methods
void Player::heal()
{
    const int POTION_HEAL = 20;
    if (healingPotions > 0)
    {
        health += POTION_HEAL;
        if (health > maxHealth)
        {
            health = maxHealth;
        }
        healingPotions--;
    }
}

void Player::attackEnemy(Enemy &enemy)
{
    enemy.takeDamage(attack);
}

void Player::takeDamage(int damage)
{
    health -= damage;
    if (health < 0)
    {
        health = 0;
    }
}

int Player::getHealth() const
{
    return health;
}

int Player::getMaxHealth() const
{
    return maxHealth;
}

int Player::getAttack() const
{
    return attack;
}

int Player::getPotions() const
{
    return healingPotions;
}

void Player::viewPlayerHealth(string &playerName) const
{
    cout << getPlayerName(playerName) << "'s health: (" << health << "/" << maxHealth << ")" << endl;
}

// Enemy class implementations
Enemy::Enemy() : Player(), name("None") {}

Enemy::Enemy(string name, int hp, int maxHp, int atk, int noPotions) : Player(hp, maxHp, atk, 0), name(name) {}

// Enemy methods
void Enemy::attackPlayer(Player &player) const
{
    player.takeDamage(getAttack());
}

string Enemy::getEnemyName() const
{
    return name;
}

void Enemy::viewEnemyHealth() const
{
    cout << getEnemyName() << "'s health: (" << getHealth() << "/" << getMaxHealth() << ")" << endl;
}

// Other functions
bool checkPlayerDeath(Player &player)
{
    return player.getHealth() <= 0;
}

bool checkEnemyDeath(Enemy &enemy)
{
    return enemy.getHealth() <= 0;
}

bool checkPlayerNotMaxHealth(Player &player)
{
    return ((player.getHealth() < player.getMaxHealth()) && player.getHealth() > 0);
}

void playerTurn(Player &player, Enemy &enemy, bool &isAttacking, bool &isHealing, int &turnCounter, string &playerName)
{
    turnCounter++;
    cout << endl;
    if (isAttacking)
    {
        player.attackEnemy(enemy);
        cout << getPlayerName(playerName) << " attacks the " << enemy.getEnemyName() << endl;
        enemy.viewEnemyHealth();
    }

    else if (isHealing)
    {
        player.heal();
        cout << getPlayerName(playerName) << " heals" << endl;
        player.viewPlayerHealth(playerName);
    }
}

void enemyTurn(Player &player, Enemy &enemy, string &playerName)
{
    enemy.attackPlayer(player);
    cout << enemy.getEnemyName() << " attacks " << getPlayerName(playerName) << endl;
    player.viewPlayerHealth(playerName);
}

void userInput(Player &player, Enemy &enemy, int &turnCounter, string &playerName)
{
    char input;
    bool validInput = false;
    bool isAttacking = false;
    bool isHealing = false;

    cout << "Press 'a' to attack or 'h' to heal (" << player.getPotions() << " healing potion(s) left) : ";
    while (!validInput)
    {
        cin >> input;
        if (input == 'a' || input == 'A')
        {
            isAttacking = true;
            validInput = true;
        }

        else if ((input == 'h' || input == 'H') && (checkPlayerNotMaxHealth(player) && player.getPotions() > 0))
        {

            isHealing = true;
            validInput = true;
        }

        else
        {
            if ((input == 'h' || input == 'H') && !checkPlayerNotMaxHealth(player))
            {
                cout << "You are at full health!" << " Press 'a' to attack: ";
            }

            else if ((input == 'h' || input == 'H') && player.getPotions() == 0)
            {
                cout << "You have no healing potions left! Press 'a' to attack: ";
            }

            else
            {
                cout << "Invalid input! Press 'a' to attack or 'h' to heal: ";
            }
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    playerTurn(player, enemy, isAttacking, isHealing, turnCounter, playerName);
}

void pauseGame(int seconds)
{
    this_thread::sleep_for(chrono::seconds(seconds));
}

void nextEnemy(vector<Enemy> &enemies, Enemy &currentEnemy, int &enemyIndex)
{
    enemyIndex++;
    currentEnemy = enemies[enemyIndex];
}

void enemyEncounter(Player &player, Enemy &enemy, string &playerName)
{
    int turnCounter = 0;
    while (player.getHealth() > 0 && enemy.getHealth() > 0)
    {
        userInput(player, enemy, turnCounter, playerName);
        if (checkEnemyDeath(enemy))
        {
            cout << getPlayerName(playerName) << " has defeated the " << enemy.getEnemyName() << " in " << turnCounter << " turns!" << endl;
            break;
        }

        cout << endl;
        pauseGame(4);

        cout << "It's the " << enemy.getEnemyName() << "'s turn" << endl;
        enemyTurn(player, enemy, playerName);
        if (checkPlayerDeath(player))
        {
            cout << "Game Over!" << endl;
            exit(0);
        }

        cout << endl;
        cout << "It's your turn..." << endl;
    }
}

bool inputPlayerName(string &name)
{
    cout << "What is your name, brave adventurer? ";
    while (true)
    {
        getline(cin, name);
        if (!name.empty() && name.find_first_not_of(' ') != string::npos)
        {
            return true;
        }
        else
        {
            cerr << "Please enter a valid name: ";
        }
    }
}

bool inputPlayerGender(char &gender)
{
    cout << "What is your gender (M/F)? ";
    while (true)
    {
        cin >> gender;
        gender = toupper(gender);

        if (gender == 'M' || gender == 'F')
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return true;
        }
        else
        {
            cout << "Invalid input. Please enter 'M' for Male or 'F' for Female: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

bool inputPlayerAge(int &age)
{
    cout << "How old are you? ";
    while (true)
    {
        cin >> age;
        if (cin.fail())
        {
            cerr << "Error: input is not a valid type" << '\n';
            cout << "Please enter a valid age: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (age <= 0)
        {
            cerr << "Age must be greater than 0" << '\n';
            cout << "Please enter a valid age: ";
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return true;
        }
    }
}

bool inputPlayerRace(string &playerRace)
{
    int raceInput;
    cout << "What is your race? (1: Human, 2: Elf, 3: Dwarf, 4: Orc, 5: Halfling) ";
    while (true)
    {
        cin >> raceInput;
        switch (raceInput)
        {
        case 1:
            playerRace = "Human";
            return true;
        case 2:
            playerRace = "Elf";
            return true;
        case 3:
            playerRace = "Dwarf";
            return true;
        case 4:
            playerRace = "Orc";
            return true;
        case 5:
            playerRace = "Halfling";
            return true;
        default:
            cerr << "Invalid input" << '\n';
            cout << "Enter a number between 1 and 5 (1: Human, 2: Elf, 3: Dwarf, 4: Orc, 5: Halfling): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

bool inputPlayerClass(int &playerClass, string &className)
{
    cout << "What is your class? (1: Warrior, 2: Archer, 3: Mage) ";
    while (true)
    {
        cin >> playerClass;
        switch (playerClass)
        {
        case PlayerClass::Warrior:
            playerClass = PlayerClass::Warrior;
            className = "Warrior";
            return true;
        case PlayerClass::Archer:
            playerClass = PlayerClass::Archer;
            className = "Archer";
            return true;
        case PlayerClass::Mage:
            playerClass = PlayerClass::Mage;
            className = "Mage";
            return true;
        default:
            cerr << "Invalid input" << '\n';
            cout << "Enter a number between 1 and 3 (1: Warrior, 2: Archer, 3: Mage): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void playerDetails(string &playerName, int &playerAge, char &playerGender, string &playerRace, string &className)
{
    cout << "Player name: " << playerName << endl;
    cout << "Player age: " << playerAge << endl;
    cout << "Player gender: " << playerGender << endl;
    cout << "Player race: " << playerRace << endl;
    cout << "Player class: " << className << endl;
}

string getPlayerName(string &playerName)
{
    return playerName;
}

void playerStats(Player &player)
{
    cout << "Health: " << player.getHealth() << "/" << player.getMaxHealth() << endl;
    cout << "Attack: " << player.getAttack() << endl;
    cout << "Potions: " << player.getPotions() << endl;
}
/*












*/
// Compile the program: g++ main.cpp -o main

int main()
{

    string playerName;
    int playerAge;
    char playerGender;
    const int races[5] = {Human, Elf, Dwarf, Orc, Halfling};
    string playerRace;
    const int classes[3] = {Warrior, Archer, Mage};
    int playerClass;
    string className;

    // Create two enemy objects
    Enemy goblin("Goblin Grunt", 50, 50, 10, 0); // stats are health, max health, attack, and potions in that order
    Enemy spider("Giant Spider", 70, 70, 15, 0); // the only reason potions are included is because the Enemy class's constructor inherits from the Player class's constructor

    // Create a vector of enemies, and add the two enemy objects to it
    vector<Enemy> enemies;
    enemies.push_back(goblin);
    enemies.push_back(spider);
    // Create a pointer to the current enemy, and set it to the first enemy in the vector
    Enemy currentEnemy;
    int enemyIndex = 0;
    currentEnemy = enemies[enemyIndex];
    /*



    */
    // Main game loop
    cout << endl
         << "                      ******************************                      " << endl;
    cout << "                      * Welcome to Hero of Tyforth *                      " << endl;
    cout << "                      ******************************                      " << endl
         << endl;

    // Get player details
    inputPlayerName(playerName);
    inputPlayerGender(playerGender);
    inputPlayerAge(playerAge);
    inputPlayerRace(playerRace);
    inputPlayerClass(playerClass, className);

    // Create a player object
    Player p1(playerClass);

    cout << endl;
    // Display player details
    playerDetails(playerName, playerAge, playerGender, playerRace, className);
    cout << endl;
    // Display player stats
    playerStats(p1);
    cout << endl;

    cout << "You encounter a " << currentEnemy.getEnemyName() << "!" << endl;
    // Player attacks the first enemy, until one of them dies
    enemyEncounter(p1, currentEnemy, playerName);

    // This function will switch to the next enemy in the vector
    nextEnemy(enemies, currentEnemy, enemyIndex);

    return 0;
}
