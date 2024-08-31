#include <iostream>
#include <iomanip> // For std::setw
using namespace std;

int main()
{
    // Define the width of each field
    const int fieldWidth = 2;

    for (int row = 0; row < 13; row++)
    {
        for (int col = 0; col < 10; col++)
        {
            // Print formatted row and column indices
            cout << "[" << setw(fieldWidth) << row << ", " << setw(fieldWidth) << col << "] ";
        }
        cout << endl;
    }

    return 0;
}
