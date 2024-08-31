#include <iostream>
using namespace std;

// this template allows the compiler to deduce what argument type will be recieved, and what type of value should be returned
// this saves code, by removing the need to write functions with overloaded parameters
template <typename T>
T maximum(const T &a, const T &b, bool &isEqual)
{
    if (a == b)
    {
        isEqual = true;
    }
    return (a > b) ? a : b;
}

// // this function has multiple typename parameters, which allows for different variable types to be sent to the function
// // a return type is also specified as a typename parameter
// template <typename ReturnType, typename T, typename P>
// ReturnType maximum2(T a, P b)
// {
//     return (a > b) ? static_cast<ReturnType>(a) : static_cast<ReturnType>(b);
// }

// this is an easier way to write the function above
// the auto keyword will decide what type to return (whatever type has a bigger size)
template <typename T, typename P>
auto maximum2(T a, P b)
{
    return (a > b) ? a : b;
}

// // this will not work, because the compiler can't deduse what type the function will return
// template <typename T, typename P>
// auto maximum2(T a, P b);

// if a trailing return type is used, than you can have a function declaration and definiton
// the auto keyword is just a placeholder, since the real return type uses decltype
template <typename T, typename P>
auto multiply(T a, P b) -> decltype(a * b);

// auto function template
// this is a simplified function template
auto mamimum3(auto a, auto b)
{
    return (a > b) ? a : b;
}

// this function checks for the argument type of the function at compile time, and throws an error if the argument is not an integral type
template <typename T>
void printNumber(T n)
{
    static_assert(is_integral_v<T>, "print_number() can only be called with integral types");
    cout << "integer: " << n << endl;
}

/*



*/

void func_floating_point(double d)
{
    cout << "func_floating_point called..." << endl;
}
void func_integral(int i)
{
    cout << "func_integral called..." << endl;
}

// this function uses "if constexpr" to check the type of the argument at compile time
// if the argument is an integral type, then func_integral is called
// if the argument is a floating point type, then func_floating_point is called
// if the argument is neither, then a static_assert is thrown
template <typename T>
void func(T t)
{
    if constexpr (is_integral_v<T>)
        func_integral(t);
    else if constexpr (is_floating_point_v<T>)
        func_floating_point(t);
    else
        static_assert(is_integral_v<T> || is_floating_point_v<T>,
                      "Argument must be integral or floating point");
}


int main()
{
    int a = 93, b = 56;
    bool isEqual = false;
    cout << "Maximum number: " << maximum(a, b, isEqual) << " (a == b: " << boolalpha << isEqual << ")" << endl;
    isEqual = false;

    double c = 23.7, d = 72.8;
    cout << "Maximum number: " << maximum(c, d, isEqual) << " (c == d: " << boolalpha << isEqual << ")" << endl;
    isEqual = false;

    string e = "Taco", f = "cat";
    cout << "Maximum string: " << maximum(e, f, isEqual) << " (e == f: " << boolalpha << isEqual << ")" << endl
         << endl;
    isEqual = false;

    // // this line will not work, because a and c are of different types, and the compiler doesnt know which type to use
    // cout << "Maximum number: " << maximum(a, c, isEqual) << " (a == c: " << boolalpha << isEqual << ")" << endl;
    // this line will work, because we are telling the compiler to convert all arguments to double
    cout << "Maximum number: " << maximum<double>(a, c, isEqual) << " (a == c: " << boolalpha << isEqual << ")" << endl
         << endl;

    // the first argument specifies what type the function will return
    // the second and third arguments specify the type of the parameters to be recieved by the function
    // cout << "Maximum number (multiple typename parameters): " << maximum2<double, int, double>(b, d) << endl;

    // this is an easier way to do the above code
    auto num = maximum2<int, double>(b, d);
    cout << "Maximum number (multiple typename parameters): " << num << endl
         << endl;

    // decltype evaluates the return type of an expression, and assigns it to a variable
    // b is an int, and d is a double, int * double = double
    // double x = 17.5;
    decltype(b * d) x = 17.5;
    cout << "decltype(b * d): " << x << endl
         << endl;

    cout << "Size of value returned: " << sizeof((multiply<int, double>(a, c))) << endl
         << endl; // int * double = double (8 bytes)

    auto num2 = mamimum3(5, 7.5);
    cout << "Maximum number (auto function template): " << num2 << endl
         << endl;

    // auto lambda function
    auto add = [](auto a, auto b)
    { return a + b; };
    cout << "Auto lambda function: " << add(34, 65.8) << endl
         << endl;

    // this lambda function has template parameters, and it forces the arguments to be the same type
    auto divide = []<typename T>(T a, T b)
    {
        return a / b;
    };

    cout << "Lambda function with template parameters: " << divide(10.0, 2.9) << endl
         << endl;

    // function argument must be an integral type
    printNumber(30);
    cout << endl;

    //
    func(10);
    func(10.5);
    // func("hello"); // this will throw an error, because the argument is not an integral or floating point type
    cout << endl;


    return 0;
}

// function definition
template <typename T, typename P>
auto multiply(T a, P b) -> decltype(a * b)
{
    return a * b;
}