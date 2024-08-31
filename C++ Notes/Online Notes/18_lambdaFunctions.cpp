#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

    // this lambda function is stored in a variable, so it can be called later
    auto lambdaTest = []() -> void
    {
        cout << "Lambda function with no parameters, is stored (can be called using the var name) " << endl;
    };
    // calling the lambda function
    lambdaTest();
    /*

    */
    // this lambda function is called immediately after its declaration
    // it is not stored in a variable, so it can't be called later
    []() -> void
    {
        cout << "Lambda function with no parameters called immediately after declaration " << endl;
    }();

    /*

    */
    // lambda function with parameters, called immediately after its declaration
    cout << "Lambda function with int parameters called immediately after declaration: ";
    [](int a, int b) -> void
    {
        cout << a + b << endl;
    }(23, 87);
    /*

    */
    // this lamda function returns an integer value, and stores it in a variable
    // the lambda function is not stored in the sum, since the function is called right away
    int sum = [](int a, int b) -> int
    {
        return (a + b);
    }(46, 29);

    cout << "The lambda function's return value is stored in variable sum: " << sum;
    cout << endl;
    /*

    */
    // this lambda function is stored in the variable product, since it is not called immediately
    auto product = [](double a, double b) -> double
    {
        return a * b;
    };
    cout << "Lamba function \"product\" is stored (can be called using the var name with arguments): " << fixed << setprecision(2) << product(9.5, 5.25) << endl
         << endl;
    /*

    */
    // this lambda function has paaramters marked as auto, so the compiler will deduce the type of the parameters
    auto add = [](auto a, auto b)
    { return a + b; };

    cout << "Auto lambda function: " << add(34, 65.8) << endl;
    /*

    */
    // this lambda function has template parameters, and it forces the arguments to be the same type
    auto divide = []<typename T>(T a, T b)
    {
        return a / b;
    };

    // // you can also have multiple template parameters
    // auto divide = []<typename T, typename P>(T a, P b)
    // {
    //     return a / b;
    // };

    cout << "Lambda function with template parameters: " << divide(10.0, 2.5) << endl;

    /*




    */
    int a = 5;
    int b = 3;

    // this lambda function now has access to the outside variables a and b, through the capture list
    auto subtract = [a, b]()
    {
        return a - b;
    };

    cout << subtract() << endl;

    a = 10;
    b = 7;

    // even though a and b were modified, the subtract lambda function will still return 2, not 3
    cout << subtract() << endl;

    int c = 1;
    // you can change a lambda function to be pass by reference, by placing a '&' in the capture list
    auto lambdaRef = [&c]()
    {
        return c;
    };
    cout << lambdaRef() << endl;

    c = 8;
    // the return value is updated to 8
    cout << lambdaRef() << endl;
    /*




    */
    // this gives the lambda function access to all outside variables (pass by value)
    auto accessAllVal = [=]()
    {
        cout << "Access all by value: " << a << " " << b << " " << c << endl
             << endl;
    };
    accessAllVal();

    // this gives the lambda function access to all outside variables (pass by reference)
    auto accessAllRef = [&]()
    {
        // the lambda function modifies the value of c
        cout << "Access all by reference: " << a << " " << b << " " << c++ << endl;
    };
    a = 12;
    accessAllRef();
    // c was modified in the lambda function
    cout << "c: " << c;
    return 0;
}