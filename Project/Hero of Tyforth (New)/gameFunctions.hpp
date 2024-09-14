#ifndef GAME_FUNCTIONS_HPP
#define GAME_FUNCTIONS_HPP

#include <string>    // included in player.h and enemy.h, but included here for clarity
#include <vector>    // this must be included here, because it is not in player.h or enemy.h
using namespace std; // included in player.h and enemy.h, but included here for clarity

#include "player.hpp" // access to Player class
#include "enemy.hpp"  // access to Enemy class

void pauseGame(int seconds);
void nextEnemy(vector<Enemy> &enemies, Enemy &currentEnemy, int &enemyIndex);
void enemyEncounter(Player &player, Enemy &enemy, string &playerName);
void clearInput();
void inputPlayerName(string &name, bool &isValidInput);
void inputPlayerGender(char &gender, bool &isValidInput);
void inputPlayerAge(int &age, bool &isValidInput);
void inputPlayerRace(string &playerRace, bool &isValidInput);
void inputPlayerClass(int &playerClass, string &className, bool &isValidInput);
void playerDetails(string &playerName, int &playerAge, char &playerGender, string &playerRace, string &className);
string getPlayerName(string &playerName);
void playerStats(Player &player);
bool checkPlayerDeath(Player &player);
bool checkEnemyDeath(Enemy &enemy);
bool checkPlayerNotMaxHealth(Player &player);
void playerTurn(Player &player, Enemy &enemy, bool &isAttacking, bool &isHealing, int &turnCounter, string &playerName);
void enemyTurn(Player &player, Enemy &enemy, string &playerName);
void userInput(Player &player, Enemy &enemy, int &turnCounter, string &playerName);
void enemyEncounter(Player &player, Enemy &enemy, string &playerName);

#endif