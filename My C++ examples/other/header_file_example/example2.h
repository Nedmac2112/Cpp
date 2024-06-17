// You can skip using an implementation file and define the functions in the header file itself. This is useful for small projects or when you want to keep everything in one place. However, this can lead to longer compilation times and potential code duplication if the header file is included in multiple source files. It's generally recommended to use separate implementation files for larger projects.

#ifndef EXAMPLE2_H
#define EXAMPLE2_H
#include <iostream>
using namespace std;

class MyClass
{
public:
    void myMethod();
};

void MyClass::myMethod()
{
    cout << "This is myMethod" << endl;
}

void myFunction()
{
    cout << "This is myFunction" << endl;
}

int myVariable = 20;    

#endif