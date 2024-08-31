// Camden K., 11/1/23, cckirkpatrick@dmacc.edu

// libraries
#include <iostream>
#include <vector>
using namespace std;

// struct that holds the values for each month
struct Household
{
    int rent;
    double gas;
    double water;
    int garbage;
    string donation;
    double total;
};

int main()
{

    // initialized variables
    double total_rent = 0, total_gas = 0, total_water = 0, total_garbage = 0;
    const int NUM_MONTHS = 4;

    // created a vector of type Household to store the values for each month
    vector<Household> monthVector(NUM_MONTHS);

    // loop that allows the user to input data for each month
    for (int i = 0; i < 4; i++)
    {
        cout << "Enter the rent cost of month " << i + 1 << endl;
        cin >> monthVector[i].rent;

        cout << "Enter the gas cost of month " << i + 1 << endl;
        cin >> monthVector[i].gas;

        cout << "Enter the water cost of month " << i + 1 << endl;
        cin >> monthVector[i].water;

        cout << "Enter the garbage cost of month " << i + 1 << endl;
        cin >> monthVector[i].garbage;

        cout << "Enter the donation for month " << i + 1 << endl;
        cin >> monthVector[i].donation;

        // calculates the the total values
        total_rent += monthVector[i].rent;
        total_water += monthVector[i].water;
        total_garbage += monthVector[i].garbage;
        total_gas += monthVector[i].gas;
        monthVector[i].total = monthVector[i].gas + monthVector[i].water + monthVector[i].rent + monthVector[i].garbage;

        cout << endl;
    }

    // calculates the total for all 4 months
    double overallTotal = 0;

    for (int i = 0; i < 4; i++)
    {
        overallTotal += monthVector[i].total;
    }

    // declares average variables
    double av_rent, av_water, av_gas, av_garbage;

    // calculates the average of each variable;
    av_rent = total_rent / NUM_MONTHS;
    av_water = total_water / NUM_MONTHS;
    av_garbage = total_garbage / NUM_MONTHS;
    av_gas = total_gas / NUM_MONTHS;

    // outputs the total cost, and average of each cost
    cout << "The overall totoal cost was $" << overallTotal << endl; // printing
    cout << "The average rent was $" << av_rent << endl;
    cout << "The average water was $" << av_water << endl;
    cout << "The average garbage was $" << av_garbage << endl;
    cout << "The average gas was $" << av_gas << endl;
    cout << "The list of donations is as follows :" << endl;

    // outputs the donations list

    for (int i = 0; i < NUM_MONTHS; i++) // printing the donations
    {
        cout << i + 1 << ": " << monthVector[i].donation << endl;
    }

    return 0;
}
/* Test
All inputs gave their expected outputs, and the program finished with no errors
*/

// There are way too many inputs to show you all of them. (20 inputs, not including the calculations)