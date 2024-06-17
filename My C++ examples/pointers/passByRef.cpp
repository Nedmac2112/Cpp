#include <iostream>
using namespace std;

void outputSize(int &size)
{
    cout << size << " inches" << endl;
    size = 20;
}

int main()
{
    int deskHeight = 30;
    outputSize(deskHeight);
    // deskHeight is now 20
    cout << deskHeight;
    return 0;
}