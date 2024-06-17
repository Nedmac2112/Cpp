#include <iostream>
using namespace std;

int ComputeSquare(int numToSquare)
{
    return numToSquare * numToSquare;
}

int main()
{
    int num;

    cout << "Input a number to be squared: " << endl;
    cin >> num;

    cout << num << " squared is " << ComputeSquare(num);
    return 0;
}