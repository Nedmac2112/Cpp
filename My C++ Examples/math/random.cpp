#include <iostream>
#include <random> // For random_device
using namespace std;

const int NUMBER_OF_ITEMS = 100;
const int MIN = 10;
const int MAX = 20;

int main()
{

    int items[NUMBER_OF_ITEMS];
    // This is a pseudo-random number generator
    int t = time(0);
    srand(t);

    cout << "Seed: " << t << endl;

    for (int i = 0; i < NUMBER_OF_ITEMS; i++)
    {
        // this will generate a random number between MIN and MAX (inclusive)
        // Ex. rand() = 23479, 23479 % (20 - 10 + 1) + 10, 23479 % 11 -> generates a number between 0 and 10, add 10 to get a number between 10 and 20
        items[i] = rand() % (MAX - MIN + 1) + MIN;
    }

    for (int i = 0; i < NUMBER_OF_ITEMS; i++)
    {
        cout << items[i] << endl;
    }
    cout << endl;

    // // This is a true random number generator
    random_device rd;
    cout << "Random device: " << rd() << endl;

    // Generate 10 random numbers between 1 and 10
    for (int i = 0; i < 20; i++)
    {
        cout << rd() % (MAX - MIN + 1) + MIN << endl;
    }

    return 0;
}