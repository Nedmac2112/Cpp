// Camden K., cckirkpatrick@dmacc.edu, 9/14/2023
// Money exchange program

// setting up the program
#include <iostream>
using namespace std;

int main()
{ // declare variables for different currencies
    double num_pesos;
    double num_euros;
    double num_yuan;
    double total_us_dollars;

    // initialize variables for currency exchange rate
    double peso_rate = 0.058;
    double euro_rate = 1.06;
    double yuan_rate = 0.14;

    /* user inputs # of pesos they have, the number of pesos are multiplied by the exchange rate
    in order to find the value in US dollars*/
    cout << "How many Pesos do you have?" << endl;
    cin >> num_pesos;
    total_us_dollars = num_pesos * peso_rate;

    /* another input for currency... the total_us_dollars variable is equal to the previous value,
    plus the number of euros * the exchange rate (This is how to keep track of the total value in US dollars)*/
    cout << "How many Euros do you have?" << endl;
    cin >> num_euros;
    total_us_dollars += num_euros * euro_rate;

    /* repeat same steps as before */
    cout << "How much Yuan do you have?" << endl;
    cin >> num_yuan;
    total_us_dollars += num_yuan * yuan_rate;

    // the program outputs the total value of the foreign currencies in US dollars.
    cout << "You have "
         << "$" << total_us_dollars;
}

/*Tests
expected $14, got $14
expected $5.8, got $5.8
expected $106, got $106
 */