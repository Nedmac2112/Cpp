#include "example2.h"
#include <iostream>
using namespace std;

int main()
{
    extern int myVariable;

    myFunction();

    MyClass obj;
    obj.myMethod();

    cout << myVariable << endl;
    return 0;
}