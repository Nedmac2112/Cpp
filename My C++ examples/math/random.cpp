#include <iostream>
#include <cstdlib> // For srand and rand
#include <ctime>   // For time
#include <random>  // For random_device
using namespace std;

int main()
{
    // This is a pseudo-random number generator
    int t = time(0);
    srand(t);

    cout << "Seed: " << t << endl;

    // Generate 10 random numbers between 1 and 10
    for (int i = 0; i < 10; i++)
    {
        cout << 1 + rand() % 10 << endl;
    }

    // This is a true random number generator
    random_device rd;
    cout << "Random device: " << rd() << endl;

    return 0;
}