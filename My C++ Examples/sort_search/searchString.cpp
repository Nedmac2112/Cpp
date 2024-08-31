#include <iostream>
#include <vector>
#include <limits>
using namespace std;

vector<size_t> searchString(string &s, string &substr, int startSearch)
{
    vector<size_t> positions;
    size_t pos = s.find(substr, startSearch);
    while (pos != string::npos)
    {
        positions.push_back(pos);
        pos = s.find(substr, pos + 1);
    }
    return positions;
}

int main()
{
    string message = "Is No Mans Sky the best, or is Starfield the best?";
    string substr;
    int startSearch;
    bool searchAgain = true;
    bool validInput = false;

    while (searchAgain)
    {
        cout << "The message is: " << message << endl;
        cout << "Enter a sub-string to search for in the message: ";
        getline(cin, substr);

        while (substr.empty())
        {
            cout << "Error: enter a substring: ";
            getline(cin, substr);
        }

        validInput = false;
        cout << "At what position do you want to start searching from: ";
        while (!validInput)
        {
            if (cin >> startSearch)
            {
                if (startSearch >= 0 && startSearch <= message.length() - 1)
                {
                    validInput = true;
                }
                else
                {
                    cout << "Error: enter an integer in the range 0 - " << message.length() - 1 << ": ";
                }
            }
            else
            {
                cin.clear();                                         // Clear the error state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                cout << "Error: enter a valid integer: ";
            }
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

        vector<size_t> positions = searchString(message, substr, startSearch);
        if (positions.size() > 0)
        {
            cout << "Sub-string " << substr << " found at the following positions: " << endl;
            for (size_t pos : positions)
            {
                cout << pos << " ";
            }
        }
        else
        {
            cout << "The sub-string was not found in the original string";
        }
        cout << endl;

        cout << "Would you like to search for another sub-string in the message (1: YES, 0: NO)? ";
        validInput = false;
        while (!validInput)
        {
            if (cin >> searchAgain)
            {
                validInput = true;
            }
            else
            {
                cin.clear();                                         // Clear the error state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                cout << "Error: enter 1 to search for another sub-string, or 0 to quit: ";
            }
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

        cout << endl
             << "--------------------------------------------------------------------------------" << endl;
    }

    cout << "END OF PROGRAM";

    return 0;
}
