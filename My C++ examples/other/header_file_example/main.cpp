#include "example.h"
#include <iostream>
using namespace std;

int main()
{
    myFunction();
    MyClass obj;
    obj.myMethod();
    cout << "External variable: " << myVariable << endl;
    cout << "Object variable: " << obj.x << endl;
    return 0;
}
