#include <iostream>
using namespace std;

int main()
{
    int x = 10, y = 4;
    cout << x << " % " << y << " = " << x % y << endl; // the remainder of 10/4 is 2
    cout << y << " % " << x << " = " << y % x << endl; // the remainder of 4/10 is 4
    cout << x << " % " << x << " = " << x % x << endl
         << endl; // the remainder of 10/10 is 0

    for (int i = 0; i < 10; i++)
    {
        cout << i % 10 << " "; // this will print numbers in the range of 0 to 9
                               // because the remainder of any number divided by 10 is always atleast one less than 10
    }
    cout << endl
         << endl;

    int arr[] = {1, 2, 3, 4, 5};
    int arrSize = 5;
    for (int i = 0; i < (arrSize * 2); i++)
    {
        if (i == 5)
        {
            cout << endl;
        }
        cout << arr[i % arrSize] << " "; // the modulus operator can be useful when you want to loop through an array more than once
                                         // this is beecause when i reaches the size of the array, the remainder of i divided by the size of the array will be 0
                                         // so the loop will start from the beginning of the array again
    }
    cout << endl
         << endl;

    int minutes = 712;
    int hours = minutes / 60;
    int remainingMinutes = minutes % 60;
    // You can use the modulus operator to convert minutes to hours and minutes
    cout << minutes << " minutes is equal to " << hours << " hours and " << remainingMinutes << " minutes" << endl;

    
    return 0;
}