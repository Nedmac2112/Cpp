// Camden K., 12/5/23, cckirkpatrick@dmacc.edu
// Program that calculates which price is higher, using pointers

#include <iostream>
using namespace std;

int main()
{
    float price1;
    float price2;

    // input prices from the user
    cout << "Enter id 1: ";
    cin >> price1;
    cout << "Enter id 2: ";
    cin >> price2;

    float *pricePtr;

    /* TODO: Your solution goes here.
       Update pricePtr so the output is correct.
       Do not change anything else. */

    // checks to see which price is bigger
    if (price1 > price2)
    {
        pricePtr = &price1;
    }

    else if (price2 > price1)
    {
        pricePtr = &price2;
    }

    // runs if the prices are equal
    else
    {
        pricePtr = nullptr;
    }

    // output message to the user
    if (pricePtr == nullptr)
    {
        cout << "The prices are the same." << endl;
    }
    else
    {
        cout << "The largest price is " << *pricePtr << "." << endl;
    }
}

/*
Tests:
Input: 25, 40
Expected: The largest price is 40. Received: The largest price is 40.
Input: 12, 12
Expected: The prices are the same. Received: The prices are the same.
*/