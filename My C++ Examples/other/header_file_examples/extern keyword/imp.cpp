#include <iostream>
using namespace std;
#include "extern.h"

int sharedVariable = 42; // Definition of the global variable

// Function definition
void printSharedVariable()
{
    cout << "Shared Variable: " << sharedVariable << endl;
}