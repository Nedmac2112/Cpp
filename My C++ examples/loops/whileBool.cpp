#include <iostream>
using namespace std;

int main()
{
    int i = 0;
    bool done = false;
    // uses a boolean variable to stop the loop
    while (!done)
    {
        cout << i << endl;
        i++;

        if (i > 5)
        {
            done = true;
        }
    }

    cout << "FINISHED";
    return 0;
}