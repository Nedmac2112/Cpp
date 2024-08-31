// Camden K., 10-11-23, cckirkpatrick@dmacc.edu
// Program that finds the average of four temperatures using a return function

// libraries
#include <iostream>
using namespace std;

// function that takes the average of four temperatures and the returns the value
int averageFourTemperatures(int temp1, int temp2, int temp3, int temp4)
{

    int avgTemp = (temp1 + temp2 + temp3 + temp4) / 4;
    return avgTemp;
}

// start
int main()
{
    // declare variables
    int num1, num2, num3, num4;

    // Prompts user to input four temperatures
    cout << "Please enter 4 temperatures in degrees Fahrenheit:" << endl;
    cin >> num1;
    cin >> num2;
    cin >> num3;
    cin >> num4;

    // detects if the temperature is too high
    while (num1 > 120 || num2 > 120 || num3 > 120 || num4 > 120)
    {
        cout << "Temperature range was invalid." << endl;
        cout << "Please enter 4 temperatures (range: 40-120):" << endl;
        cin >> num1;
        cin >> num2;
        cin >> num3;
        cin >> num4;
    }

    // detects if the temperature is too low
    while (num1 < -40 || num2 < -40 || num3 < -40 || num4 < -40)
    {
        cout << "Temperature range was invalid." << endl;
        cout << "Please enter 4 temperatures (range: 40-120):" << endl;
        cin >> num1;
        cin >> num2;
        cin >> num3;
        cin >> num4;
    }

    // outputs the average temperature to the console
    cout << "The average temperature is " << averageFourTemperatures(num1, num2, num3, num4) << " degrees Fahrenheit.";

    // end
    return 0;
}

/* Tests
Input: 32, 76, 0, 50, expected: 39, received: 39
Input: 100, 45, -74, 13, expected: Temperature range was invalid, received: Temperature range was invalid
*/