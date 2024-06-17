#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    while (cin.fail())
    { // Clear error state
        cin.clear();
        // Discard invalid input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number: ";
        cin >> num;
    }

    cout << "You entered: " << num << endl;

    return 0;
}