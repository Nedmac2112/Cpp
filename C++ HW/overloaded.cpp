// Camden K., 10-11-23, cckikrpatrick@dmacc.edu
// Program that uses overloaded functions for a ticket master

// libraries
#include <iostream>
using namespace std;

// setting up overloaded functions
// this function doesn't take any parameters
void ticketsearch()
{

    cout << "Looking for single ticket at highest price in any section in the Auditorium" << endl;
}

// this function takes a number as a parameter
void ticketsearch(int number)
{
    // makes sure that the number of tickets is >= 1
    if (number < 1)
    {
        cout << "Enter a valid number";
    }

    else
    {
        cout << "Looking for " << number << " tickets at highest price in any section in the Auditorium" << endl;
    }
}

// this function takes number and max as parameters
void ticketsearch(int number, double max)
{
    // makes sure that the number of tickets is >= 1 and the max price >= 1
    if (number < 1 || max < 1)
    {
        cout << "Enter a valid number (must be 1 or greater)" << endl;
    }

    else
    {

        cout << "Looking for " << number << " tickets at maximum cost of " << max << " each in any section in the Auditorium" << endl;
    }
}

// this function takes number, max and section as parameters
void ticketsearch(int number, double max, string section)
{
    // makes sure that the number of tickets is >= 1 and the max price >= 1
    if (number < 1 || max < 1)
    {
        cout << "Enter a valid number (must be 1 or greater)" << endl;
    }

    else
    {
        cout << "Looking for " << number << " tickets at maximum cost of " << max << " each on the " << section << " section of the Auditorium" << endl;
    }
}
// start
int main()

{
    cout << "Make sure that the first and second arguments are >= 1, and the last argument is a string." << endl;
    // calling each overloaded function
    cout << "ticketsearch(): Function with no arguments" << endl;
    ticketsearch();
    cout << endl;

    cout << "ticketsearch(number): Function with 1 argument" << endl;
    ticketsearch(2);
    cout << endl;

    cout << "ticketsearch(number,max): Function with 2 arguments" << endl;
    ticketsearch(6, 0);
    cout << endl;

    cout << "ticketsearch(number,max,section): Function with 3 arguments" << endl;
    ticketsearch(4, 38.00, "Floor");

    // end
    return 0;
}

/* Tests
Input: ticketsearch(6, 0), expected: "Enter a valid number (must be 1 or greater)"
received: "Enter a valid number (must be 1 or greater)"
Input: ticketsearch(), expected: "Looking for single ticket at highest price in any section in the Auditorium"
received: "Looking for single ticket at highest price in any section in the Auditorium"
*/