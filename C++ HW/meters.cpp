#include <iostream>
using namespace std;

int main()
{
    int totalMeters;
    int numKilometers;
    int numHectometers;
    int numMeters;

    cin >> totalMeters;

    /* Your code goes here */
    numKilometers = totalMeters / 1000;
    totalMeters = totalMeters % 1000;

    numHectometers = totalMeters / 100;
    totalMeters = totalMeters % 100;

    numMeters = totalMeters;

    cout << "Kilometers: " << numKilometers << endl;
    cout << "Hectometers: " << numHectometers << endl;
    cout << "Meters: " << numMeters << endl;

    return 0;
}