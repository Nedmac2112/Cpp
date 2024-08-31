// Camden K., 9/21/23, cckirkpatrick@dmacc.edu
// Program that calculates the users discount, depending on the number of units bought

// setting up the program
#include <iostream>
using namespace std;

// start of program
int main()
{
    // declare variables and initialize constant
    int units;
    int totalCost;
    const int softPrice = 99;

    // user inputs units purchased
    cout << "Please enter the number of units purchased : ";
    cin >> units;

    // used to calculate price before discount
    const int priceBeforeDiscount = softPrice * units;

    // makes sure the users input is valid
    if ((units < 0))
    {
        cout << "Please enter a number greater than zero";
    }

    // if the users input was valid, one else-if statement will run
    else if ((units >= 10) && (units <= 19))
    {
        // calculates the total cost based on the price before discount and the amount discounted
        totalCost = (priceBeforeDiscount) - (priceBeforeDiscount * 0.20); // 20% dicount
        cout << "Total Cost : "
             << "$" << totalCost;
    }
    else if ((units >= 20) && (units <= 49))
    {
        totalCost = (priceBeforeDiscount) - (priceBeforeDiscount * 0.30); // 30% discount
        cout << "Total Cost : "
             << "$" << totalCost;
    }
    else if ((units >= 50) && (units <= 99))
    {
        totalCost = (priceBeforeDiscount) - (priceBeforeDiscount * 0.40); // 40% discount
        cout << "Total Cost : "
             << "$" << totalCost;
    }
    else if (units >= 100)
    {
        totalCost = (priceBeforeDiscount) - (priceBeforeDiscount * 0.50); // 50% discount
        cout << "Total Cost : "
             << "$" << totalCost;
    }
    // runs if the users input for units was > 0 && <= 9
    else
    {
        totalCost = (priceBeforeDiscount);
        cout << "Total Cost : "
             << "$" << totalCost;
    }

    return 0;
}

/* Tests:
 input (50) - (expected: 2970 , received:  2970
input (0) - expected: 0, received: 0
 input (-7) - expected: Please enter a number greater than zero, received:
Please enter a number greater than zero
*/