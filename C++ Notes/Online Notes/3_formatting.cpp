#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int num = 0x0F;        // hexadecimal number
    int num2 = 017;        // octal number
    int num3 = 0b00001111; // binary number

    // displayes the value of the hexadecimal, octal, and binary numbers in decimal
    cout << num << endl;
    cout << num2 << endl;
    cout << num3 << endl
         << endl;

    // setw(n) sets the width of the next output field to n characters
    cout << left << setw(10) << "Hello" << setw(10) << "World!" << endl;
    cout << right << setfill('=') << setw(10) << "Very" << setw(10) << "Cool" << endl // setfill() sets the fill character
         << endl;

    cout << setfill(' ');
    cout << setw(10) << -125.25 << endl;
    cout << internal << setw(10) << -125.25 << endl; // this aligns the sign to the leftmost position

    // this disables the internal flag
    cout.unsetf(ios::internal);
    cout << showpos << setw(10) << 125.25 << endl; // this forces the sign to be displayed
    cout << noshowpos << endl;                     // this disables the showpos flag

    int num4 = 53682;
    cout << showbase; // this forces the base of the number to be displayed
    cout << "Hexadecimal: " << hex << num4 << endl;
    cout << "Decimal: " << dec << num4 << endl;
    cout << "Octal: " << oct << num4 << endl;
    cout << noshowbase << endl; // this disables the showbase flag

    double floatNum = 23682.8363;

    cout << "Default: " << floatNum << endl;
    cout << "Fixed notation: " << fixed << floatNum << endl;                     // this sets the stream to fixed notation
    cout << "Scientific notation: " << scientific << floatNum << endl;           // this sets the stream to scientific notation
    cout << "Back to default: " << defaultfloat << floatNum << endl;             // this sets the stream back to default behavior
    cout << fixed << setprecision(4) << "setprecision(4): " << floatNum << endl; // this sets the number of decimal places to display
    cout << defaultfloat << setprecision(6) << "Back to default: " << floatNum << endl;

    double floatNum2 = 12.0;
    cout << showpoint << floatNum2 << endl;   // this forces the decimal point to be displayed
    cout << noshowpoint << floatNum2 << endl; // this disables the showpoint flag

    return 0;
}
