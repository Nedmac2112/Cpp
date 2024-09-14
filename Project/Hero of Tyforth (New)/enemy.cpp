#include <iostream> // this must be included here, because it is not in player.h or enemy.h
// both included in player.h and enemy.h, but included here for clarity
#include <string>
using namespace std;

#include "enemy.hpp"  // access to Enemy class definition
#include "player.hpp" // already in enemy.h, but included here for clarity

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
