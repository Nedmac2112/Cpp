#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
using namespace std;

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

// Forward declaration of Enemy class
class Enemy;

// Declaration of Player class (base class)
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

#endif