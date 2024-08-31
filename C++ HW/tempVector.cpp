// Camden K., 10/18/23, cckirkpatrick@dmacc.edu
// program that uses a vector and calculates the average temperature on the even days

// libraries
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    // declare and initialize variables
    double temp;
    int quit = 999;
    int day;
    int counter = 0;
    double sum;
    double average;

    // declare vector
    vector<double> temperatures;

    cout << "Enter a list of temperatures" << endl;

    // allows the user to input temperatures into the vector
    while (true)
    {
        cin >> temp;

        // checks to see if the users input is valid
        if (temp >= -50 && temp <= 150)
        {
            temperatures.push_back(temp);
            cout << "temperatures at index " << day << " is: " << temperatures.at(day) << endl;
            day++;
        }

        // allows the user to quit the program
        else if (temp == quit)
        {
            break;
        }

        // displays an error message if the input was invald
        else
        {
            cout << "Please enter a number -50 through 150. Enter \"999\" to quit: ";
        }
    }

    // calculates the sum on the even days
    for (int i = 0; i < temperatures.size(); i += 2)
    {

        sum = sum + temperatures.at(i);
        counter++;
    }

    // calculates the average temperature on even days
    average = sum / counter;

    // outputs the average to the console
    cout << "Average temperature of even days: " << fixed << setprecision(2) << average << endl;

    return 0;
}

/* Tests
Input: 87, 12, 34, 120, -34, 10. Expected: 29.00. Received: 29.00*
Input: 200. Expected: Please enter a number -50 through 150. Enter "999" to quit.
Received: Please enter a number -50 through 150. Enter "999" to quit.
*/