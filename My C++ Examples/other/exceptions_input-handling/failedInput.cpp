#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int num;

    cout << "Enter an integer: ";
    cin >> num;

    while (cin.fail())
    {
        cout << "Invalid input! Please enter an integer: ";

        cin.clear();

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cin >> num;
    }

    cout << "You entered: " << num << endl;

    return 0;
}
