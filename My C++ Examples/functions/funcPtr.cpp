// Purpose: Demonstrate the use of function pointers in C++.
// Description: Function pointers are pointers that point to functions. They are useful when you want to pass functions as arguments to other functions or when you want to store functions in a data structure. This program demonstrates how to define function pointers, initialize them with functions, and use them to perform different arithmetic operations.
// Last modified: 05/15/2024

#include <iostream>

// Function pointer type declaration
using ArithmeticFunction = int (*)(int, int);

// Function definitions
int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

// Function that takes a function pointer as an argument
// This is useful when you have multiple functions that do similar things
int calculate(int a, int b, ArithmeticFunction funcPtr)
{
    return funcPtr(a, b);
}

int main()
{
    int x = 10, y = 5;

    // Define function pointers and initialize them with corresponding functions
    ArithmeticFunction funcPtrAdd = add;
    ArithmeticFunction funcPtrSubtract = subtract;
    ArithmeticFunction funcPtrMultiply = multiply;

    // This is the normal way to define function pointers
    // int (*funcPtrAdd)(int, int) = add;
    // int (*funcPtrSubtract)(int, int) = subtract;
    // int (*funcPtrMultiply)(int, int) = multiply;

    // Use function pointers to perform different arithmetic operations
    std::cout << "Addition: " << calculate(x, y, funcPtrAdd) << std::endl;
    std::cout << "Subtraction: " << calculate(x, y, funcPtrSubtract) << std::endl;
    std::cout << "Multiplication: " << calculate(x, y, funcPtrMultiply) << std::endl;

    // You can also call the function directly using the function pointer
    std::cout << funcPtrAdd(30, 40);

    return 0;
}
