// Purpose: Demonstrate the use of enums in C++
// Description: This program demonstrates the use of enums in C++. The program defines an enum called Day with the days of the week. The program uses a for loop to iterate through the days of the week and outputs whether each day is a weekend day or a weekday.
// Last modified: 5/7/2024

#include <iostream>
using namespace std;

int main()
{
    // enums give an integer value to a named variable
    // this makes it more readable instead of using just numbers
    enum Day
    {
        Sunday = 1,
        Monday = 2,
        Tuesday = 3,
        Wednesday = 4,
        Thursday = 5,
        Friday = 6,
        Saturday = 7
    };

    for (int i = Sunday; i <= Saturday; i++)
    {
        cout << "Day " << i << " ";

        if (i == Sunday || i == Saturday)
            cout << "is a weekend day" << endl;
        else
            cout << "is a weekday" << endl;
    }

    return 0;
}