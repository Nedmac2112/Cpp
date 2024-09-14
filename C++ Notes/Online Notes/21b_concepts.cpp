#include <iostream>
#include <concepts> // this is the header file for concepts
#include <type_traits> // this is the header file for is_integral_v
using namespace std;

template <integral T> // this is a constraint, which forces the argument to be an integral type
T add(T a, T b)
{
    return a + b;
}

// custom concepts/constraints
template <typename T>
concept MyIntegral = is_integral_v<T>;

template <typename T>
concept Multipliable = requires (T a, T b)
{
    a * b; // this is a constraint, which forces the argument to be multipliable
};

template <typename T>
concept Incrementable = requires (T a)
{
    // these are the rules which the argument must follow, it must be able to do all of these operations
    a += 1;
    a++;
    ++a; 
};

// enforcing concepts/constraints
template <MyIntegral T>
T subtract(T a, T b)
{
    return a - b;
}

template <Multipliable T>
T multiply(T a, T b)
{
    return a * b;
}

template <Incrementable T>
T increment(T a)
{
    return a + 1;
}

// check for the size of the type
template <typename T>
concept TinyType = requires (T a)
{
    sizeof(a) <= 4; // this only enforces that this is a valid syntax, it does not check the value
    requires sizeof(a) <= 4; // this will check the value of the expression
};

template <TinyType T>
void func(T a)
{
    cout << "Small type: " << a << endl;
}

// combining concepts
template <typename T>
void combo(T a) requires MyIntegral<T> && TinyType<T>
{
    cout << "Combining concepts: " << a << endl;
}

int main()
{
    char a = 5, b = 7;
    int c = add(a, b);
    cout << "Sum of a and b: " << c << endl;

    double d = 10, e = 15;
    // this will throw an error, because the arguments are not integral types
    // float f = add(d, e);
    // cout << "Sum of d and e: " << f << endl;

    // custom concepts
    int x = 10, y = 5;

    int z = subtract(x, y);
    cout << "Difference of x and y: " << z << endl;

    z = multiply(x, y);
    cout << "Product of x and y: " << z << endl;

    z = increment(x);
    cout << "Increment of x: " << z << endl;

    // check for the size of the type
    func(x); // this will work, because the size of int is less or equal to than 4
    // func(d); // this will throw an error, because the size of double is greater than 4

    // combining concepts
    combo(x); // this will work, because the type is integral and the size is less than or equal to 4
    // combo(d); // this will throw an error, because the type is not integral

    return 0;
}