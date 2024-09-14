#ifndef ENEMY_HPP
#define ENEMY_HPP

// both included in player.h, but included here for clarity
#include <string>
using namespace std;

#include "player.hpp" // this has to be included to use the Player class
                    // you can't do "class Player;" here because you need to know what the Enemy class is inheriting (methods and attributes)

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

#endif