// Purpose: Demonstrate the use of enums in C++
// Last modified: 9/7/2024

#include <iostream>
using namespace std;

// Enums are used to define a set of named constants, that hold integral values.
// By default, the first name in the list is assigned the value 0, and the value of each successive name is increased by 1.
// The value of the names can be explicitly set to any integral value.
// You can can change the default type of an enum from int to any other integral type, by specifying the type after the enum name.
// You can allow multiple names to have the same value.
enum class Months : unsigned char // This enum can hold values from 0 to 255
{
    Jan = 1,
    Feb,
    February = 2,
    Mar,
    March = Mar,
    Apr,
    May,
    Jun = 100,
    Jul,
    Aug,
    Sep,
    Oct,
    Nov,
    Dec,
};

// Old way of defining enums
enum Days
{
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};
int main()
{
    Months month1 = Months::Jan;
    Months month7 = Months::Jul;
    cout << static_cast<int>(month1) << endl;
    cout << static_cast<int>(month7) << endl;

    cout << static_cast<int>(Months::Feb) << endl;
    // using enum Months; // allows you to access the enum values directly, works in C++ 20 and above
    // cout << static_cast<int>(Feb) << endl;

    int humpDay = Days::Wednesday;
    // Old enums automatically convert to int
    cout << humpDay << endl;
    return 0;
}