// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;

// // Function to find matches in a vector of strings
// void find_matches(const vector<string> &data, const string &key)
// {
//     vector<size_t> indices; // Create a vector to store indices of matches

//     // Iterate through the vector of data
//     for (size_t i = 0; i < data.size(); ++i)
//     {
//         // Check if the key is found in the current item
//         if (data[i].find(key) != string::npos)
//         {
//             indices.push_back(i); // Add the index to indices
//         }
//     }

//     // Output the results
//     cout << "Found " << indices.size() << " matches at indices: ";
//     for (size_t i = 0; i < indices.size(); ++i)
//     {
//         cout << indices[i];
//         if (i != indices.size() - 1)
//         {
//             cout << " ";
//         }
//     }
//     cout << endl;

//     // Output the matched items
//     cout << "Matching items: ";
//     for (size_t i = 0; i < indices.size(); ++i)
//     {
//         cout << data[indices[i]]; // you could also create a separate vector to store the matched items, but this is more efficient (less memory)
//         if (i != indices.size() - 1)
//         {
//             cout << " ";
//         }
//     }
//     cout << endl;
// }

// int main()
// {
//     vector<string> data = {
//         "apple pie",
//         "banana split",
//         "cherry tart",
//         "apple crisp",
//         "blueberry muffin"};

//     string key = "apple";

//     find_matches(data, key);

//     return 0;
// }

#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

void find_matches(const vector<string> &data, const string &key, int startSearch)
{
    vector<size_t> indices; // Create a vector to store indices of matches

    // Iterate through the vector of data starting from startSearch position
    for (size_t i = startSearch; i < data.size(); ++i)
    {
        // Check if the key is found in the current item
        if (data[i].find(key) != string::npos)
        {
            indices.push_back(i); // Add the index to indices
        }
    }

    // Output the results
    cout << "Found " << indices.size() << " matches at indices: ";
    for (size_t i = 0; i < indices.size(); ++i)
    {
        cout << indices[i];
        if (i != indices.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;

    // Output the matched items
    cout << "Matching items: ";
    for (size_t i = 0; i < indices.size(); ++i)
    {
        cout << data[indices[i]]; // You could also create a separate vector to store the matched items, but this is more efficient (less memory)
        if (i != indices.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;
}

int main()
{
    vector<string> data = {
        "apple pie",
        "banana split",
        "cherry tart",
        "apple crisp",
        "blueberry muffin"};

    string key;
    int startSearch;
    bool searchAgain = true;
    bool validInput = false;

    while (searchAgain)
    {
        cout << "Enter a key to search for in the data: ";
        getline(cin, key);

        while (key.empty())
        {
            cout << "Error: enter a key: ";
            getline(cin, key);
        }

        validInput = false;
        cout << "At what position do you want to start searching from: ";
        while (!validInput)
        {
            if (cin >> startSearch)
            {
                if (startSearch >= 0 && startSearch <= data.size() - 1)
                {
                    validInput = true;
                }
                else
                {
                    cout << "Error: enter an integer in the range 0 - " << data.size() - 1 << ": ";
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

        find_matches(data, key, startSearch);

        cout << "Would you like to search for another key in the data (1: YES, 0: NO)? ";
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
                cout << "Error: enter 1 to search for another key, or 0 to quit: ";
            }
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

        cout << endl
             << "--------------------------------------------------------------------------------" << endl;
    }

    cout << "END OF PROGRAM";

    return 0;
}
