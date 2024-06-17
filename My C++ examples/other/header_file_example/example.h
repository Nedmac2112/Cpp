/* 
#ifndef is used to check if EXAMPLE_H is defined or not.   
If it is not defined, then it is defined and the code inside the #ifndef block is executed.
If it is defined, then the code inside the #ifndef block is not executed.
This is used to prevent multiple definitions of the same code.
*/

#ifndef EXAMPLE_H
#define EXAMPLE_H

void myFunction();

class MyClass
{
public:
    int x = 1;
    void myMethod();
};

extern int myVariable;

#endif
