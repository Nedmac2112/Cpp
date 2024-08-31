#include <iostream>
using namespace std;

int main()
{
    // the loop stops if i is 5
    for (int i = 0; i <= 10; i++)
    {
        if (i == 5)
        {
            break;
        }

        cout << i * 2 << endl;
    }

    cout << "FINISHED" << endl;

    cout << endl;

    // the loop continues to the next iteration if i is 5
    for (int i = 0; i <= 10; i++)
    {
        if (i == 5)
        {
            cout << endl;
            continue;
        }

        cout << i * 2 << endl;
    }

    cout << "FINISHED ";
    return 0;
}