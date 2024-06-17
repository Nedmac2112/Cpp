// Camden K., 9/26/23, cckirkpatrick@dmacc.edu
// Program that lets the user input a # 1-10, and tells them if they guessed correctly

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
    // Error? removed the "u" in "<uint>"
    srand(static_cast<int>(time(nullptr)));
    // older compilers: srand(static_cast<int>(time(0)));

    // declare and initialize variables
    //  generates a random # 1-10
    int secret = rand() % 10 + 1;
    int guess;

    cout << "Guess a number between 1 and 10." << endl;
    cin >> guess;

    /* Error #1: Changed from "guess < 0" to "guess < 1", because if the input was 0,
    then that would have been a valid entry.*/
    while (guess < 1 || guess > 10)
    {
        cout << "That is not a number between 1 and 10, try again." << endl;
        /*Error #2: Added another input, which allows the user to guess again,
        otherwise you could run into an infinte loop.*/
        cin >> guess;
    }

    // executes only if guess is a # 1-10, and is not = to the secret #
    while (guess != secret)

    {
        if (guess < secret)
        {
            cout << "Too low, try again." << endl;
        }
        else if (guess > secret)
        {
            cout << "Too high, try again." << endl;
        }
        /*Error #2 (continued): Added another input, which allows the user to guess again,
         otherwise you could run into an infinte loop.*/
        cin >> guess;
    }

    // executes only if guess == secret #
    cout << "Correct!" << endl;

    return 0;
}

/* Tests:
Input 0: expected: "That is not a number between 1 and 10, try again."
 received: "That is not a number between 1 and 10, try again."
Input 1: expected: "Too low, try again." or "Correct!" received: "Too low, try again."  */
