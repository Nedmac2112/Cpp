#include <iostream>
#include <vector>
using namespace std;

// enum for the user's class
enum Character
{
    WARRIOR = 1,
    MAGE = 2,
    ARCHER = 3
};

// enemy class, which is used to give each enemy health and damage
class Enemy
{
private:
    int enemyDmg;
    int enemyHp;
    int maxHealth;

public:
    // Constructor
    Enemy() : enemyDmg(0), enemyHp(0), maxHealth(0) {}

    void setEnemyDmg(int d)
    {
        enemyDmg = d;
    }
    int getEnemyDmg() const
    {
        return enemyDmg;
    }

    void setEnemyHp(int h)
    {
        enemyHp = h;
    }
    int getEnemyHp() const
    {
        return enemyHp;
    }

    void setEnemyMaxHp(int mH)
    {
        maxHealth = mH;
    }
    int getEnemyMaxHp() const
    {
        return maxHealth;
    }
};

// runs when the enemy attacks the player
void enemyAttack(int &playerHp, int &enemyDmg, string &enemy)
{
    playerHp -= enemyDmg;
    cout << "The " << enemy << " dealt " << enemyDmg << " damage to you \n";
}

// runs when the player attacks the enemy, also calls the enemyAttack function
void playerAttack(int &enemyHp, int &playerDmg, int &enemyDmg, int &playerHp, string &enemy)
{
    enemyHp -= playerDmg;
    cout << "You dealt " << playerDmg << " damage \n";

    if (enemyHp > 0)
    {
        enemyAttack(playerHp, enemyDmg, enemy);
    }
}

// checks to see if the user died or not
void checkDeathFunc(int &playerHp, string &enemy, int &turn, int &hpPotions)
{
    cout << endl;

    if (playerHp <= 0)
    {
        cout << "YOU DIED! \n";
        cout << "GAME OVER \n";
        cout << "-----------------------------------------------------------------------------------------------------------";
    }

    else
    {
        cout << "You killed the " << enemy << " in " << turn << " turn(s)! \n"
             << "You have " << playerHp << " Hp left. \n"
             << "You gained 1 health potion. \n";

        hpPotions++;
        turn = 0;
    }
}

// runs when either the user decides to attack, or is forced to attack
void attackFunc(string &enemy, int &playerHp, int &enemyHp, int &maxHp, int &enemyMaxHp, char &cmd, int &turn, int &playerDmg, int &hpPotions, int &healAmount, int &enemyDmg)
{

    cout << "You engage the " << enemy << "! \n";

    while (playerHp > 0 && enemyHp > 0)
    {
        cout << "You have (" << playerHp << "/" << maxHp << ") health left \n";
        cout << "The " << enemy << " has (" << enemyHp << "/" << enemyMaxHp << ") health left \n";
        cout << "You have " << hpPotions << " health potions left \n \n";
        cout << "What will you do? (a: attack, h: heal) ";
        cin >> cmd;

        // input validation
        while (cmd != 'a' && cmd != 'h')
        {
            cout << "Please enter a valid command: (a: attack, h: heal) ";
            cin >> cmd;
        }
        // runs if the user decides to attack
        if (cmd == 'a')
        {
            playerAttack(enemyHp, playerDmg, enemyDmg, playerHp, enemy);
            turn++;
        }
        // this allows the user to heal on their turn instead of attacking
        else if (hpPotions > 0)
        {
            // if the user's health is at the max health, this forces them to attack
            if (playerHp == maxHp)
            {
                cout << "You are already at full health. You must attack! \n";

                playerAttack(enemyHp, playerDmg, enemyDmg, playerHp, enemy);
            }
            // allows the user to heal if they are not at max health
            else
            {
                playerHp += healAmount;
                cout << "You drink a health potion \n";
                hpPotions--;
                // makes sure the user does not have more health than their max health
                if (playerHp >= maxHp)
                {
                    playerHp = maxHp;
                }

                // allows the enemy to attack after the player heals
                if (enemyHp > 0)
                {
                    enemyAttack(playerHp, enemyDmg, enemy);
                }
                // counts how many turns it takes to kill the enemy
                turn++;
            }
        }
        // forces the user to attack if they have no health potions
        else
        {
            cout << "You are out of health potions and must attack \n";
            playerAttack(enemyHp, playerDmg, enemyDmg, playerHp, enemy);
            turn++;
        }
    }
    // checks to see if the user died or not
    checkDeathFunc(playerHp, enemy, turn, hpPotions);
}

void runFunc(int &randNum, string &enemy, int &playerHp, int &enemyHp, int &maxHp, int &enemyMaxHp, char &cmd, int &turn, int &playerDmg, int &hpPotions, int &healAmount, int &enemyDmg)
{
    // generates a new random number eveytime the prograam is run
    srand(time(0));
    // generates a random number between 0 and 1
    randNum = rand() % 2;
    // the user has a 50% chance to escape successfully
    if (randNum == 0)
    {
        cout << "You escaped successfully! \n";
    }
    // forces the user to attack if they failed to run
    else
    {
        cout << "You failed to escape the " << enemy << ". You must attack! \n";
        attackFunc(enemy, playerHp, enemyHp, maxHp, enemyMaxHp, cmd, turn, playerDmg, hpPotions, healAmount, enemyDmg);
    }
}

// runs if the user's first choice was to heal, but they are unable to
void cantHeal(int &randNum, string &enemy, int &playerHp, int &enemyHp, int &maxHp, int &enemyMaxHp, char &cmd, int &turn, int &playerDmg, int &hpPotions, int &healAmount, int &enemyDmg)
{
    // input validation
    while (cmd != 'a' && cmd != 'r')
    {
        cout << "Enter a valid command: (a: attack, r: run) ";
        cin >> cmd;
    }
    // allows the user to run only if canRun is true (used in the bossFunc)
    if (cmd == 'r')
    {
        runFunc(randNum, enemy, playerHp, enemyHp, maxHp, enemyMaxHp, cmd, turn, playerDmg, hpPotions, healAmount, enemyDmg);
    }
    // runs the attackFunc
    else
    {
        attackFunc(enemy, playerHp, enemyHp, maxHp, enemyMaxHp, cmd, turn, playerDmg, hpPotions, healAmount, enemyDmg);
    }
}

// This function is always run when the user first encounters an enemy. It gives them 3 options, which branch off depending on their fist choice.
void choiceFunc(char &cmd, int &randNum, string &enemy, int &healAmount, int &playerHp, int &hpPotions, int &potionsDrank, int &maxHp, int &enemyHp, int &enemyDmg, int &playerDmg, int &turn, int &enemyMaxHp)
{
    // input validation
    while (cmd != 'a' && cmd != 'r' && cmd != 'h')
    {
        cout << "Please enter a valid command: (a: attack. r: run, h: heal) ";
        cin >> cmd;
    }

    // runs if the user chose to heal
    if (cmd == 'h')
    {
        // forces the user to choose another option if they are at max health
        if (playerHp == maxHp)
        {
            cout << "You are already at full health. Enter a valid command (a: attack, r: run) ";
            cin >> cmd;
            cantHeal(randNum, enemy, playerHp, enemyHp, maxHp, enemyMaxHp, cmd, turn, playerDmg, hpPotions, healAmount, enemyDmg);
        }
        // runs if the user is not at max health and has atleast 1 health potion
        else if (hpPotions > 0)
        {
            // the user can drink more than one potion if they want
            cout << "How many health potions do you want to drink? ";
            cin >> potionsDrank;
            // input validation
            while (hpPotions < potionsDrank || potionsDrank <= 0)
            {
                cout << "You have " << hpPotions << " health potion(s) left. You must drink atleast 1 potion. \n"
                     << "Please enter a valid number of health potions to drink: ";

                cin >> potionsDrank;
            }

            cout << endl;
            // for loop that adds the health to the user and removes the health potions from their inventory
            for (int i = 0; i < potionsDrank; i++)
            {
                if (playerHp >= maxHp)
                {
                    cout << "You are at full health and can't drink " << potionsDrank << " health potions \n";
                    break;
                }

                playerHp += healAmount;
                hpPotions--;
            }

            // makes sure the user does not have more health than their max health
            if (playerHp >= maxHp)
            {
                playerHp = maxHp;
            }

            cout << "Your health is now " << playerHp << ". \n";
            cout << "You have " << hpPotions << " health potion(s) left. \n \n";

            cout << "Now what will you do? (a: attack, r: run) ";
            cin >> cmd;

            cantHeal(randNum, enemy, playerHp, enemyHp, maxHp, enemyMaxHp, cmd, turn, playerDmg, hpPotions, healAmount, enemyDmg);
        }
        // runs if the user wants to heal, but can't because they have no health potions
        else
        {
            cout << "You can't heal because you have no potions. Enter a valid command: (a: attack, r: run) ";
            cin >> cmd;

            cantHeal(randNum, enemy, playerHp, enemyHp, maxHp, enemyMaxHp, cmd, turn, playerDmg, hpPotions, healAmount, enemyDmg);
        }
    }
    // runs if the user chose to run
    else if (cmd == 'r')
    {
        runFunc(randNum, enemy, playerHp, enemyHp, maxHp, enemyMaxHp, cmd, turn, playerDmg, hpPotions, healAmount, enemyDmg);
    }
    // runs if the user chose to attack
    else
    {
        attackFunc(enemy, playerHp, enemyHp, maxHp, enemyMaxHp, cmd, turn, playerDmg, hpPotions, healAmount, enemyDmg);
    }
}

// this function is run when the user fights a boss, and is unique, because it prohibits the user from running away
void bossFunc(int &randNum, char &cmd, string &enemy, int &healAmount, int &playerHp, int &hpPotions, int &potionsDrank, int &maxHp, int &enemyHp, int &enemyDmg, int &playerDmg, int &turn, int &enemyMaxHp)
{

    // input validation
    while (cmd != 'a' && cmd != 'h')
    {
        cout << "Please enter a valid command: (a: attack, h: heal) ";
        cin >> cmd;
    }
    // runs if the user chose to heal
    if (cmd == 'h')
    {
        // forces the user to choose another option if they are at max health
        if (playerHp == maxHp)
        {
            cout << "You are already at full health. You must attack! \n";

            attackFunc(enemy, playerHp, enemyHp, maxHp, enemyMaxHp, cmd, turn, playerDmg, hpPotions, healAmount, enemyDmg);
        }
        // the user can drink more than one potion if they want
        else if (hpPotions > 0)
        {
            cout << "How many health potions do you want to drink? ";
            cin >> potionsDrank;
            // input validation
            while (hpPotions < potionsDrank || potionsDrank <= 0)
            {
                cout << "You have " << hpPotions << " health potion(s) left. You must drink atleast 1 potion. \n"
                     << "Please enter a valid number of health potions to drink: ";

                cin >> potionsDrank;
            }

            cout << endl;
            // for loop that adds the health to the user and removes the health potions from their inventory
            for (int i = 0; i < potionsDrank; i++)
            {
                if (playerHp >= maxHp)
                {
                    cout << "You are at full health and can't drink " << potionsDrank << " health potions \n";
                    break;
                }

                playerHp += healAmount;
                hpPotions--;
            }

            // makes sure the user does not have more health than their max health
            if (playerHp >= maxHp)
            {
                playerHp = maxHp;
            }

            cout << "Your health is now " << playerHp << ". \n";
            cout << "You have " << hpPotions << " health potion(s) left. \n \n";

            cout << "Now you must attack! \n";
            // runs after the user heals
            attackFunc(enemy, playerHp, enemyHp, maxHp, enemyMaxHp, cmd, turn, playerDmg, hpPotions, healAmount, enemyDmg);
        }
        // forces the user to attack
        else
        {
            cout << "You can't heal because you have no potions. Now you must attack! \n";
            attackFunc(enemy, playerHp, enemyHp, maxHp, enemyMaxHp, cmd, turn, playerDmg, hpPotions, healAmount, enemyDmg);
        }
    }
    // runs if the user chose to attack
    else
    {
        attackFunc(enemy, playerHp, enemyHp, maxHp, enemyMaxHp, cmd, turn, playerDmg, hpPotions, healAmount, enemyDmg);
    }
}
// displays character info
void charStats(int pDmg, int pHp, int maxHp, int hpPotions)
{
    cout << "------------------------------------------- \n";
    cout << "Player damage: " << pDmg << "\n"
         << "Player health: (" << pHp << "/" << maxHp << ") \n"
         << "Health potions: " << hpPotions << "\n";
    cout << "------------------------------------------- \n";
}
// displays enemy info
void enemyStats(string enemy, int eDmg, int eHp)
{
    cout << "-------------------- \n";
    cout << "Enemy: " << enemy << "\n"
         << "Enemy damage: " << eDmg << "\n"
         << "Enemy health: " << eHp << "\n";
    cout << "-------------------- \n";
}

void enemySetup(vector<Enemy> &v, int &enemyHp, int &enemyMaxHp, int &enemyDmg, int &c)
{
    Enemy e = v[c];
    enemyHp = e.getEnemyHp();
    enemyMaxHp = e.getEnemyMaxHp();
    enemyDmg = e.getEnemyDmg();
    // See what I did there ;)
    c++;
}