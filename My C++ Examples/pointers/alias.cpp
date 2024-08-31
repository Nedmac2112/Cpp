// Purpose: Demonstrate how to create an alias for a string using a reference and a pointer
// Description: This program demonstrates how to create an alias for a string using a reference and a pointer. The program creates two strings, OriginalString and OriginalString2. The program then creates an alias for OriginalString called StringCopy using a reference. The program then creates an alias for OriginalString2 called StringCopy2 using a pointer. The program then changes the values of OriginalString and OriginalString2. The program demonstrates that changing the value of OriginalString also changes the value of StringCopy, and changing the value of OriginalString2 also changes the value of StringCopy2.
// Last modified: 05/10/2024

#include <iostream>
using namespace std;

int main()
{
    string OriginalString = "Taco";
    string OriginalString2 = "Squirrel";
    // StringCopy is an alias for OriginalString, and points to the same memory location
    // Const is used to prevent the alias from being changed
    // This does not create a new string, it just creates a new name for the same string
    const string &StringCopy = OriginalString;
    // This is the same as the above line, but with a pointer
    const string *StringCopy2 = &OriginalString2;

    OriginalString = "Pizza";
    OriginalString2 = "Penguin";

    cout << OriginalString << endl;
    cout << StringCopy << endl;
    cout << OriginalString2 << endl;
    cout << *StringCopy2 << endl;
    return 0;
}