#include <iostream>
using namespace std;

int main()
{
    // using a while loop like a for loop
    int i = 0;     // initialize i
    while (i < 10) // loop condition
    {
        cout << i << " ";
        i++; // increment i
    }

    bool isRunning = true;
    int num = 0;
    // using a while loop with a sentinel value
    while (isRunning)
    {
        cout << "Enter a number (-999 to quit): ";
        cin >> num;

        // if -999 is entered, set isRunning to false
        if (num == -999)
        {
            isRunning = false;
        }

        // if -999 was entered, this will run before the loop ends
        cout << num * num << endl;
    }

    // infinite while loop with a break statement
    while (true)
    {
        cout << "Enter a number (-999 to quit): ";
        cin >> num;

        // if -999 is entered, break out of the loop immediately
        if (num == -999)
        {
            break;
        }

        // this will not run if -999 was entered
        cout << num * num << endl;
    }

    return 0;
}