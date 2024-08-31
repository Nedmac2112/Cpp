// Purpose: To demonstrate the difference between pointers and references
// Description: This program demonstrates the difference between pointers and references. It shows how pointers and references can be used to access the memory address of a variable and how they can be used to change the value of a variable. It also shows how pointers and references can be used to access the memory address of a variable and how they can be used to change the value of a variable. It also shows how pointers and references can be used to access the memory address of a variable and how they can be used to change the value of a variable. It also shows how pointers and references can be used to access the memory address of a variable and how they can be used to change the value of a variable.
// Last modified: 05/10/2024

#include <iostream>
using namespace std;

int main()
{
     int x = 1, y = 2;

     // pointer to x
     int *ptr = &x;
     // reference to y (references must be initialized when declared)
     //  This does not allocate memory, it just creates an alias for y
     int &ref = y;

     // This will not change the memory address of ref, it will just assign the value of x to ref / y
     // ref = x;
     // This will change the memory address of ref to the memory address of y
     // ptr = &y;

     cout << "Address of x: " << &x << ", Address of pointer: " << ptr << endl;

     cout << "Address of y: " << &y << ", Address of reference: " << &ref << endl
          << endl;

     // When the value of x is incremented, the value of ptr is also incremented
     x++;
     // When the value of y is incremented, the value of ref is also incremented
     y++;

     cout << "Value of x: " << x << ", Value of pointer: " << *ptr << endl;

     cout << "Value of y: " << y << ", Value of reference: " << ref << endl
          << endl;

     // pointer now points to a garbage value (The -- operator decrements the pointer by 4 bytes)
     ptr++;
     cout << "Garbage value: " << *ptr << endl;

     // adds one to ref / y (This doesnt change the memory address of y, it just increments the value of y)
     ref++;
     cout << "Y value: " << y << ", Reference value: " << ref << endl;

     return 0;
}