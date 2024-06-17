// the sizeof function returns the size of a certain data type in bytes
// the sizeof function allows you to calculate how many elements are in an array

#include <iostream>
using namespace std;

int main()
{
    string cars[] = {"Corvette", "Lamborghini", "Koenigsegg"};

    cout << "The cars array takes up " << sizeof(cars) << " bytes of memory" << endl;
    cout << "The cars array has " << sizeof(cars) / sizeof(cars[0]) << " elements";
    return 0;
}