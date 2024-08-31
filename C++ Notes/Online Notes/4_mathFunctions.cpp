#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num = 25;
    int negNum = -25;
    double doubleNum = 12.4;

    // Power functions
    cout << "Square root of " << num << " is " << sqrt(num) << endl;
    cout << "Cube root of " << num << " is " << cbrt(num) << endl;
    cout << "4^3 = " << pow(4, 3) << endl;
    cout << "log(" << num << "): " << log(num) << endl;
    cout << "log10(100): " << log10(100) << endl;
    cout << "|" << negNum << "|: " << abs(negNum) << endl;

    // Rounding functions
    cout << doubleNum << " rounded to the nearest integer is " << round(doubleNum) << endl;
    cout << "Ceil of " << doubleNum << " is " << ceil(doubleNum) << endl;
    cout << "Floor of " << doubleNum << " is " << floor(doubleNum) << endl;

    // Trigonometric functions
    cout << "sin(90): " << sin(90) << endl;
    cout << "cos(0): " << cos(0) << endl;
    cout << "tan(45): " << tan(45) << endl;

    cout << "PI: " << M_PI << endl;
    cout << "e: " << M_E << endl;
    return 0;
}