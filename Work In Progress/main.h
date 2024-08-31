#ifndef MAIN_H
#define MAIN_H

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

void clearInput();
void inputPlayerName(string &name, bool &isValidInput);
void inputPlayerGender(char &gender, bool &isValidInput);
void inputPlayerAge(int &age, bool &isValidInput);
void inputPlayerRace(string &playerRace, bool &isValidInput);
void inputPlayerClass(int &playerClass, string &className, bool &isValidInput);

string getPlayerName(string &playerName);
void playerDetails(string &playerName, int &playerAge, char &playerGender, string &playerRace, string &className);
void playerStats(Player &player);

#endif // MAIN_H
