// Camden K., 12/5/23, cckirkpatrick@dmacc.edu
// Program that dynamically creates and deletes an array of integers

#include <iostream>
using namespace std;

int main()
{
    // variable declarations
    int length;
    int num;

    // asks the user for the size of the array
    cout << "How many integers do you want to add to the list? ";
    cin >> length;

    // dynamically allocates memory for the array
    int *intArr = new int[length];

    // asks the user to enetr the values for the array
    for (int i = 0; i < length; i++)
    {
        cout << "Enter the value for item " << i + 1 << " in the list: ";
        cin >> num;
        intArr[i] = num;
    }

    // prints the values in the array
    for (int i = 0; i < length; i++)
    {
        cout << "Item " << i + 1 << ": " << intArr[i] << endl;
    }

    // dynamically deallocates the memory of the array
    delete[] intArr;

    return 0;
}

/*
Tests:
Input: 90, 34
Expected: Item 1: 90 (newline) Item 2: 34
Received: Item 1: 90 (newline) Item 2: 34

Input: -23, 0
Expected: Item 1: -23 (newline) Item 2: 0
Received: Item 1: -23 (newline) Item 2: 0
*/