// uses the header file to get information about the program
#include <iostream>
#include "safe.h"
using namespace std;

extern int x;
int main()
{
    safeCracker(570);
    cout << endl;
    safeCracker(624);
    cout << endl;

    cout << x;
    return 0;
}

// run the command: "g++ -o safeMain.exe safeMain.cpp safe.cpp" in order to link the files properly
// then type "main" to run the program