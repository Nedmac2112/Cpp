#include <iostream>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

double max(double a, double b)
{
    return (a > b) ? a : b;
}

int main()
{
    int ia = 38;
    int ib = 9;
    cout << "Max function: " << max(ia, ib) << endl;

    double da = 38.4;
    double db = 9.5;
    cout << "Overloaded max function: " << max(da, db);
    return 0;
}