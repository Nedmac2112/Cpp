// #include <iostream>

// using namespace std;

// int divideFloats(int numerator, int denominator)
// {
//     if (denominator == 0)
//     {
//         throw runtime_error("Division by zero error");
//     }
//     return numerator / denominator;
// }

// int main()
// {
//     int numerator, denominator;
//     bool isValidInput = false;

//        while (!isValidInput)
//     {
//         cout << "Enter the numerator: ";
//         cin >> numerator;
//         cout << "Enter the denominator: ";
//         cin >> denominator;

//         try
//         {
//             int result = divideFloats(numerator, denominator);
//             cout << "Result of division: " << result << endl;
//             isValidInput = true; // Set isValidInput to true if division is successful
//         }
//         catch (const runtime_error &e)
//         {
//             cout << "Error: " << e.what() << endl;
//         }
//     }

//     return 0;
// }

#include <iostream>
#include <stdexcept> // For runtime_error
#include <limits>    // For numeric limits

using namespace std;

int divideFloats(int numerator, int denominator)
{
    if (denominator == 0)
    {
        throw runtime_error("Division by zero error");
    }
    return static_cast<float>(numerator) / denominator;
}

int main()
{
    int numerator, denominator;
    bool isValidInput = false;

    // Loop for the numerator input
    while (!isValidInput)
    {
        cout << "Enter the numerator: ";
        cin >> numerator;

        // Check if the input is valid
        if (cin.fail())
        {
            cin.clear();                                         // Clear the error flag on cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the invalid input
            cout << "Error: Please enter a valid integer for the numerator." << endl;
        }
        else
        {
            isValidInput = true; // Valid input for numerator
        }
    }

    // Reset isValidInput for the denominator input
    isValidInput = false;

    // Loop for the denominator input
    while (!isValidInput)
    {
        cout << "Enter the denominator: ";
        cin >> denominator;

        // Check if the input is valid
        if (cin.fail())
        {
            cin.clear();                                         // Clear the error flag on cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the invalid input
            cout << "Error: Please enter a valid integer for the denominator." << endl;
        }
        else
        {
            try
            {
                int result = divideFloats(numerator, denominator);
                cout << "Result of division: " << result << endl;
                isValidInput = true; // Set isValidInput to true if division is successful
            }
            catch (const runtime_error &e)
            {
                cout << "Error: " << e.what() << endl;
                isValidInput = false; // Continue to prompt if there was a division error
            }
        }
    }

    return 0;
}
