#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int size;

    cout << "Input a size for the array: ";
    cin >> size;

    // allows the user to input a new size for the array each time the program is run
    // the "new" key word dynamically allocates memory each time the program is run
    // int *numArr = new int[size];

    // it is better to use a vector instead of a dynamic array
    vector <int> numArr(size);

    for (int i = 0; i < size; i++)
    {
        cout << "Enter a value for numArr[" << i << "]: ";
        cin >> numArr[i];
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "numArr[" << i << "] / " << &numArr[i] << ": " << numArr[i] << " (" << sizeof(numArr[i]) << " bytes)" << endl;
    }

    // this unallocates the memory, preventing a memory leak
    // delete[] numArr;

    return 0;
}