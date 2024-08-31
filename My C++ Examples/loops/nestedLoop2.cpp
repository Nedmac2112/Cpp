#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // multiplies numbers 1 through 10, by 1 through 10, using a nested for loop
    for (int x = 1; x <= 10; x++)
    {
        cout << "Products of " << x << endl;
        for (int y = 1; y <= 10; y++)
        {
            cout << x * y << endl;
        }
        cout << endl;
    }

    // runs 3 times
    for (int x = 1; x <= 3; x++)
    {
        for (int y = 1; y < 3; y++)
        {
            if (y == 2)
            {
                // this goes back to the outer loop
                break;
            }

            // after this runs twice, it runs the y for loop
            for (int z = 1; z < 3; z++)
            {
                cout << x << " " << y << " " << z << endl;
            }
        }
    }
    cout << endl
         << endl;

    const int maxValue = 10 * 10;                            // The largest number in the table
    const int fieldWidth = to_string(maxValue).length() + 1; // +1 for extra space

    cout << "Multiplication Table" << endl
         << endl;
    // Print the header row
    cout
        << setw(fieldWidth) << left << "*"; // Align the header
    for (int x = 0; x < 12; x++)
    {
        cout << setw(fieldWidth) << left << x + 1;
    }
    cout << endl;

    // Print the multiplication table
    for (int y = 0; y < 12; y++)
    {
        cout << setw(fieldWidth) << left << y + 1; // Print row label

        for (int x = 0; x < 12; x++)
        {
            cout << setw(fieldWidth) << left << ((x + 1) * (y + 1));
        }
        cout << endl;
    }

    return 0;
}
