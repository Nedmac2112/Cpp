#include <iostream>
#include <string>
using namespace std;

// type conversion convert one data type to another data type
// there are two types of type conversion; implicit(automatic), and explicit

int main()
{
    // implicit
    // x is converted to its ASCII value
    char c = 70;
    cout << c << endl;

    // explicit
    int correct = 8;
    int questions = 11;
    // if we didn't convert one of the integers to a double, when the integers are divided, they would round down to zero!
    double score = correct / (double)questions * 100;

    cout << "You got a " << score << "%"
         << " on the test." << endl;

    // string to int
    string num = "47";
    cout << stoi(num) + 10 << endl;
    // int to string
    int a = 365;
    cout << to_string(a) + " days in a year" << endl;

    // Best way to do it in C++: static_cast<>
    int x = 8;
    int y = 13;

    double z = static_cast<double>(x) / y;
    cout << z << endl;
    return 0;
}