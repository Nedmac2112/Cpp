#include <iostream>
using namespace std;

// this function calculates the sum of all numbers between a and b
int totalSum(int a, int b)
{
    // base case
    if (a == b)
        return a;
    else
        // recursive case: add the current number to the sum of the rest of the numbers
        return a + totalSum(a + 1, b);
}

// this function calculates the factorial of a number (4 factorial = 4 * 3 * 2 * 1 = 24)
unsigned long long factorial(int n)
{
    // base case
    if (n == 0)
        return 1;
    else
        // recursive case: multiply the current number by the factorial of the rest of the numbers
        return n * factorial(n - 1);
}

// this function calculates the nth fibonacci number (each number is the sum of the two preceding numbers)
// 1 1 2 3 5 8 13 21 34 55 89 144 ...
int fibonacci(int n)
{
    if (n < 3)
        return 1;
    else
        return fibonacci(n - 2) + fibonacci(n - 1);
}

int main()
{
    cout << "Total sum between two numbers" << endl;
    int x = 0, y = 0;
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

    cout << "Sum of numbers between " << x << " and " << y << " is " << totalSum(x, y) << endl
         << endl;

    int n;
    cout << "Enter a number to calculate its factorial: ";
    cin >> n;

    unsigned long long result = factorial(n);
    cout << "Factorial of " << n << " is " << result << endl
         << endl;

    int fibInput = 0;
    int fibResult = 0;
    cout << "What fibonacci number do you want to calculate? ";
    cin >> fibInput;
    fibResult = fibonacci(fibInput);
    cout << "fibonacci(" << fibInput << ") = " << fibResult << endl
         << endl;

    // this is the same as the totalSum function, but using a for loop
    int sumBetween = 0;
    for (int i = x; i <= y; i++)
    {
        sumBetween += i;
    }
    cout << "Sum (for loop): " << sumBetween << endl;

    // this is the same as the factorial function, but using a for loop
    int factorial = 1;
    for (int i = 1; i <= n; i++)
    {
        factorial *= i;
    }
    cout << "Factorial (for loop): " << factorial << endl;

    return 0;
}