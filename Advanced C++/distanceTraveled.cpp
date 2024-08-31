// Camden K., 8/22/24, cckirkpatrick@dmacc.edu
// Program to display a table of distance traveled by a vehicle
// based on the speed and time it has traveled

#include <iostream>
using namespace std;

// Function to display the table of distance traveled
void displayDistanceTable(int speed, int time)
{
    cout << "Hour\tDistance Traveled" << endl;
    cout << "------------------------" << endl;
    for (int i = 1; i <= time; i++)
    {
        cout << i << "\t" << speed * i << endl;
    }
}

int main()
{
    int speed;
    int time;

    // Input validation for speed
    do
    {
        cout << "Enter the speed of the vehicle (mph): ";
        cin >> speed;

        if (speed <= 0)
        {
            cout << "Invalid input. Speed must be positive." << endl;
        }
    } while (speed <= 0);

    // Input validation for time
    do
    {
        cout << "Enter the time the vehicle has traveled (hours): ";
        cin >> time;

        if (time <= 0)
        {
            cout << "Invalid input. Time must be positive." << endl;
        }
    } while (time <= 0);

    // Call the function to display the table
    displayDistanceTable(speed, time);

    return 0;
}

/* Tests:
Tested with speed = 60 and time = 5, which resulted in the following output:
Hour    Distance Traveled
------------------------
1       60
2       120
3       180
4       240
5       300

Negative test cases were also checked for speed and time, which resulted in the appropriate error messages.
*/
