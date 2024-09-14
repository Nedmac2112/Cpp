// makefile command: mingw32-make -f make.mk

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cctype>
#include <chrono>
#include <thread>
using namespace std;

#include "gameFunctions.hpp"
// these are included in gameFunctions.h, but included here for clarity
#include "player.hpp"
#include "enemy.hpp"

int main()
{

     string playerName;
     int playerAge;
     char playerGender;
     string playerRace;
     int playerClass;
     string className;
     bool isValidInput = false;

     // Create two enemy objects
     Enemy goblin("Goblin Grunt", 50, 50, 10, 0); // stats are health, max health, and attack, in that order
     Enemy spider("Giant Spider", 70, 70, 15, 0);

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
     cout << "                      * Welcome to Hero of Tyforth!!! *                      " << endl;
     cout << "                      ******************************                      " << endl
          << endl;

     // Get player details
     inputPlayerName(playerName, isValidInput);
     inputPlayerGender(playerGender, isValidInput);
     inputPlayerAge(playerAge, isValidInput);
     inputPlayerRace(playerRace, isValidInput);
     inputPlayerClass(playerClass, className, isValidInput);

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
