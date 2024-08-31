#include <iostream>
#include <conio.h> // For _getch() and _putch()
#include <vector>
#include <random>
#include <thread>

using namespace std;

int main()
{
    string input;
    char ch;
    bool isValidPassword = false;
    vector<char> specialCharacters = {
        '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/',
        ':', ';', '<', '=', '>', '?', '@', '[', '\\', ']', '^', '_', '`', '{', '|', '}', '~'};

    cout << "Enter your secret input: ";
    int t = time(0);
    srand(t);

    // Loop until Enter is pressed
    while ((ch = _getch()) != '\r') // The enter key returns a value of '\r', when using _getch()
    {
        if (ch == '\b')
        { // If backspace is pressed
            if (!input.empty())
            {
                cout << "\b \b"; // Moves the cursor back, overwrites the character with a space, then moves the cursor back again
                input.pop_back(); // Remove last character from input string
            }
        }
        else
        {
            char randChar = specialCharacters[rand() % specialCharacters.size()];
            cout << randChar;
            input += ch; // Add character to input string
        }
    }

    cout << endl;

    cout << "You entered: " << input << endl;

    cout << "DONE";

    return 0;
}
