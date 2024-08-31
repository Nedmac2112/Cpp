#include <iostream>
#include "compare.h"
using namespace std;

int main()
{
    int maximum = max(10, 20);
    cout << "The maximum number is: " << maximum << endl;
    return 0;
}

// run the command: g++ main.cpp compare.cpp -o main