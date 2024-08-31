// Purpose: Shows how to create a default constructor and a parameterized constructor in a class.
// Description: The SampleClass class has two constructors. The first one is a default constructor that initializes the field1 and field2 with 100 and 200. The second constructor is a parameterized constructor that accepts two integer parameters and initializes the field1 and field2 with the values of the parameters. The Print method prints the values of field1 and field2.
// Last modified: 5/5/2024

#include <iostream>
using namespace std;

class SampleClass
{
public:
    // Default constructor
    SampleClass();
    // Parameterized constructor
    SampleClass(int, int);
    void Print() const;

private:
    int field1;
    int field2;
};

// Deafault Constuctor: sets the default values of field1 and field2 to 100 and 200
SampleClass::SampleClass() : field1(100), field2(200)
{
    cout << "Constructor #1 called" << endl;
}

// Constructor that accepts two integer parameters, and initializes field1 and field2 with the values of the parameters
SampleClass::SampleClass(int num1, int num2)
{
    field1 = num1;
    field2 = num2;
    cout << "Constructor #2 called" << endl;
}

// Does the same as the above constructor, but is written in a different way
// SampleClass::SampleClass(int num1, int num2) : field1(num1), field2(num2)
// {
// cout << "Constructor called" << endl;
// }

void SampleClass::Print() const
{
    cout << "Field1: " << field1 << endl;
    cout << "Field2: " << field2 << endl;
}

int main()
{
    // Uses the default constructor
    SampleClass obj1;
    obj1.Print();
    cout << '\n';
    // Uses the parameterized constructor
    SampleClass obj2(10, 20);
    obj2.Print();
    return 0;
}