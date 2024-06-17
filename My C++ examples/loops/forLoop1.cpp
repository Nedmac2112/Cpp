#include <iostream>
using namespace std;

int main()
{
    string A = "Hello";
    string B = "1122334455";

    // // you can use multiple counter variables
    for (int i = 0, j = 0; i < 5; i++, j += 2)
    {
        cout << A[i] << B[j] << endl;
    }

    string r[] = {"dog", "cat", "mouse", "fish"};

    // rang-based for loop that prints out an array of strings
    for (string i : r)
    {
        cout << i + " ";
    }

    cout << endl;

    string greeting = "hello";

    // range-based for loop that prints out a string
    // the first parameter is what type you want to print out, the second is what you are iterating over
    for (char c : greeting)
    {
        cout << c << endl;
    }

    // special type of for loop that accesses the string's index and prints that character
    string h = "hello";

    for (int i = 0; char c = h[i]; i++)
    {
        cout << c << " ";
    }

    return 0;
}