// Camden K., 10/18/23, cckirkpatrick@dmacc.edu
// program that uses an array and calculates the average temperature

// libraries
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // declaration and initialization
    int temperatures[5];
    int temp;
    int counter = 0;
    int counter_2 = 0;
    double sum;
    int arrayLength = 5;
    double average;

    cout << "Please enter 5 temperatures" << endl;

    // loop that allows the user to input temperatures into an array
    while (true)
    {
        cin >> temp;
        // checks to see if the user's input is valid
        if (temp >= -50 && temp <= 150)
        {
            temperatures[counter] = temp;
            cout << "temperatures array at index " << counter << " is: " << temperatures[counter] << endl;
            counter++;
        }

        // if the user's input wasn't valid this executes
        else
        {
            cout << "Please enter a number -50 through 150" << endl;
        }

        // ends the while loop
        if (counter == arrayLength)
        {
            break;
        }
    }

    // calculates the sum of the elements in the array
    for (counter_2; counter_2 < counter; counter_2++)
    {
        sum = sum + temperatures[counter_2];
    }

    // calculates the average
    average = sum / counter;

    // outputs the average to the console
    cout << "The average is: " << fixed << setprecision(2) << average << endl;

    return 0;
}

/* Tests
Input: 10, 67, -35, 126, 0. Expected: 33.60. Received: 33.60
Input: 200. Expected: Please enter a number -50 through 150.
Received: Please enter a number -50 through 150
*/