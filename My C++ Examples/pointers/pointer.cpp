// Camden K. 10/15/2023

#include <iostream>
using namespace std;

// pass by value function
void valueFunction(int a)
{
    a = 12;
    cout << "a is " << a << endl;
}

// pass by reference function
void referenceFunction(int &b)
{
    b = 5;
    cout << "b is " << b << endl;
}

int main()
{
    int x = 10;
    int y = 17;
    int z = 3;

    // pass by value function
    valueFunction(x);
    cout << "x is " << x << endl;

    // pass by reference function
    referenceFunction(y);
    cout << "y is " << y << endl;

    // pointer that points to the memory location of variable z in line 22
    // answer is a hexadecimal value
    cout << &z << endl;

    // a variable of type pointer (*) holds the memory location of a variable
    int *pointer1 = &z;
    cout << pointer1 << endl;

    // in order to get the value of the address that the pointer points to, you must de-reference it
    cout << *pointer1 << endl;

    // used to change the value at the memory location that the pointer refers to
    *pointer1 = 4;
    // int z changes from 3 to 4
    cout << *pointer1 << endl;

    return 0;
}