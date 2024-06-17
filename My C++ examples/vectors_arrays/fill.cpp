// C++ program to demonstrate working of fill()
#include <iostream>
using namespace std;

int main()
{
    int arr[10];
    // calling fill to initialize values in the range to 4
    // starts at the first index, and ends at the last index
    fill(arr, arr + 10, 4);

    for (int i = 0; i < 10; i++)
        cout << i + 1 << ": " << arr[i] << endl;

    return 0;
}
