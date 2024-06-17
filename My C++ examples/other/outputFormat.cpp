#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
     // The default precision of a double is 6, which means up to 6 significant digits are used to represent the number
     double a = 1234.567; // then setprecision(6) is applied to x
     // only prints the first 6 sig figs, and drops the 7. The 6 is rounded up to 7.
     cout << a << "\n";
     // prints all 7 digits of x
     cout << setprecision(7) << a << "\n";
     // the fixed operator causes the setprecision to round to 2 decimal places, instead of 2 sig figs
     cout << fixed << setprecision(1) << a << "\n";

     // set the precision back to the default value
     cout << setprecision(6);
     // un-did the fixed point opertion
     cout.unsetf(ios::fixed);
     cout << a << "\n";

     double b = 9876.543;
     // you can also use setprecision and fixed this way
     cout << fixed << setprecision(2);
     cout << b << "\n";
     cout << 23.784 << "\n";

     double c = 4;
     // doesn't display a decimal
     cout << c << "\n";
     // displays the remaining zeros until the field is full
     cout << showpoint << c << "\n";

     // setw sets the width of the field. It is right alligned by default.
     // 5 spaces followed by hello, 10 spaces followed by 0123456789
     cout << setw(10) << "Hello" << setw(20) << "0123456789"
          << "\n";
     // set text to be left alligned. left is applied to he entire line
     cout << left << setw(10) << "Hello" << setw(20) << "0123456789"
          << "\n";

     // Example: alligning a table
     cout << setprecision(3) << fixed;
     cout << right << setfill('#') << setw(10) << 6.8275 << setw(10) << 174.43 << endl;
     cout << setfill('%') << setw(10) << 19.37 << setw(10) << 3.96 << endl
          << endl;

     return 0;
}
