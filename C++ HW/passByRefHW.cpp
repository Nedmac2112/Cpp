// Camden K., 12/5/23, cckirkpatrick@dmacc.edu
// Program that passes by reference and changes the value of two variables in the main program

#include <iostream>
using namespace std;

// function that accepts two string parameters by reference
void name(string &firstName, string &lastName)
{
    // variables that will hold the new values for the users first and last name
    string fName;
    string lName;

    // user input
    cout << "Enter your first and last name: ";
    cin >> fName >> lName;

    // assigns the value of firstName and lastName in the main program to the new names the user inputted
    firstName = fName;
    lastName = lName;
}

int main()
{
    // variable declaration
    string firstName;
    string lastName;

    cout << "Enter your first and last name: ";
    cin >> firstName >> lastName;

    cout << "Your name is: " << firstName << " " << lastName << endl
         << endl;

    // calls the name function
    name(firstName, lastName);

    // displays the new value of firstName and lastName;
    cout << "firstName = " << firstName << endl;
    cout << "lastName = " << lastName;

    return 0;
}

/*
Test
Input: Camden Kirkpatrick, Camden Johnson
Expected: Your name is: Camden Kirkpatrick (newlines) firstName = Camden (newline) lastName = Johnson
Received: Your name is: Camden Kirkpatrick (newlines) firstName = Camden (newline) lastName = Johnson
*/