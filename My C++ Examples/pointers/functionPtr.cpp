#include <iostream>
using namespace std;

// A simple function that takes two integers and returns their sum
int add(int a, int b)
{
    return a + b;
}

// A simple function that takes two integers and returns their product
int multiply(int a, int b)
{
    return a * b;
}

// A function that takes two integers and a pointer to a function that
// takes two integers and returns an integer
int compute(int x, int y, int (*operation)(int, int))
{
    return operation(x, y);
}

int main()
{
    // Declare a function pointer and initialize it with the 'add' function
    int (*operation)(int, int) = add;

    // Use the function pointer to call the 'add' function
    cout << "Sum: " << operation(5, 3) << endl; // Output: Sum: 8

    // Change the function pointer to point to the 'multiply' function
    operation = multiply;

    // Use the function pointer to call the 'multiply' function
    cout << "Product: " << operation(5, 3) << endl; // Output: Product: 15

    // Using the 'compute' function with different operations
    cout << "Compute (add): " << compute(5, 3, add) << endl;           // Output: Compute (add): 8
    cout << "Compute (multiply): " << compute(5, 3, multiply) << endl; // Output: Compute (multiply): 15

    return 0;
}
