// Camden K., 10/24/23, cckirkpatrick@dmacc.edu

// libraries
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// linear search algorithm used to find specified value
int LinearSearch(int numbers[], int numbersSize, int key)
{
    int i;

    for (i = 0; i < numbersSize; ++i)
    {
        if (numbers[i] == key)
        {
            return i;
        }
    }

    // return -1 if value is not found
    return -1;
}

int main()
{
    // declarations and initializations
    int numbers[10];
    int num;
    const int NUMBERS_SIZE = 10;
    int key;
    int keyIndex;

    cout << "Please enter a list of ten numbers : " << endl;

    // user inputs 10 integers in the array
    for (int i = 0; i < 10; i++)
    {
        cin >> num;

        // input validation
        while (num < 0 || num > 1000)
        {
            cout << "Invalid, re-enter number : " << endl;
            cin >> num;
        }

        if (num >= 0 && num <= 1000)
        {
            numbers[i] = num;
        }
    }

    cout << endl;

    int n = sizeof(numbers) / sizeof(numbers[0]);

    // sorts the array from lowest to highest
    sort(numbers, numbers + n);

    // user inputs an integer to search for
    cout << "Enter a value to look for : " << endl;
    cin >> key;

    // the LinearSearch function is called and the value is stored in keyIndex
    keyIndex = LinearSearch(numbers, NUMBERS_SIZE, key);

    if (keyIndex == -1)
    {
        cout << key << " was not found." << endl;
    }
    else
    {
        cout << "Found " << key << " at index " << keyIndex << "." << endl;
    }

    return 0;
}

/*Test
Input: 7, 39, 2, 47, 13, 1, 100, 90, 87, 51. key = 47. Expected: Found 47 at index 5.
Received: Found 47 at index 5.
Input: 2000. Expected: Invalid, re-enter number : . Received: Invalid, re-enter number :.
*/