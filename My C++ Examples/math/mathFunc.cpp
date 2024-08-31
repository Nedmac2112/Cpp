// program that shows off different math-related functions
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int x = 21389;
    int y = 21390;
    int a;
    int b;
    int z;
    int w;
    int v;
    double u = 2.49;
    double r = 4.14;
    double s = 7.99;

    // finds the biggest of 2 numbers (don't need "cmath")
    a = max(x, y);
    cout << a << endl;

    // finds the smallest of two numbers (don't need "cmath")
    b = min(x, y);
    cout << b << endl;

    // z = 3*3 (base, exponent)
    z = pow(3, 2);
    cout << z << endl;

    // square root of 100
    w = sqrt(100);
    cout << w << endl;

    // absolute value of -56
    v = abs(-56);
    cout << v << endl;

    // rounds u down to 2
    u = round(u);
    cout << u << endl;

    // rounds r up to 5
    r = ceil(r);
    cout << r << endl;

    // rounds s down to 7
    s = floor(s);
    cout << s << endl;

    cout << "PI: " << M_PI << endl;
    cout << "e: " << M_E << endl;

    return 0;
}