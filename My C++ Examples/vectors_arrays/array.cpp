#include <iostream>
#include <string>

using namespace std;

int main()
{
    int numArray[5];
    for (int i = 0; i < 5; i++)
    {
        numArray[i] = i;
    }

    for (int i = 0; i < size(numArray); i++)
    {
        cout << numArray[i] << endl;
    }

    string famousDrummers[5] = {"Neil Peart", "John Bonham", "Keith Moon", "Buddy Rich"};

    for (const string &drummer : famousDrummers)
    {
        cout << drummer << endl;
    }

    //  This will print the memory address of the array, since an array is a pointer to the first element
    cout << famousDrummers;

    // You can also use a pointer to an array, but you have to use the dereference operator
    // There is really no reason to do this, but it is possible
    char vowels[] = {'a', 'e', 'i', 'o', 'u', '\0'};
    cout << *(vowels + 1) << endl;
    return 0;
}