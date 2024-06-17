// cpp file that implements the functions and variables
#include <iostream>
using namespace std;

int x = 24;

void safeCracker (int safeID)
{
    if (safeID == 624)
    {
        cout << "The combination is 17-53-24";
    }

    else
    {
        cout << "Safe combination unknown";
    }
    
}