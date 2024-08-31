#include <iostream>
#include <stdexcept>
using namespace std;

// Function to check if a year is a leap year
bool isLeapYear(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                return true;
            else
                return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}

int getDaysInMonth(int year, int month)
{
    switch (month)
    {
    case 1:  // January
    case 3:  // March
    case 5:  // May
    case 7:  // July
    case 8:  // August
    case 10: // October
    case 12: // December
        return 31;
    case 4:  // April
    case 6:  // June
    case 9:  // September
    case 11: // November
        return 30;
    case 2: // February
        if (isLeapYear(year))
            return 29;
        else
            return 28;
    default:
        return -1; // Invalid month
    }
}

// Function to validate user input
bool isValidInput(int year, int month)
{
    if (year < 0)
    {

        throw runtime_error("Invalid year. Please enter a positive number.");

        return false;
    }
    if (month < 1 || month > 12)
    {

        throw runtime_error("Invalid month. Please enter a number between 1 and 12.");

        return false;
    }

    return true;
}

// Function to prompt the user for input
void getUserInput(int &year, int &month)
{

    try
    {
        cout << "Enter a year: ";
        cin >> year;
        cout << "Enter a month (1-12): ";
        cin >> month;
        isValidInput(year, month);
    }
    catch (runtime_error e)
    {
        cout << e.what();
        while (!isValidInput) // should run when isValidInput returns false
        {
            getUserInput(year, month);
        }
    }
}
int main()
{
    int month;
    int year;

    getUserInput(year, month);

    // while (!isValidInput) // should run when isValidInput returns false
    //{
    //   getUserInput(year, month);
    //}

    int days = getDaysInMonth(year, month);
    cout << "Number of days: " << days << endl;

    return 0;
}

/* Tests
Input: 2400, 2. Expected: 29. Received: 29.
Input: 2023, 10. Expected: 31. Received: 31.
*/