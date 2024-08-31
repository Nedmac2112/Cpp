#include <iostream>
#include <string>
using namespace std;

void PrintDate(int currDay, int currMonth, int currYear)
{
    cout << currMonth << "/" << currDay << "/" << currYear;
}

void PrintDate(int currDay, string currMonth, int currYear)
{
    cout << currMonth << " " << currDay << ", " << currYear;
}

int main()
{

    PrintDate(30, 7, 2012);
    cout << endl;

    PrintDate(30, "July", 2012);
    cout << endl;

    return 0;
}