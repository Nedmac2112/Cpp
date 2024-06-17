#include <iostream>
using namespace std;

int totalSum(int a, int b)
{
    if (a == b)
        return a;
    else
        return a + totalSum(a + 1, b);
}

unsigned long long factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int main()
{
    int x = 1, y = 2;
    cout << "Enter the first number: ";
    cin >> x;
    cout << "Enter the second number: ";
    cin >> y;

    while (x > y)
    {
        cout << "First number must be less than the second number" << endl;
        cout << "Enter the first number: ";
        cin >> x;
        cout << "Enter the second number: ";
        cin >> y;
    }

    cout << "Sum of numbers between " << x << " and " << y << " is " << totalSum(x, y) << endl;

    int n;
    cout << "Enter a number to calculate its factorial: ";
    cin >> n;

    unsigned long long result = factorial(n);
    cout << "Factorial of " << n << " is " << result << endl;

    return 0;
}