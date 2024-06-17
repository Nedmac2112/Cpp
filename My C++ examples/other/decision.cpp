#include <iostream>

using namespace std;

int main()
{
    int first = 20;
    int second = 20;
    string result;

    // if (first == second)
    // {
    //     result = "equal";
    // }

    // else
    // {
    //     result = "not equal";
    // }

    // this is a simpler way to write the code above
    // the ? is called the ternary operator
    // the syntax is: (condition) ? (if true) : (if false)
    result = (first == second) ? "equal" : "not equal";
    cout << result;
    cout << endl;
    // this statement prints 1 if the condition is true and 0 if the condition is false
    cout << (first == second) ? "equal" : "not equal";

    return 0;
}