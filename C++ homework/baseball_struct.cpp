// Camden K., 11/1/23, cckirkpatrick@dmacc.edu
// program that prints out a list of information of baseball players, using a struct

// libraries
#include <iostream>
using namespace std;

// struct that stores the information for each baseball player
struct BaseballPlayer
{
    string name;
    double batAvg;
    int numHomeRuns;
    int RBI;
    int runsScored;
    int stolenBases;
    string team;
    double salary;
};

// function that prints the information to the console
void print(BaseballPlayer player)
{
    cout << "Name: " << player.name << endl;
    cout << "Batting average: " << player.batAvg << endl;
    cout << "Home runs scored: " << player.numHomeRuns << endl;
    cout << "Player RBI: " << player.RBI << endl;
    cout << "Runs scored: " << player.runsScored << endl;
    cout << "Bases stolen: " << player.stolenBases << endl;
    cout << "Player team: " << player.team << endl;
    cout << "Player salary: " << player.salary << endl;
}

int main()
{
    // create 3 play instances/objects of struct BaseballPlayer
    BaseballPlayer player1;
    BaseballPlayer player2;
    BaseballPlayer player3;

    // values for object 1
    player1.name = "Henry";
    player1.batAvg = .280;
    player1.numHomeRuns = 4;
    player1.RBI = 307;
    player1.runsScored = 130;
    player1.stolenBases = 9;
    player1.team = "Cardinals";
    player1.salary = 850000;

    // values for object 2
    player2.name = "Jackson";
    player2.batAvg = .267;
    player2.numHomeRuns = 2;
    player2.RBI = 289;
    player2.runsScored = 103;
    player2.stolenBases = 10;
    player2.team = "Blue Jays";
    player2.salary = 525000;

    // values for object 3
    player3.name = "Zach";
    player3.batAvg = .251;
    player3.numHomeRuns = 3;
    player3.RBI = 280;
    player3.runsScored = 97;
    player3.stolenBases = 6;
    player3.team = "Cubs";
    player3.salary = 300000;

    // prints information to the console
    print(player1);
    cout << endl;
    print(player2);
    cout << endl;
    print(player3);

    return 0;
}

/* Test
Received all expected information in the console for each object
*/