// Linear Search in C++

#include <iostream>
using namespace std;

int search(int array[], int n, int x)
{

    // Going through array sequencially
    for (int i = 0; i < n; i++)
        if (array[i] == x)
            return i;
    return -1;
}

int main()
{
    int array[] = {2, 4, 0, 1, 9};
    int input;
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Enter a number to look for in the array: ";
    cin >> input;

    int result = search(array, size, input);

    (result == -1) ? cout << "Element not found" : cout << "Element found at index: " << result;
}