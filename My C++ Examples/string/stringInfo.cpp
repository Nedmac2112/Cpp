// #include <iostream>
// #include <string>
// #include <vector>
// #include <cctype>
// #include <iomanip>

// using namespace std;

// // Function to print results of the character analysis
// void printResults(const string &label, int count, const string &s, const vector<size_t> &indices)
// {
//     cout << label << " found: " << count << endl;
//     if (count > 0)
//     {
//         for (size_t i = 0; i < indices.size(); i++)
//         {
//             if (label == "Blank characters")
//             {
//                 cout << "Blank found at index " << indices[i] << " in \"" << s << "\"" << endl;
//             }
//             else
//             {
//                 cout << "\'" << s[indices[i]] << "\' found at index " << indices[i] << " in \"" << s << "\"" << endl;
//             }
//         }
//     }
//     cout << endl;
// }

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <iomanip>

using namespace std;

// Function to print results of the character analysis
void printResults(const string &label, int count, const string &s, const vector<size_t> &indices)
{
    // Print the label and count
    cout << label + " found:" << right << setw(4) << count << endl;

    // Check if there are any indices to print
    if (count > 0)
    {
        // Print each index and corresponding character
        for (size_t i = 0; i < indices.size(); ++i)
        {
            if (label == "Blank characters")
            {
                cout << "Blank found at index " << right << setw(2) << indices[i] << " in \"" << s << "\"" << endl;
            }
            else
            {
                cout << "'" << s[indices[i]] << "' found at index " << right << setw(4) << indices[i] << " in \"" << s << "\"" << endl;
            }
        }
    }
    cout << endl;
}

// Function to analyze the characters in the string and count various types
void analyzeCharacters(const string &s, int &alnumCount, int &alphaCount, int &digitCount, int &blankCount, int &specialCount, int &lowerCount,
                       int &upperCount, vector<size_t> &alnumIndices, vector<size_t> &alphaIndices, vector<size_t> &digitIndices,
                       vector<size_t> &blankIndices, vector<size_t> &specialIndices, vector<size_t> &lowerIndices, vector<size_t> &upperIndices)
{
    for (size_t i = 0; i < s.length(); i++)
    {
        if (isalnum(s[i]))
        {
            alnumCount++;
            alnumIndices.push_back(i);
        }
        if (isalpha(s[i]))
        {
            alphaCount++;
            alphaIndices.push_back(i);
        }
        if (isdigit(s[i]))
        {
            digitCount++;
            digitIndices.push_back(i);
        }
        if (isblank(s[i]))
        {
            blankCount++;
            blankIndices.push_back(i);
        }
        if (!isalnum(s[i]) && !isblank(s[i]))
        {
            specialCount++;
            specialIndices.push_back(i);
        }
        if (islower(s[i]))
        {
            lowerCount++;
            lowerIndices.push_back(i);
        }
        if (isupper(s[i]))
        {
            upperCount++;
            upperIndices.push_back(i);
        }
    }
}

// Function to analyze characters based on the selected category
void analyzeSelectedCategory(const string &s, char choice)
{
    int alnumCount = 0, alphaCount = 0, digitCount = 0, blankCount = 0, specialCount = 0, lowerCount = 0, upperCount = 0;
    vector<size_t> alnumIndices, alphaIndices, digitIndices, blankIndices, specialIndices, lowerIndices, upperIndices;

    // Analyze characters in the string and store the counts and indices
    analyzeCharacters(s, alnumCount, alphaCount, digitCount, blankCount, specialCount, lowerCount, upperCount, alnumIndices,
                      alphaIndices, digitIndices, blankIndices, specialIndices, lowerIndices, upperIndices);

    // Switch case to print results based on user choice
    switch (choice)
    {
    case '1':
        printResults("Alpha-numeric characters", alnumCount, s, alnumIndices);
        break;
    case '2':
        printResults("Alphabetic characters", alphaCount, s, alphaIndices);
        break;
    case '3':
        printResults("Digit characters", digitCount, s, digitIndices);
        break;
    case '4':
        printResults("Blank characters", blankCount, s, blankIndices);
        break;
    case '5':
        printResults("Special characters", specialCount, s, specialIndices);
        break;
    case '6':
        printResults("Lowercase characters", lowerCount, s, lowerIndices);
        break;
    case '7':
        printResults("Uppercase characters", upperCount, s, upperIndices);
        break;
    case '8':
        // Print results for all categories
        printResults("Alpha-numeric characters", alnumCount, s, alnumIndices);
        printResults("Alphabetic characters", alphaCount, s, alphaIndices);
        printResults("Digit characters", digitCount, s, digitIndices);
        printResults("Blank characters", blankCount, s, blankIndices);
        printResults("Special characters", specialCount, s, specialIndices);
        printResults("Lowercase characters", lowerCount, s, lowerIndices);
        printResults("Uppercase characters", upperCount, s, upperIndices);
        break;
    }
}

// Function to display the menu
void displayMenu()
{
    cout << "---------------------------------------------" << endl;
    cout << "Menu:" << endl;
    cout << "1. Analyze alpha-numeric characters" << endl;
    cout << "2. Analyze alphabetic characters" << endl;
    cout << "3. Analyze digit characters" << endl;
    cout << "4. Analyze blank characters (spaces and tabs)" << endl;
    cout << "5. Analyze special characters" << endl;
    cout << "6. Analyze lowercase characters" << endl;
    cout << "7. Analyze uppercase characters" << endl;
    cout << "8. Analyze all character categories" << endl;
    cout << "0. Exit" << endl;
    cout << "N. Enter a new string" << endl;
    cout << "---------------------------------------------" << endl;
}

int main()
{
    string s;
    char choice;
    bool continueProgram = true;
    bool validInput = false;
    bool newString = true;

    while (continueProgram)
    {
        // If a new string is to be entered, prompt the user for input
        if (newString)
        {
            cout << "Enter a string to analyze: ";
            getline(cin, s);

            // Ensure the input is not empty or starting with a space
            while (s.empty() || s.find_first_of(" \t") == 0)
            {
                cout << "Input is empty or starts with a space, please enter something: ";
                getline(cin, s);
            }
        }

        validInput = false;
        while (!validInput)
        {
            // Display the menu
            displayMenu();

            // Get user choice
            cout << "Enter your choice (1-8, 0 to exit, N to enter a new string): ";
            cin >> choice;
            cin.ignore(); // Ignore the newline character left in the input buffer
            cout << endl;

            if (choice == '0')
            {
                // Exit the program
                cout << "Exiting program";
                continueProgram = false;
                validInput = true;
            }
            else if (choice == 'N' || choice == 'n')
            {
                // Prompt for a new string
                newString = true;
                validInput = true;
            }
            else if (choice >= '1' && choice <= '8')
            {
                // Analyze the selected category
                analyzeSelectedCategory(s, choice);
                validInput = true;
                newString = false; // Don't prompt for a new string after analysis
            }
            else
            {
                // Invalid choice, prompt again
                cout << "Invalid choice. Please enter a number between 1 and 8, 0 to exit, or 'N' to enter a new string." << endl;
            }
        }
    }

    return 0;
}
