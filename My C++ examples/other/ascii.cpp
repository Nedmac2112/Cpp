#include <iostream>
using namespace std;

int main()
{
    int x = 32;
    for (char i = 32; i < 127; i++)
    {
        cout << x << ": " << i << endl;
        x++;
    }
}