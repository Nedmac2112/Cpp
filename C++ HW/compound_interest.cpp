// Camden K., 10/4/23, cckirkpatrick@dmacc.edu

// Setting up the program
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
    // Declare variables.
    double principal, rate, t;
    double totalAmount;

    // Get the user's principal
    do
    {
        cout << "Enter principal: ";
        cin >> principal;
    } while (principal <= 0);
    // Get the user's interest rate
    do
    {
        cout << "Enter interest rate (as percent): ";
        cin >> rate;
    } while (rate <= 0 || rate >= 100);
    // Get the number of times the interest is compounded
    do
    {
        cout << "Enter number of times compounded: ";
        cin >> t;
    } while (t <= 0);

    // Calculate the total amount in savings.
    rate /= 100;
    totalAmount = principal * pow(1 + rate / t, t * (t / 12.0));

    // Print the output.
    cout << "Interest Rate: " << rate * 100 << "%" << endl;
    cout << "Times Compounded: " << t << endl;
    cout << "Principal: $ " << principal << endl;
    cout << "Amount in Savings: $ " << fixed << setprecision(2) << showpoint << totalAmount << endl;
    ;

    return 0;
}

/* Tests:
1. Input: P=100, r=5%, t=1   Expected: 100.41, Received: 100.41
2. Input P=0   Exprected: "Enter principal:", Received: "Enter principal:"
*/
