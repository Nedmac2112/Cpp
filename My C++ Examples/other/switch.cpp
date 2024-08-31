#include <iostream>
using namespace std;

int main()
{
    int dogAgeMonths;

    cout << "Enter how many months old your dog is (0-12): ";
    cin >> dogAgeMonths;

    switch (dogAgeMonths)
    {
    case 0:
    case 1:
    case 2:
        cout << "That's 0..14 human months." << endl;
        break;

    case 3:
    case 4:
    case 5:
    case 6:
        cout << "That's 1..5 human years." << endl;
        break;

    case 7:
    case 8:
        cout << "That's 5..9 human years." << endl;
        break;

    case 9:
    case 10:
    case 11:
    case 12:
        cout << "That's 9..15 human years." << endl;
        break;

    default:
        cout << "Invalid input." << endl;
        break;
    }
    return 0;
}
