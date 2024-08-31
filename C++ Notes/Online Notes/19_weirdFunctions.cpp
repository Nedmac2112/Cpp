#include <iostream>
using namespace std;

// global variables are also considered static (last the whole life-time of the program)
int globalVar = 0;

// this function keeps track of how many times it has been called, using a static variable
int functionCalls()
{
    // this variable will only be initialized once, even if the function is called multiple times
    // only accessible in the function, unlike global variables
    static int numCalls = 0;
    numCalls++;
    return numCalls;
}

// inline funtions remove the function overhead, of passing arguments to the function
// instead, the function is essentially placed in the line where the function is called
// this decreases the time for the function to execute, but increases the size of the executable
// this is useful if you have short functions that are called often
// the compiler may choose not to make a function inline, even if you specify, since it may be inefficient
inline void max(int &a, int &b)
{
    if (a != b)
    {
        cout << ((a > b) ? a : b);
    }
    else
    {
        cout << "a and b are equal";
    }
}

// this is a recursive function (a function that calls itself)
// Ex. sumToZero(3)
// iteration 1: 3 + sumToZero(2)
// iteration 2: 3 + 2 + sumToZero(1)
// iteration 3: 3 + 2 + 1 + sumToZero(0)
// iteration 4: num != 0 fails, so 0 is returned
// add up the results 3 + 2 + 1 + 0 = 6 is returned from the function
int sumToZero(int num)
{
    if (num != 0)
        return num + sumToZero(num - 1);
    return 0;
}

int main()
{
    for (int i = 0; i < 3; i++)
    {
        cout << "Function called " << functionCalls() << " times" << endl
             << endl;
    }
    /*



    */
    int a = 27;
    int b = 27;
    cout << "The max value is: ";
    max(a, b);
    cout << endl;
    /*



    */
    cout << sumToZero(4);

    return 0;
}