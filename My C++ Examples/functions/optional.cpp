#include <iostream>
#include <optional>
using namespace std;

void myFunction(optional<int> opt)
{
    if (opt == nullopt)
    {
        cout << "No value\n";
    }

    else
    {
        cout << "Value: " << *opt << "\n";
    }
}

optional<int> getValue(int x)
{
    if (x % 2 == 0)
    {
        return x * 2;
    }
    else
    {
        return nullopt; // Indicates absence of a value
    }
}
int main()
{
    optional<int> opt1;
    myFunction(opt1);

    optional<int> opt2 = 10;
    myFunction(opt2);

    /*


    */

    optional<int> result = getValue(5);

    if (result.has_value())
    {
        cout << "Value: " << result.value() << endl;
    }
    else
    {
        cout << "No value returned" << endl;
    }

    return 0;
}