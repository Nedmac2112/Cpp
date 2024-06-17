// Purpose: Illustrate the use of copy constructor in C++.
// Description: This program demonstrates the use of copy constructor in C++. The program defines a class called MyClass with a default constructor, a parameterized constructor, and a copy constructor. The program creates an object using the default constructor, the parameterized constructor, and the copy constructor. The program then changes the value of the object created using the parameterized constructor and outputs the values of all three objects to the console.
// Last modified: 5/7/2024

#include <iostream>
#include <string>
using namespace std;

class MyClass
{

private:
    int data;
    string str;

public:
    // Default constructor
    MyClass()
    {
        cout << "Default Constructor called\n";
        data = 0;
        str = "none";
    }

    // Parameterized constructor
    MyClass(int value, string s)
    {
        cout << "Parameterized Constructor called\n";
        data = value;
        str = s;
    }

    // Copy constructor
    MyClass(const MyClass &other)
    {
        cout << "Copy Constructor called\n";
        data = other.data;
        str = other.str;
    }

    void setVal(int d, string s)
    {
        data = d;
        str = s;
    }

    // Member function to display data
    void displayData() const
    {
        cout << data << " " << str << "\n";
    }
};

int main()
{
    // Create an object using the default constructor
    MyClass obj1;
    cout << "Object 1: ";
    obj1.displayData();
    cout << "\n";

    // Create an object using the parameterized constructor
    MyClass obj2(42, "monkey");
    cout << "Object 2: ";
    obj2.displayData();
    cout << "\n";

    // Use the copy constructor to create a new object
    MyClass obj3 = obj2; // Equivalent to MyClass obj3(obj2);
    cout << "Object 3: ";
    obj3.displayData();
    cout << "\n";

    // Changed the value of obj2
    obj2.setVal(20, "snake");
    cout << "Object 2: ";
    obj2.displayData();
    cout << "\n";

    // The value of obj3 in unchanged
    cout << "Object 3: ";
    obj3.displayData();

    return 0;
}
