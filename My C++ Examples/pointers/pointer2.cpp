// pointer math and double pointer
#include <iostream>
using namespace std;

int main()
{
    int a = 6;
    int *p;
    p = &a;

    string b = "";
    string *c;
    c = &b;

    cout << "Size of integer in bytes: " << sizeof(int) << endl;
    cout << "Address of int a: " << p << endl;
    cout << "Value of int a: " << *p << endl;

    // an integer takes up 4 bytes, so p+1 is the next available space in memory
    cout << "Address of int a: " << p + 1 << endl;
    // the value at that address is a garbage value
    cout << "Value of int a: " << (*p + 1) << endl;

    int x = 17;

    int *p0;
    p0 = &x;
    // this is a double pointer that points to a pointer
    int **p1;
    p1 = &p0;
    // this is the memory location of pointer p0
    cout << p1;

    return 0;
}