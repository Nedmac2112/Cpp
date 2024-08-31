#include <iostream>
using namespace std;

int main()
{
    // If statements
    int age = -8;
    int num = 7;

    if (age > 0)
    {
        cout << "Age is valid!" << endl;
    }

    if (!(age > 0))
    {
        cout << "Age is invalid!" << endl;
    }

    age = 26;
    if (age >= 20 && age <= 29)
    {
        cout << "You are in your twenties" << endl;
    }

    if (num > 0 || num % 2 == 0)
    {
        cout << "The number is either positive or even" << endl;
    }

    // This is an if statement with an initialization of a variable
    // The variable can also be accessed in the else block
    if (int doubled = num * 2; doubled > 15)
    {
        cout << "The doubled value is greater than 15." << endl;
    }
    else
    {
        cout << "Doubled value: " << doubled << endl;
        cout << "The doubled value is not greater than 15." << endl;
    }

    // Else if statements
    age = 16;
    if (age >= 18)
    {
        cout << "You are an adult";
    }

    else if (age < 18)
    {
        cout << "You are a child";
    }

    cout << endl;

    // Else statements
    int temperatureF = 77;

    if (temperatureF < 50)
    {
        cout << "It's cold" << endl;
    }
    else if (temperatureF >= 50 && temperatureF < 77)
    {
        cout << "It's moderate" << endl;
    }
    else
    {
        cout << "It's hot." << endl;
    }

    // Switch statements
    int day = 4;

    switch (day)
    {
    case 1:
    {
        cout << "Monday" << endl;
        break;
    }
    case 2:
    {
        cout << "Tuesday" << endl;
        break;
    }
    case 3:
    {
        cout << "Wednesday" << endl;
        break;
    }
    case 4:
    {
        cout << "Thursday" << endl;
        break;
    }
    case 5:
    {
        cout << "Friday" << endl;
        break;
    }
    default:
    {
        cout << "Weekend" << endl;
    }
    }

    // Ternary operator
    int a = 10;
    int b = 4;
    int max;
    max = (a > b) ? a : b;
    cout << "Maximum value: " << max << endl;
    /*

    */

    // While loop
    int x = 0;
    int y = 20;

    while (x < 10)
    {
        cout << x << " ";
        x++;
    }
    cout << endl;
    /*

    */
    // Do while loop
    do
    {
        cout << y << " ";
        y++;

    } while (y < 10);
    cout << endl;
    /*

    */
    // For loop
    for (int i = 1; i <= 10; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 10; i > 0; i--)
    {
        cout << i << " ";
    }
    // You can have mutliple counters in a for loop, but only one condition
    for (int i = 0, x = 0; i < 10; i += 2, x++)
    {
        cout << i << " " << x << endl;
    }
    // Range based for loop (see 8_arrays.cpp to understand arrays)
    int arr[] = {1, 2, 3, 4, 5};
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    // For loop with initial variable declaration (Only works in C++20 and above)
    // for (int multiplier = 5; auto i : arr)
    // {
    //     cout << i * multiplier << " ";
    // }
    // cout << endl;
    /*

    */
    // Comma operator
    int num1 = 12;
    int num2 = 15;
    int result = (num1 *= 2, num2 = num1 + 10); // result will store the value of the last expression (num2 = num1 + 10)
    cout << result << endl;
    /*

    */
    // Nested loops with rows and columns
    for (int rows = 1; rows <= 4; rows++)
    {
        for (int columns = 1; columns <= 5; columns++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    /*

    */
    // Break and continue statements
    for (int i = 1; i <= 10; i++)
    {
        if (i == 5)
        {
            continue; // skips the current iteration, then continues with the next iteration
        }
        cout << i << " ";
    }
    cout << endl;
    for (int i = 1; i <= 10; i++)
    {
        if (i == 5)
        {
            break; // breaks out of the loop entirely
        }
        cout << i << " ";
    }

    return 0;
}
