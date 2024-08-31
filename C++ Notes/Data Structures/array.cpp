#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Arrays are a collection of elements of the same data type, stored in contiguous memory locations
    // There are two types of arrays: static and dynamic (vector)

    // Static Array
    // The size of the array is fixed, and you cant' add or remove elements
    int staticArray[5] = {1, 2, 3, 4, 5};
    cout << "Static Array: ";
    for (int i : staticArray)
        cout << i << " ";
    cout << endl;

    // Dynamic Array (vector)
    // The size of the array is dynamic, and you can add or remove elements
    vector<int> dynamicArray = {1, 2, 3, 4, 5};
    cout << "Dynamic Array (vector): ";
    for (int i : dynamicArray)
        cout << i << " ";
    cout << endl;

    // Operations

    // Add an element at the end of the array (time complexity: O(1))
    dynamicArray.push_back(6);
    cout << "After push_back(6): ";
    for (int i : dynamicArray)
        cout << i << " ";
    cout << endl;

    // Remove the last element of the array (time complexity: O(1))
    dynamicArray.pop_back();
    cout << "After pop_back(): ";
    for (int i : dynamicArray)
        cout << i << " ";
    cout << endl;

    // Insert an element at the beginning of the array (time complexity: O(n))
    // All elements have to be shifted to the right, hence O(n)
    dynamicArray.insert(dynamicArray.begin(), 0);
    cout << "After insert(0) at the beginning: ";
    for (int i : dynamicArray)
        cout << i << " ";
    cout << endl;

    // Erase an element at the beginning of the array (time complexity: O(n))
    // All elements have to be shifted to the left, hence O(n)
    dynamicArray.erase(dynamicArray.begin());
    cout << "After erase() at the beginning: ";
    for (int i : dynamicArray)
        cout << i << " ";
    cout << endl;
    return 0;
}