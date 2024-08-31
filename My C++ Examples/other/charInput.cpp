#include <iostream>
#include <conio.h> // For _getch()
using namespace std;

int main()
{
    char ch;

    // Using _getch, which does not require Enter to be pressed
    cout << "Press any key using _getch: ";
    ch = _getch();
    cout << "\nYou pressed: " << ch << endl;

    // Using cin.get(ch), which requires Enter to be pressed
    cout << "Press any key using cin.get: ";
    cin.get(ch);
    cout << "You pressed: " << ch << endl;

    return 0;
}