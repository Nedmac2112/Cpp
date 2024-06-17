#include <iostream>
#include <stdexcept>

using namespace std;

float divideFloats(float numerator, float denominator)
{
    if (denominator == 0)
    {
        throw runtime_error("Division by zero error");
    }
    return numerator / denominator;
}

int main()
{
    float numerator, denominator;
    bool isValidInput = false;

    cout << "Enter the numerator: ";
    cin >> numerator;

    while (!isValidInput)
    {
        cout << "Enter the denominator: ";
        cin >> denominator;

        try
        {
            float result = divideFloats(numerator, denominator);
            cout << "Result of division: " << result << endl;
            isValidInput = true; // Set isValidInput to true if division is successful
        }
        catch (const runtime_error &e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}
