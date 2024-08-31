#include <iostream>
using namespace std;

int main()
{
    int a = 6;
    double b = 7.4;
    double x = 12.5;
    double y = 8.6;

    // implicit conversion
    auto doubleSum = a + b; // a is converted to double before adding
    cout << "Double sum = " << doubleSum << endl;

    // explicit conversion
    auto intSum = static_cast<int>(x) + static_cast<int>(y); // truncates x and y to 12 and 8, then adds them
    cout << "Integer sum 1 = " << intSum << endl;
    auto intSum2 = static_cast<int>(x + y); // adds x and y, then truncates to 20
    cout << "Integer sum 2 = " << intSum2 << endl;
    return 0;
}