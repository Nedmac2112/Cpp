#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    // Declare and initialize an array
    string names[3] = {"Camden", "Kelton", "Bryce"};

    // Output array data
    cout << "The second name in the array is: " << names[1] << endl;

    // Find the size of an array at runtime
    cout << "The size of the array is: " << size(names) << endl;

    // Find the size of the array in bytes
    cout << "The size of the array in bytes is: " << sizeof(names) << endl;

    // Character array
    char message[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    // To store a string in a char array
    char anotherMessage[6] = "Hello";

    // Print out the character array
    cout << "Message: " << message << endl;
    cout << "Another message: " << anotherMessage << endl;

    // Using getline() for a character array
    char name[20];
    cout << "Enter your name: ";
    cin.getline(name, 10);
    cout << "Your name is: " << name << endl;

    // Seed the random number generator
    srand(time(0));

    // Generate a random number between 1 and 10
    int randomNum = (rand() % 10) + 1;
    cout << "Random number between 1 and 10: " << randomNum << endl;

    // Multi-dimensional array
    int numArr[3][3] =
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};

    // Print the multi-dimensional array
    cout << "2D array content:" << endl;
    for (int i = 0; i < 3; ++i)
    { // rows
        for (int j = 0; j < 3; ++j)
        { // columns
            cout << numArr[i][j] << " ";
        }
    }

    return 0;
}
