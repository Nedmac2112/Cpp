#include <iostream>
using namespace std;

// Generic function to swap two values
// Templates are used to create generic functions, that can work with any data type
template <typename T>
void swapVal(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x = 5, y = 10;
    cout << "Before swap: " << x << " - " << y << endl;
    swapVal<int>(x, y);
    cout << "After swap: " << x << " - " << y << endl;

    double m = 3.14, n = 6.28;
    cout << "Before swap: " << m << " - " << n << endl;
    swapVal<double>(m, n);
    cout << "After swap: " << m << " - " << n << endl;
    return 0;
}