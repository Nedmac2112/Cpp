#include <iostream>
using namespace std;

int main()
{
    int original = 10;
    int &ref = original; // ref is a reference to original

    // Display addresses
    cout << "Address of original: " << &original << endl;
    cout << "Address of ref: " << &ref << endl;

    // Change the value through the reference
    ref = 5;
    cout << "Value of original after modification through ref: " << original << endl;
    cout << "Value of ref: " << ref << endl;

    cout << endl;

    // Using const with references
    int anotherOriginal = 10;
    const int &constRef = anotherOriginal; // constRef is a reference to anotherOriginal

    // Uncommenting the next line will cause a compilation error
    // constRef = 5; // Error: cannot modify anotherOriginal through constRef

    cout << "Value of anotherOriginal: " << anotherOriginal << endl;
    cout << "Value of constRef: " << constRef << endl;
    cout << endl;

    // Using a range-based for loop with a reference
    int arr[] = {1, 2, 3, 4, 5};
    for (int &x : arr)
    {
        x *= 2;
    }
    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}