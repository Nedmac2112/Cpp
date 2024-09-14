// Camden K., 12/31/23, cckirkpatrick@dmacc.edu
// Program Name: Hero of Tyforth
// Purpose: a framework from which I can further build upon and expand from, in order to buid a story based text RPG.

#include "game.cpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <limits>
#include <cctype>
#include <typeinfo>
#include <thread>
#include <chrono>
using namespace std;

int main()
{
     // enum declarations and initializations
     Character const warrior = WARRIOR;
     Character const mage = MAGE;
     Character const archer = ARCHER;

     // variable declarations and initializations
     vector<Enemy> v;

     char cmd;
     bool isValidInput = false;

     int age, charNum, randNum, playerDmg, playerAttack, playerHp, maxHp, enemyHp, enemyMaxHp, enemyDmg, potionsDrank;
     int dmgIncrease = 5;
     int hpIncrease = 10;
     int hpPotions = 0;
     int healAmount = 30;
     int c = 0;
     int turn = 0;

     string name, race, charClass, charWeapon, sex;
     string locations[4] = {"Fort Tyforth", "Northhollow", "Trail of Tears", "Dragon's Lair"};
     string weapons[6] = {"Longsword", "Magic staff", "Oak bow", "Platinum longsword", "Saphire magic staff", "Maple bow"};
     string enemyArr[4] = {"goblin", "knight", "spider", "dragon"};
     string enemy = enemyArr[c];

     cout << "Welcome to Hero of Tyforth!" << endl;
     cout << endl;

     // character creation
     cout << "Enter the name of your character: ";

     while (!isValidInput)
     {
          getline(cin, name);
          if (name.empty())
          {
               cout << "You must enter a name! ";
          }
          else
          {
               isValidInput = true;
          }
     }

     isValidInput = false;

     cout << "Enter the race of " << name << ": ";

     while (!isValidInput)
     {
          getline(cin, race);
          if (race.empty())
          {
               cout << "You must enter a race! ";
          }
          else
          {
               isValidInput = true;
          }
     }

     isValidInput = false;

     while (!isValidInput)
     {
          cout << "Enter the sex of " << name << " (M/F): ";
          getline(cin, sex);

          if (sex.length() == 1)
          {
               char inputChar = toupper(sex[0]);
               if (inputChar == 'M' || inputChar == 'F')
               {
                    isValidInput = true;
                    sex = inputChar;
               }
               else
               {
                    cerr << "Error! You can only enter M or F" << endl;
               }
          }

          else if (sex.empty())
          {
               cerr << "Error! You must enter a character." << endl;
          }

          else
          {
               cerr << "Error! You can't enter more than one character." << endl;
          }
     }

     isValidInput = false;

     // still need to validate that input is not empty
     cout << "Please enter a number (18-100): ";
     while (!(isValidInput))
     {
          cin >> age;

          if (cin.fail())
          {
               cin.clear();
               cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
               cerr << "Error: input is not a valid type"
                    << "\n"
                    << "Input a number (18-100): ";
          }
          else if (cin.peek() != '\n')
          {
               cin.clear();
               cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
               cerr << "Error: input contains extra characters"
                    << "\n"
                    << "Input a number (18-100) with no spaces: ";
          }

          else if (age < 18 || age > 100)
          {
               cout << "Error: age must be in the range (18-100): ";
               cin >> age;
          }

          else
          {
               isValidInput = true; // Valid input, exit the loop
          }
     }

     isValidInput = true;

     cout << "Enter the number for the class that you want to be: (1 = Warrior, 2 = Mage, 3 = Archer): ";
     cin >> charNum;
     // input validation
     while (charNum != warrior && charNum != mage && charNum != archer)
     {
          cout << "Invalid class choice. (1 = Warrior, 2 = Mage, 3 = Archer) ";
          cin >> charNum;
     }

     // decides the user's stats based on the class they chose
     switch (charNum)
     {
     case warrior:
          charClass = "Warrior";
          charWeapon = weapons[0];
          playerDmg = 20;
          playerHp = 140;
          maxHp = 140;

          break;

     case mage:
          charClass = "Mage";
          charWeapon = weapons[1];
          playerDmg = 30;
          playerHp = 120;
          maxHp = 120;

          break;

     case archer:
          charClass = "Archer";
          charWeapon = weapons[2];
          playerDmg = 25;
          playerHp = 130;
          maxHp = 130;

          break;
     }

     system("cls");
     cout << endl;

     cout << "You created a character with these attributes: \n"
          << "Name: " << name << "\n"
          << "Race: " << race << "\n"
          << "Sex: " << sex << "\n"
          << "Age: " << age << "\n"
          << "Class: " << charClass << " \n \n";

     system("pause");
     system("cls");

     cout
         << "You live in the Enelidor Kingdom, and live in a town called Fort Tyforth, where you make a living selling weapons. \n"
         << "You leave your home and head out for the town center to begin setting up your weapons stand. \n"
         << "You only end up selling three weapons today, and you just barely scrape buy to make ends meet. \n";

     cout
         << "As you're walking back to your home, you overhear someone talking about traveling to Northhollow to become a soldier for king Samuel Woodward. \n"
         << "Apparently there was a dragon that destroyed a town about 50 miles from Fort Tyforth, "
         << "and it was rumored to have flew South toward a cliff at the end of the Trail of Tears. \n"
         << "They mention that there is a massive reward for the soldier who can successfully traverse the Trail of Tears and slay the dragon. \n \n";

     cout
         << "(" << name << " talking to themself): "
         << "Why don't I travel to Northhollow and prepare to journey through the Trail of Tears? \n"
         << "I would rather attempt to traverse the Trail of Tears and slay the dragon, then have to keep making weapons for the rest of my life. \n \n";

     cout << "The next morning you head on your way towards Northhollow in order to enlist on your quest to traverse the Trail of Tears and defeat the dragon. \n"
          << "After two days of traveling, you reach Northhallow and begin to prepare for your treacherous journey. \n"
          << "(Game will continue after 40 seconds) \n \n";

     cout << "You are now ready to embark on your journey... \n \n"
          << "Player class: " << charClass << "\n"
          << "Player weapon: " << charWeapon << "\n"
          << "Player health points: " << maxHp << "\n"
          << "Player damage: " << playerDmg << "\n \n";

     this_thread::sleep_for(chrono::seconds(40));

     system("cls");

     // creates and initializes objects of class Enemy
     Enemy goblin;
     goblin.setEnemyDmg(10);
     goblin.setEnemyHp(50);
     goblin.setEnemyMaxHp(50);
     v.push_back(goblin);

     Enemy knight;
     knight.setEnemyDmg(15);
     knight.setEnemyHp(75);
     knight.setEnemyMaxHp(75);
     v.push_back(knight);

     Enemy spider;
     spider.setEnemyDmg(20);
     spider.setEnemyHp(90);
     spider.setEnemyMaxHp(90);
     v.push_back(spider);

     Enemy dragon;
     dragon.setEnemyDmg(25);
     dragon.setEnemyHp(130);
     dragon.setEnemyMaxHp(130);
     v.push_back(dragon);

     enemySetup(v, enemyHp, enemyMaxHp, enemyDmg, c);

     cout << "You start off on the Trail of Tears and everything seems to be going fine. \n"
          << "Suddenly, a " << enemy << " jumps out in front of and thrusts its sword near you! \n \n";

     // displays player and enemy stats
     enemyStats(enemy, enemyDmg, enemyHp);
     charStats(playerDmg, playerHp, maxHp, hpPotions);

     cout << "What will you do? (a: attack, r: run, h: heal) ";
     cin >> cmd;
     cout << "\n";

     // function call
     choiceFunc(cmd, randNum, enemy, healAmount, playerHp, hpPotions, potionsDrank, maxHp, enemyHp, enemyDmg, playerDmg, turn, enemyMaxHp);
     // ends the program if the user died
     if (playerHp <= 0)
     {
          return 0;
     }
     cout << endl;

     cout << "You reach a fork in the road and are forced to make a decision, will you go left or right? (l: left, r: right) ";
     cin >> cmd;
     cout << "\n";
     // input validation
     while (cmd != 'l' && cmd != 'r')
     {
          cout << "Please enter a valid command: (l: left, r: right) \n";
          cin >> cmd;
     }
     // the user can branch off in two directions to determine the rest of the story
     if (cmd == 'l')
     {
          cout << "You decide to take the path on the left. \n"
               << "As you journey onward, you come to a mighty looking fortress, with four tall towers at each of its four corners. \n"
               << "You are far enough away that the guards near the entrance of the fort do not see you, so decide that you will... (t: talk to the guards, s: sneak around the fortress) ";

          cin >> cmd;

          while (cmd != 't' && cmd != 's')
          {
               cout << "Please enter a valid command: (t: talk to the guards, s: sneak around the fortress) ";
               cin >> cmd;
          }
          // if the user talks to the guards, they are rewarded with 2 health potions
          if (cmd == 't')
          {
               cout << "\n";
               cout << "You decide that you will talk to the guards. \n"
                    << "As you approach the entrance of the fortress, one guard walks towards you. \n"
                    << "You tell the guard that you are one a quest to slay the dragon that has been terrorizing the nearby towns. \n";

               cout << "The guard responds... \"Your quest is honorable, and I hope that you will succeed.\" \n"
                    << "\"I will allow you to pass through. Here's two health potion for your journey. Good luck!\" \n";
               hpPotions += 2;
               cout << "(Two health potion added to inventory. You have " << hpPotions << " health potions.) \n";
          }

          else
          {
               cout << "\n";
               cout << "You decide that you will attempt to sneak around the fortess, in order to avoid the intimidating guards. \n";
               srand(time(0));
               randNum = rand() % 2;

               if (randNum == 0)
               {
                    cout << "You snuck around the fortress successfully! \n \n";
                    c += 2;
               }

               else
               {
                    // sets up enemy variables since the user will now attack the enemy
                    enemy = enemyArr[1];
                    enemySetup(v, enemyHp, enemyMaxHp, enemyDmg, c);

                    cout << "As you sneak around the fortress, you hear footsteps behind you. Suddenly, a guard yells out at you and challenges you to fight him. \n \n";

                    enemyStats(enemy, enemyDmg, enemyHp);
                    charStats(playerDmg, playerHp, maxHp, hpPotions);

                    cout << "What will you do? (a: attack, r: run, h: heal) ";
                    cin >> cmd;

                    choiceFunc(cmd, randNum, enemy, healAmount, playerHp, hpPotions, potionsDrank, maxHp, enemyHp, enemyDmg, playerDmg, turn, enemyMaxHp);

                    if (playerHp <= 0)
                    {
                         return 0;
                    }
               }
          }
          cout << "It is getting dark outside and you need to find somewhere to spend the night. As you continue down the path, you find a small shack and decide to rest for the night. \n \n";
     }

     else
     {
          c++;

          cout << "You decide to take the path on the right. \n"
               << "It is getting dark outside and you need to find somewhere to spend the night. As you continue down the path, you see a cave entrance with giant stalactites hanging from the ceiling. \n"
               << "You decide that the cave would be the best spot to rest until the dawn. \n";

          cout << "You enter the cave and notice that there are giant cobwebs about twenty feet infront of you. \n"
               << "You begin to hear faint sounds of something crawling along the rocky floor. The sounds begin to increase in volume and speed. \n"
               << "*Hsssssssss!!!* A giant spider drops down from the ceiling above and confronts you. \n";
          // sets up enemy variables since the user will now attack the enemy
          enemy = enemyArr[2];
          enemySetup(v, enemyHp, enemyMaxHp, enemyDmg, c);

          enemyStats(enemy, enemyDmg, enemyHp);
          charStats(playerDmg, playerHp, maxHp, hpPotions);

          cout << "What will you do? (a: attack, r: run, h: heal) ";
          cin >> cmd;
          cout << endl;

          choiceFunc(cmd, randNum, enemy, healAmount, playerHp, hpPotions, potionsDrank, maxHp, enemyHp, enemyDmg, playerDmg, turn, enemyMaxHp);

          if (playerHp <= 0)
          {
               return 0;
          }
          // if the user did not run away from the spider, they get a better weapon
          if (cmd != 'r')
          {
               if (charNum == warrior)
               {
                    charWeapon = weapons[3];
               }

               else if (charNum == mage)
               {
                    charWeapon = weapons[4];
               }

               else
               {
                    charWeapon = weapons[5];
               }

               playerDmg += dmgIncrease;

               cout << "\n";
               cout << "You find a wooden chest in the cave! \n"
                    << "You find a " << charWeapon << " in the chest! (Your damage is increased by 5) \n"
                    << "Now that the spider is dead, you decide to rest in the cave until morning. \n";
          }
     }

     cout << "It is morning and you are close to reaching the location where the dragon is thought to reside. \n"
          << "You got a good nights rest, and are feeling rejuvinated and determined to slay the dragon. (Your max health is increased by 10, and you regain half your health) \n";
     maxHp += hpIncrease;
     playerHp += maxHp / 2;

     if (playerHp > maxHp)
     {
          playerHp = maxHp;
     }

     cout << "Health is now: (" << playerHp << "/" << maxHp << ") \n \n";

     cout << "You keep heading north, atticipating your impending fight with the dragon. \n"
          << "Up ahead, you see a rocky archway lodged between two small hills. It looks as though it's inviting you to enter. \n"
          << "Your body feels the urge to go there, so you decide that you will see if there is anything through the archway. \n"
          << "As you arrive at the archway, you realize that this must be the end of the Trail of Tears. \n"
          << "Through the arch, you see a rocky valley with a cliff at the end. \n"
          << name << " talking to themself: "
          << "This matches the location where the dragon is thought to be, but I don't see anything of interest. \n"
          << "You walk toward the edge of cliff and hear a faint noise... *wshhh* *wshhhhhhh* *WSHHHHHHHHHHHH! \n"
          << "The noise is now very powerful, and you feel a gust of air hit your head from above. \n"
          << "You look up and see a monstrous looking dragon with bright green scales, and a long neck. The dragon lands behind you. \n"
          << "The dragon notices you and shoots flames from its mouth towards you! \n";

     // sets up enemy variables since the user will now attack the final boss

     enemy = enemyArr[3];
     enemySetup(v, enemyHp, enemyMaxHp, enemyDmg, c);

     enemyStats(enemy, enemyDmg, enemyHp);
     charStats(playerDmg, playerHp, maxHp, hpPotions);

     cout << "What will you do? (a: attack, h: heal) ";
     cin >> cmd;

     bossFunc(randNum, cmd, enemy, healAmount, playerHp, hpPotions, potionsDrank, maxHp, enemyHp, enemyDmg, playerDmg, turn, enemyMaxHp);
     cout << endl;

     // ends the program if the user died
     if (playerHp <= 0)
     {
          return 0;
     }

     // runs if the user killed the dragon successfully
     else
     {
          cout << "Congratulations, you beat the game! :)";
     }

     return 0;
}

// Test: I have run extensive tests, and have found no issues, as long as the user doesn't type in a string when asked for an integer