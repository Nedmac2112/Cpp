#include <iostream>
using namespace std;

// Function declarations/prototypes
void greet();
void greet(string name);
int luckyNumber();
int max(int a, int b);
void addOne(int *x);
void printNumPtr(const int *const num);
void printNumRef(const int &num);
double sum(double arr[], size_t size);
double sumRef(double (&arr)[5]);
double multiDimSum(double arr[][3], size_t numRows);
double multiDimSumRef(double (&arr)[2][3]);
void defParam(int a = 4, int b = 5);

// constexpr functions must be fully defined before the main function
// these functions are evaluated at compile time
// if the function can't be evaluated at compile time, it will be evaluated at runtime
constexpr int getValue(int x) { return x * 10; }

int main()
{
    // Void function with no parameters
    greet();
    // Void function with a string parameter
    greet("Camden");
    cout << endl;

    // Function with no parameters and an int return type
    cout << "Your lucky number is: " << luckyNumber() << endl
         << endl;

    // Function with two int parameters and an int return type (returns the bigger number)
    int a = 10, b = 20;
    cout << "a = " << a << ", b = " << b << endl;
    if (max(a, b) == 0)
        cout << "a and b are equal" << endl;
    else
        cout << "The bigger number is: " << max(a, b) << endl
             << endl;

    int num = 5;
    // Functions with a pointer parameter
    printNumPtr(&num);
    addOne(&num);
    printNumPtr(&num);
    cout << endl;

    int age = 19;
    // Function with a reference parameter
    printNumRef(age);
    cout << endl;

    // Array as parameter
    double numbers[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t numbersSize = size(numbers);
    cout << "Sum of the numbers: " << sum(numbers, numbersSize) << endl;

    // Array reference as parameter
    cout << "Sum of the numbers: " << sumRef(numbers) << endl;

    // Multi-dimensional array as parameter
    double matrix[2][3] = {{1.1, 2.2, 3.3}, {4.4, 5.5, 6.6}};
    size_t numRows = size(matrix);
    cout << "Sum of the matrix: " << multiDimSumRef(matrix) << endl
         << endl;

    // Function with default parameters
    defParam();
    cout << endl;

    // constexpr function
    // The value of x is calculated at compile time
    constexpr int x = getValue(5);
    cout << "x = " << x << endl;

    // consteval function
    // The value of y is calculated at compile time
    consteval int y = getValue2(5);
    cout << "y = " << y << endl;

    return 0;
}

// Function definitions
void greet()
{
    cout << "Hello, World!" << endl;
}

void greet(string name)
{
    cout << "Hello, " << name << "!" << endl;
}

int luckyNumber()
{
    return 77;
}

// The parameters are marked as const because we don't want to change the values of a and b
int max(const int a, const int b)
{
    if (a > b)
        return a;
    else if (b > a)
        return b;
    else // a == b
        return 0;
}

// Pass by pointer
// The parameter is marked as a pointer because we want to change the value of num in the main function
void addOne(int *num)
{
    (*num)++;
}

// Function with a const pointer to a const int parameter
// The first const means that the value of num cannot be changed
// The second const means that the pointer itself cannot point to a different memory location
void printNumPtr(const int *const num)
{
    // *num = 10;     // This will cause an error because we are trying to change the value of num
    // num = nullptr; // This will cause an error because we are trying to change the pointer itself
    cout << "num = " << *num << endl;
}

// Pass by reference
// You can make the value of num constant by adding const before the data type, but you can't make the reference itself constant
void printNumRef(const int &num)
{
    // num = 10; // This will cause an error because we are trying to change the value of num
    cout << "num = " << num << endl;
}

// Array as parameter
// The size must be passed, because when arrays are passed to functions, they decay into pointers
double sum(double arr[], size_t size)
{
    double sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

// Array reference as parameter
double sumRef(double (&arr)[5])
{
    double sum = 0;
    for (double d : arr)
    {
        sum += d;
    }
    return sum;
}

// Multi-dimensional array as parameter
// The number of rows must be passed, because when multi-dimensional arrays are passed to functions, they decay into pointers
// This function can accept arrays with any number of rows, but the number of columns must be 3
double multiDimSum(double arr[][3], size_t numRows)
{
    double sum = 0;
    for (size_t i = 0; i < numRows; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            sum += arr[i][j];
        }
    }
    return sum;
}

// Multi-dimensional array reference as parameter
// Both the number of rows and columns must be passed
// This function can only accept 2x3 arrays
double multiDimSumRef(double (&arr)[2][3])
{
    double sum = 0;

    // Range-based for loop to iterate through rows
    for (const auto &row : arr)
    {
        // Range-based for loop to iterate through elements in each row
        for (const auto &element : row)
        {
            sum += element;
        }
    }
    return sum;
}

// Function with default parameters, specified in the function declaration/prototype
// If the function is called without arguments, the default values will be used
// The function definition can't specify default values, if you have a function declaration/prototype
void defParam(int a, int b)
{
    cout << "a = " << a << ", b = " << b << endl;
}
