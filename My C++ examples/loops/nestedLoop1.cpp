#include <iostream>
using namespace std;

int main()
{
    for (int col = 0; col < 10; col++)
    {
        for (int row = 0; row < 10; row++)
        {
            cout << "[]";
        }
        cout << endl;
    }

    return 0;
}