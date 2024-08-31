#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    string months[] = {"January", "February", "March", "April", "May", "June",
                       "July", "August", "September", "October", "November", "December"};
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string weekDays[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};


    int year;
    cout << "Enter a year (YYYY): ";
    cin >> year;
    if (year < 1 || year > 9999)
    {
        cout << "Invalid input!" << endl;
        return 1;
    }
    else if ((year % 4 == 0 && (year % 100 != 0)) || year % 400 == 0)
    {
        daysInMonth[1] = 29;
    }

    string inputDay;
    cout << "Enter the first day of the year (Sun, Mon, Tue, Wed, Thu, Fri, Sat): ";
    cin >> inputDay;

    int startingDay;
    if (inputDay == "Sun")
        startingDay = 0;
    else if (inputDay == "Mon")
        startingDay = 1;
    else if (inputDay == "Tue")
        startingDay = 2;
    else if (inputDay == "Wed")
        startingDay = 3;
    else if (inputDay == "Thu")
        startingDay = 4;
    else if (inputDay == "Fri")
        startingDay = 5;
    else if (inputDay == "Sat")
        startingDay = 6;
    else
    {
        cout << "Invalid input!" << endl;
        return 1;
    }

    // Print calendar
    int currentDay = startingDay;
    for (int month = 0; month < 12; month++)
    {
        string monthName = months[month];
        int monthNameLength = monthName.length();
        int totalWidth = 7 * 5; // 7 days * 5 spaces per day

        // Calculate leading spaces to center the month name
        int leadingSpaces = (totalWidth - monthNameLength) / 2;
        cout << setw(leadingSpaces + monthNameLength) << monthName << endl;

        for (const string &weekday : weekDays)
        {
            cout << setw(5) << weekday;
        }
        cout << endl;

        // Print leading spaces for the first week
        for (int i = 0; i < currentDay; i++)
        {
            cout << setw(5) << " ";
        }

        // Print the days of the month
        for (int day = 1; day <= daysInMonth[month]; day++)
        {
            cout << setw(5) << day;
            currentDay = (currentDay + 1) % 7;
            if (currentDay == 0)
            {
                cout << endl;
            }
        }
        cout << endl
             << endl;
    }

    return 0;
}
