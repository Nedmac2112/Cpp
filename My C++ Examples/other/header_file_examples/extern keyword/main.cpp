#include <iostream>
using namespace std;
#include "extern.h"

int main()
{
    printSharedVariable(); // Uses the shared variable defined in file1.cpp
    sharedVariable = 100;
    printSharedVariable(); // This will print the updated value of the shared variable, since it is shared between the two files
    return 0;
}