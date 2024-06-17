// Camden K, 9/20/23, cckirkpatrick@dmacc.edu
// This is a Program that calculates the users weekly salary with conditions

// setting up the program
#include <iostream>
// using iomanip in order for setprecision to work
#include <iomanip>
using namespace std;

int main()
{
  // constant variables initialized
  const int MAX_HOURS_IN_WEEK = 168;
  const int MAX_WAGE = 100;
  const int LOWER_SALARY = 200;
  const int UPPER_SALARY = 800;
  // integer variables declared or initialized
  double hourlyWage; // changed from int to double for dollars and cents
  int workHoursPerWeek;
  int weeklySalary;
  int valid = 1;

  // user inputs how many hours they work per week, and the program detects if it is invalid
  cout << "How many hours do you work per week?" << endl;
  cin >> workHoursPerWeek;
  // must change the && to ||, since if either of these are true, then the input is invalid.
  if (workHoursPerWeek < 0 || workHoursPerWeek > MAX_HOURS_IN_WEEK)
  {
    cout << "Invalid number of hours per week." << endl;
    valid = 0;
  }

  // detects the users input if the workHoursPerWeek variable was valid
  if (valid == 1)
  {
    cout << "What is your hourly wage?" << endl;
    cin >> hourlyWage;

    // allows the hourlyWage to show cents, and prohibits showing more than 2 decimal places
    cout << "Your hourly wage is : " << fixed << showpoint << setprecision(2) << hourlyWage << endl;

    // makes sure the users input is valid
    if (hourlyWage > MAX_WAGE)
    {
      cout << "An hourly wage greater than 100 requires executive approval." << endl;
      valid = 0;
    }
    // makes sure the users input is valid
    else if (hourlyWage < 0)
    {
      cout << "Invalid hourly wage." << endl;
      valid = 0;
    }
  }
  // code runs if the users input for hourlyWage was valid
  if (valid == 1)
  {
    // calculates weeklySalary
    weeklySalary = hourlyWage * workHoursPerWeek;
    // outputs one of three ranges depending on the users inputs
    if (weeklySalary < LOWER_SALARY)
    {
      cout << "The weekly salary is less than 200." << endl;
    }
    // changed from an if to an else-if, since no number can be < 200 and between 200 and 800
    else if (weeklySalary <= UPPER_SALARY)
    {
      cout << "The weekly salary is between 200 and 800." << endl;
    }
    else
    {
      cout << "The weekly salary is greater than 800." << endl;
    }
  }

  return 0;
}

/*Tests
  expected: "The weekly salary is less than 200.", received: "The weekly salary is less than 200."
  expected: "Invalid number of hours per week.", received: "Invalid number of hours per week."
  expected: "The weekly salary is greater than 800.", received: "The weekly salary is greater than 800."
*/
