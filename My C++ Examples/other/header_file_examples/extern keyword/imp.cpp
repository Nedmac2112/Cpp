#include <iostream>
#include "extern.h"

int sharedVariable = 42;  // Definition of the global variable

void printSharedVariable() {
    std::cout << "Shared Variable: " << sharedVariable << std::endl;
}