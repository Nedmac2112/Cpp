// Purpose: To demonstrate the use of vectors in C++ and the various functionalities they provide
// Description: This program demonstrates the use of vectors in C++ and the various functionalities they provide. It creates a vector of integers, populates it with numbers from 1 to 10, and then demonstrates various operations such as reversing the vector, resizing the vector, inserting elements at specific positions, erasing elements from specific positions, removing the last element, and clearing all elements from the vector.
// Last modified: 05-15-2024

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> numbers;

    for (int i = 1; i <= 10; i++)
        numbers.push_back(i);

    for (int i = 0; i < numbers.size(); i++)
        cout << numbers[i] << " ";
    cout << endl;

    // This is a easier way to iterate through the vector
    // for (int n : numbers)
    // 	cout << n << endl;

    // Reverses the vector
    reverse(numbers.begin(), numbers.end());

    for (int n : numbers)
        cout << n << " ";
    cout << endl;

    // Back to normal
    reverse(numbers.begin(), numbers.end());

    // size() returns the number of elements in the vector
    cout << "Size: " << numbers.size() << endl;
    // max_size() returns the maximum number of elements that the vector can hold
    cout << "Max size: " << numbers.max_size() << endl;
    // capacity() returns the number of elements that the vector can hold without needing to allocate more memory
    cout << "Capacity: " << numbers.capacity() << endl;

    // Resizes the vector to hold 5 elements
    numbers.resize(5);
    cout << "Size after resizing: " << numbers.size() << endl;

    if (numbers.empty())
        cout << "Vector is empty" << endl;
    else
        cout << "Vector is not empty" << endl;
    cout << "Second to last element: " << numbers.at(numbers.size() - 2) << endl;
    cout << "Front: " << numbers.front() << endl;
    cout << "Back: " << numbers.back() << endl;

    // insert element at specific position in vector
    numbers.insert(numbers.begin() + 2, 10);

    for (int n : numbers)
        cout << n << " ";

    cout << endl;

    // erase element from a specific position
    // This will erase elements at index 2 and 3
    numbers.erase(numbers.begin() + 2, numbers.begin() + 4);

    for (int n : numbers)
        cout << n << " ";

    cout << endl;

    // remove last element of vector
    numbers.pop_back();

    for (int n : numbers)
        cout << n << " ";

    cout << endl;

    // clear all the elements of vector
    numbers.clear();
    cout << "Size after clear: " << numbers.size() << endl;

    return 0;
}