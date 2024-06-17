// Camden K., 9/26/23, cckirkpatrick@dmacc.edu
// Program that calculates your account value over a period of 10 years

#include <iostream>
// included in order to use the "string" variable type
#include <string>
using namespace std;

// declare and initialize variable(s)
string name;
double savingsRate;
int salary;
double accountValue = 0.0;

int main()
{
    // user input for name
    while (true)
    {
        cout << "Enter your name (q to quit): ";
        cin >> name;

        // allows the user to exit the program
        if (name == "q")
        {
            break;
        }

        // user input for savings rate
        cout << "Enter savings rate: ";
        cin >> savingsRate;

        // makes sure user input is valid
        while (savingsRate < 0 || savingsRate > 1)
        {
            cout << "Invalid savings rate. Enter a value between 0 and 1: ";
            cin >> savingsRate;
        }

        // user input for salary
        cout << "Enter salary: ";
        cin >> salary;

        // makes sure user input is valid
        while (salary < 0)
        {
            cout << "Invalid salary. Enter a value greater than 0";
            cin >> salary;
        }

        cout << "The account values for " << name << " are:" << endl;

        // for loop that calculates the total account value for years 1-10
        for (int year = 1; year <= 10; year++)
        {
            accountValue = (accountValue + savingsRate * salary) * 1.08;
            cout << accountValue << endl;
        }

        cout << endl;
    }

    // runs only if the user enters "q" for their name
    cout << "bye" << endl;

    return 0;
}

/* Test:
Input (name: Camden), (savingsRate: 0.08), (salary: 60500)
Expected:
The account values for Camden are:
5227.2
10872.6
16969.6
23554.3
30665.9
38346.4
46641.3
55599.8
65275
75724.2
Received: all previous values were received*/