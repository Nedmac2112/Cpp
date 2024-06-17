

#include <iostream>
#include <vector>
using namespace std;

double getArrTotal(double prices[], int size)
{
    double total = 0;
    for (int i = 0; i < size; i++)
    {
        total += prices[i];
    }

    return total;
}

int getVecTotal(vector<int> intVector)
{
    int total = 0;
    for (int i = 0; i < intVector.size(); i++)
    {
        total += intVector[i];
    }

    return total;
}
int main()
{
    double total;
    double prices[] = {24.87, 12.93, 8.51, 7.06};
    int size = sizeof(prices) / sizeof(prices[0]);
    vector<int> intVector = {23, 8, 31, 12, 9};

    total = getArrTotal(prices, size);
    cout << "Array Total: " << total << endl;

    total = getVecTotal(intVector);
    cout << "Vector Total: " << total;
    return 0;
}