#include <iostream>
using namespace std;

// Type aliases are used to create a new name for an existing type.
using hugeInt = unsigned long long int;

// Old way of defining type aliases
// typedef unsigned long long int hugeInt;

int main()
{
    // By using type aliases, you can make your code more readable
    hugeInt num = 43'633'217'981'237'092;
    hugeInt num2 = 19'448'096'739'850'215;
    cout << num << endl;
    cout << num2 << endl;
    return 0;
}