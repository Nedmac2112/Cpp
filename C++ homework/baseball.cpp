// Camden K, 10-6-23, cckirkpatrick@dmacc.edu
/* Program that combines two baseball (Leauges.txt and "Teams.txt")
 files into one file (outputbb.txt) */

// libraries
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// start of program
int main()
{
    // declare file streams
    ifstream leaguesFile;
    ifstream teamsFile;
    ofstream outFile;

    // declare strings
    string teamName;
    string teamLeague;

    // opens the files
    leaguesFile.open("Leagues.txt");
    teamsFile.open("Teams.txt");
    outFile.open("outputbb.txt");

    // if all files are open, execute the code
    if (teamsFile.is_open() && leaguesFile.is_open() && outFile.is_open())
    {
        // gets the strings for each team name and team league, and combines them into one file
        while (getline(teamsFile, teamName) && getline(leaguesFile, teamLeague))
        {
            outFile << teamName << ":\t " << teamLeague << endl;

            // when done, display to console
            cout << "outputbb.txt was generated successfully" << endl;
        }
    }

    // if one or more files fails to open... display to console
    else
    {
        cout << "One or more files failed to open";
    }

    // end
    return 0;
}

// Test: program ran successfully with no error, and "outputbb.txt" had the correct format