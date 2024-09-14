#include <iostream> // this must be included here, because it is not in player.h or enemy.h
// both included in player.h and enemy.h, but included here for clarity
#include <string>
using namespace std;

// both player.h and enemy.h are already included in gameFunctions.h, but included here for clarity
#include "player.hpp"        // access to Player class definition
#include "enemy.hpp"         // needed for attackEnemy()
#include "gameFunctions.hpp" // needed for getPlayerName()

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
