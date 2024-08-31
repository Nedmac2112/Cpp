#include <iostream>
using namespace std;

void adjust(int &input)
{
    int adjustment = 1;
    input += adjustment;
}

int sum(int a, int b)
{
    int result = a + b;
    adjust(result);
    return result;
}

int main()
{
    int x = 5;
    int y = 7;
    int summation = sum(x, y);
    cout << summation << endl;
    return 0;
}