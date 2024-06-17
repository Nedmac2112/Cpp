#include <iostream>
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

    return 0;
}