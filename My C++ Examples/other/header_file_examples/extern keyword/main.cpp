#include <iostream>
#include "extern.h"

int main() {
    printSharedVariable();  // Uses the shared variable defined in file1.cpp
    sharedVariable = 100;
    printSharedVariable();
    return 0;
}