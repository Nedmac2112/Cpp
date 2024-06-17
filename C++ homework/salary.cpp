// Camden K., cckirkpatrick@dmacc.edu, 9/14/2023
// Salary calculator

// setting up the program
#include <iostream>
using namespace std;
#include <cmath>
#include <iomanip>

int main()
{
    double hourlyWage;
    /* changed workHoursPerWeek and weeklySalary to double, so that the hourly wage would give a decimal value.
    C.K. 9/14 */
    double workHoursPerWeek;
    double weeklySalary;
    int annualSalary;
    // created a constant to keep track of weeks per year. C.K. 9/14
    const int weeksPerYear = 52;

    cout << "How much do you earn per week?" << endl;
    cin >> weeklySalary;

    cout << "How many hours do you work per week?" << endl;
    cin >> workHoursPerWeek;

    hourlyWage = weeklySalary / workHoursPerWeek;
    cout << "Hourly wage is: ";
    // made it so that hourlyWage displays a decimal value to 2 places. C.K. 9/14
    cout << fixed << setprecision(2) << hourlyWage << endl;
    // removed the magic number "52" and replaced it with the variable "weeksPerYear". C.K. 9/14
    annualSalary = weeklySalary * weeksPerYear;
    cout << "Annual salary is: ";
    cout << annualSalary << endl;

    return 0;
}

/* Tests
expected Hourly wage 10.00, Salary 5200, recieved Hourly wage 10, Salary 5200
expected Hourly wage 20.00, Salary 31200, recieved Hourly wage 20.00, Salary 31200
expected Hourly wage 33.33, Salary 72800, recieved Hourly wage 33.33, Salary 72800
 */