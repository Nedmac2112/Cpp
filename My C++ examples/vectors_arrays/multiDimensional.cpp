#include <iostream>
using namespace std;

const int ROWS = 4;
const int COLS = 4;

int main()
{
    string calculator[ROWS][COLS] = {
        {"| 1", "2", "3", "+ |"},
        {"| 4", "5", "6", "- |"},
        {"| 7", "8", "9", "* |"},
        {"| C", "0", "=", "/ |"}};

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << calculator[i][j] << " ";
        }
        cout << endl;
    }

    // You can use as many dimensions as you want
    // but each time you add a dimension, the size of the array increases exponentially
    // The size of the array below is 10,000 elements / 4 bytes per element = 40,000 bytes
    int bigArray[10][10][10][10] = {{{{1}}}};
    cout << bigArray[0][0][0][0] << endl;

    return 0;
}