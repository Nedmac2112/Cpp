// Program that takes a string and parses it into two parts using an input string stream

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string name = "Camden Kirkpatrick";
    // the input string stream holds "Camden Kirkpatrick"
    istringstream nameStream(name);

    string firstName, lastName;
    // firstName is assigned the first value in the nameStream
    // lastName is assigned the second value in the nameStream
    nameStream >> firstName >> lastName;

    cout << "first name: " << firstName << endl;
    cout << "last name: " << lastName << endl;

    return 0;
}