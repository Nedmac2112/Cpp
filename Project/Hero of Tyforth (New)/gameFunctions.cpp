// all of these must be included here, because they are not in gameFunctions.h
#include <iostream>
#include <limits>
#include <cctype>
#include <chrono>
#include <thread>
// all included in gameFunctions.h, but included here for clarity
#include <string>
#include <vector>
using namespace std;

#include "gameFunctions.hpp" // access to game function definitions

void pauseGame(int seconds)
{
    this_thread::sleep_for(chrono::seconds(seconds));
}

void nextEnemy(vector<Enemy> &enemies, Enemy &currentEnemy, int &enemyIndex)
{
    enemyIndex++;
    currentEnemy = enemies[enemyIndex];
}

void clearInput()
{
    cin.clear();                                         // Clear the error state
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore remaining characters in the buffer
}

void inputPlayerName(string &name, bool &isValidInput)
{
    cout << "What is your name, brave adventurer? ";
    while (!isValidInput)
    {
        getline(cin, name);
        if (!name.empty() && name.find_first_not_of(' ') != string::npos)
        {
            isValidInput = true;
        }
        else
        {
            cerr << "Invalid input. Please enter a name that doesn't start with a space: ";
        }
    }
}

void inputPlayerGender(char &gender, bool &isValidInput)
{
    isValidInput = false;
    cout << "What is your gender (M/F)? ";
    while (!isValidInput)
    {
        cin >> gender;
        gender = toupper(gender);

        if (gender == 'M' || gender == 'F')
        {
            isValidInput = true;
        }
        else
        {
            cout << "Invalid input. Please enter 'M' for Male or 'F' for Female: ";
        }
        clearInput();
    }
}

void inputPlayerAge(int &age, bool &isValidInput)
{
    isValidInput = false;
    cout << "How old are you? ";
    while (!isValidInput)
    {
        cin >> age;
        if (cin.fail())
        {
            cerr << "Invalid input. Please enter a number: ";
            clearInput();
            continue;
        }
        else if (age <= 0)
        {
            cerr << "Invalid input. Please enter an age greater than zero: ";
            clearInput();
            continue;
        }

        isValidInput = true;
        clearInput();
    }
}

void inputPlayerRace(string &playerRace, bool &isValidInput)
{
    isValidInput = false;
    int raceInput;
    cout << "What is your race? (1: Human, 2: Elf, 3: Dwarf, 4: Orc, 5: Halfling) ";
    while (!isValidInput)
    {
        cin >> raceInput;

        if (cin.fail())
        {
            cerr << "Invalid input. Please enter a number: ";
            clearInput();
            continue;
        }

        switch (raceInput)
        {
        case PlayerRace::Human:
            playerRace = "Human";
            isValidInput = true;
            break;
        case PlayerRace::Elf:
            playerRace = "Elf";
            isValidInput = true;
            break;
        case PlayerRace::Dwarf:
            playerRace = "Dwarf";
            isValidInput = true;
            break;
        case PlayerRace::Orc:
            playerRace = "Orc";
            isValidInput = true;
            break;
        case PlayerRace::Halfling:
            playerRace = "Halfling";
            isValidInput = true;
            break;
        default:
            cerr << "Invalid input. You can only enter a number (1 - 5): ";
            break;
        }
        clearInput();
    }
}

void inputPlayerClass(int &playerClass, string &className, bool &isValidInput)
{
    isValidInput = false;
    cout << "What is your class? (1: Warrior, 2: Archer, 3: Mage) ";
    while (!isValidInput)
    {
        cin >> playerClass;

        if (cin.fail())
        {
            cerr << "Invalid input. Please enter a number: ";
            clearInput();
            continue;
        }

        switch (playerClass)
        {
        case PlayerClass::Warrior:
            playerClass = PlayerClass::Warrior;
            className = "Warrior";
            isValidInput = true;
            break;
        case PlayerClass::Archer:
            playerClass = PlayerClass::Archer;
            className = "Archer";
            isValidInput = true;
            break;
        case PlayerClass::Mage:
            playerClass = PlayerClass::Mage;
            className = "Mage";
            isValidInput = true;
            break;
        default:
            cerr << "Invalid input. You can only enter a number (1 - 3): ";
            break;
        }
        clearInput();
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
        // Removes any characters left in the input buffer.
        // I used this so that the user is only aked once to enter correct input, if they enter something like "xgy".
        // It also prevents the user from entering multiple inputs at once.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    playerTurn(player, enemy, isAttacking, isHealing, turnCounter, playerName);
}

void enemyEncounter(Player &player, Enemy &enemy, string &playerName)
{
    int turnCounter = 0;
    // cout << "You encounter a " << enemy.getName() << endl;
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