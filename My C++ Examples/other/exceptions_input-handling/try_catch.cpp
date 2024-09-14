// Program that shows the different types of exceptions that can be thrown

#include <iostream>
using namespace std;

float Division(float a, float b)
{
    // An exception is manually thrown if b is 0, since C++ does not throw an exception for division by zero
    if (b == 0)
    {
        // only one of these will be executed if there is an exception
        // throw runtime_error("Divide by zero error!");
        // throw exception();
        throw string("Exception thrown!");
        // throw 404;
        // throw 'E';
    }
    // runs if no exceptions were thrown
    return a / b;
}

int main()
{
    float x;
    float y;

    cout << "Enter a number for x and y: ";
    cin >> x >> y;

    try
    {
        cout << Division(x, y);
    }

    // will run if runtime_error is thrown
    catch (const runtime_error &e)
    {
        cerr << e.what() << endl;
    }

    // will run if it is another type of exception class
    catch (const exception &e)
    {
        cerr << e.what() << endl;
    }

    // will run if the exception thrown is a string
    catch (const string &s)
    {
        cerr << "Error message: " << s << endl;
    }

    // will run if no other catch blocks have been run
    catch (...)
    {
        cerr << "Error occurred! " << endl;
    }

    return 0;
}