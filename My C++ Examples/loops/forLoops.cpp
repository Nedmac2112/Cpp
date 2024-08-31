#include <iostream>
using namespace std;

int main()
{
    // for loop that prints out numbers 0-9
    for (int i = 0; i < 10; i++)
    {
        cout << i << endl;
    }
    cout << endl;

    // for loop that prints out numbers 10-0
    for (int i = 10; i >= 1; i--)
    {
        cout << i << endl;
    }
    cout << endl;

    // you can use multiple counter variables
    for (int i = 0, j = 0; i < 5; i++, j += 2)
    {
        cout << i << " " << j << endl;
    }
    cout << endl;

    string r[] = {"dog", "cat", "mouse", "fish"};

    // rang-based for loop that prints out an array of strings
    for (string i : r)
    {
        cout << i + " ";
    }

    cout << endl
         << endl;

    string greeting = "hello";

    // range-based for loop that prints out a string
    // the first parameter is what type you want to print out, the second is what you are iterating over
    for (char c : greeting)
    {
        cout << c << endl;
    }

    return 0;
}