// Purpose: Illustrate how to return a reference to a vector from a function
// Description: The modifyVector1 function receives a reference to a vector, modifies the vector, and returns the reference to the vector. The main function creates a vector, calls the modifyVector1 function, and prints the vector before and after the modification.
// Last modified: 5/5/2024

#include <iostream>
#include <vector>
using namespace std;
vector<int> &modifyVector1(vector<int> &myVector)
{
    // Modify the vector within the function
    for (int &num : myVector)
    {
        num *= 2;
    }

    return myVector;
}

// Example function: The function recieves a reference to a vector, modifies it, and returns the reference
int &multiply(int &a)
{
    a *= 2;
    return a;
}

int main()
{

    //  Use the short program below as an example for how the vectors work.

    // int x = 3;
    // // num must be a reference to an int, since we are returning a reference to an int
    // int &num = multiply(x);
    // cout << num << " " << x << endl;
    // cout << &num << " " << &x << endl;

    // End of example

    vector<int> myVector1 = {1, 2, 3, 4, 5};

    cout << "&myVector1: ";
    cout << &myVector1;
    cout << "\n";
    cout << "myVector1: ";
    for (int num : myVector1)
    {
        cout << num << " ";
    }

    cout << "\n\n";
    vector<int> &modifiedVector1 = modifyVector1(myVector1);
    cout << "&modifiedVector1: ";
    cout << &modifiedVector1;
    cout << "\n";
    cout << "modifiedVector1: ";
    for (int num : modifiedVector1)
    {
        cout << num << " ";
    }
    return 0;
}