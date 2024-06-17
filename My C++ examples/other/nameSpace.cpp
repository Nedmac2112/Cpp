#include <iostream>
using namespace std;


namespace first
{
    int x = 10;

    namespace second
    {
        int x = 20;
    }
}

int main()
{
    // if you use this, you don't need to write the namespace that you are reffering to
    // using namespace first;
    int x = 0;

    cout << x << endl;

    cout << first::x << endl;

    cout << first::second::x << endl;

    return 0;
}
