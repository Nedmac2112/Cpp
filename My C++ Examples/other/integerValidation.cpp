// This program shows 3 ways to validate user input for an integer
// The first one is a simple way to check if the input is an integer (this one does not flag for empty input)
// The second one is a more complex way to check if the input is an integer (this one flags for empty input)
// The third one is a way to check if the input is an integer using the C++ stoi function (this one flags for empty input)


#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int num;
    cout << "Enter an integer: ";

    // This is similar to the example below, however, it doesnt flag for empty input
    while (!(cin >> num) || cin.peek() != '\n')
    {
        cout << "Invalid input. Please enter an integer: ";
        cin.clear();                                         // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }

    cout << "You entered: " << num << endl;
    cout << num + 1;

    return 0;
}

// #include <iostream>
// #include <string>
// #include <cctype> // for isdigit
// using namespace std;

// bool isValidInteger(const string &input)
// {
//     // If input is empty, it's not valid
//     if (input.empty())
//     {
//         return false;
//     }

//     else
//     {
//         // Check each character in the input string
//         for (int i = 0; i < input.size(); i++)
//         {
//             if (!isdigit(input[i]))
//             {
//                 // If the character is not a digit
//                 // Check if it's the first character and it's a sign
//                 if (i == 0)
//                 {
//                     if ((input[i] == '-' || input[i] == '+') && i == 0)
//                     {
//                         // Allow leading sign
//                         continue;
//                     }

//                     else
//                     {
//                         // If it's not a digit and not a leading sign, input is invalid
//                         return false;
//                     }
//                 }
//                 else
//                 {
//                     // If it's not the first character and not a digit, input is invalid
//                     return false;
//                 }
//             }
//         }
//     }

//     return true;
// }

// int main()
// {
//     int num;
//     string input;

//     while (true)
//     {
//         cout << "Enter an integer: ";
//         getline(cin, input);

//         if (!isValidInteger(input))
//         {
//             cout << "Invalid input. ";
//             continue;
//         }

//         try
//         {
//             num = stoi(input);
//             break;
//         }

//         catch (const out_of_range &e)
//         {
//             cerr << "Input out of range. Please enter a smaller integer." << endl;
//         }
//     }

//     cout << "You entered: " << num << endl;
//     cout << num + 1 << endl;

//     return 0;
// }
