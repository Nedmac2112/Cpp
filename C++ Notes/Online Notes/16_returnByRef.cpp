#include <iostream>
using namespace std;

int &maxReturnRef(int &a, int &b)
{
    if (a > b)
        return a;
    else
        return b;
}

int *maxReturnPtr(int *x, int *y)
{
    if (*x > *y)
        return x;
    else
        return y;
}

int main()
{
    int a = 12;
    int b = 18;

    cout << "Before function call: " << endl;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    int &maxRef = maxReturnRef(a, b);
    cout << "maxRef: " << maxRef << endl;

    maxRef++; // This will change the value of a or b, since maxRef is a reference to a or b

    cout << "After function call: " << endl;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl
         << endl;

    // You can do the same thing with pointers
    int x = 20;
    int y = 6;

    cout << "Before function call: " << endl;
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;

    int *maxPtr = maxReturnPtr(&x, &y);
    cout << "maxPtr: " << *maxPtr << endl;

    (*maxPtr)++; // This will change the value of x or y, since maxPtr is a pointer to x or y

    cout << "After function call: " << endl;
    cout << "x: " << x << endl;
    cout << "y: " << y << endl
         << endl;
    return 0;
}