#include <iostream>
using namespace std;

// Macro definition
// Macros are preprocessor directives that are used to define constants.
// They are used to make the code more readable and easier to maintain.

#define PI 3.14159
#define E 2.71828
#define NAME "Camden"
// Macros can also be used to define functions.
#define LOG(x) cout << x << endl
#define greater(a, b) (a > b ? a : b)
// You can also use #ifdef, #ifndef, #endif, and #else to check if a macro is defined.
// This is useful for enabling or disabling certain parts of the code based on the macro definition.
#define DEBUG

int main()
{
    LOG("Hello World!");
    LOG(PI + E);
    LOG(NAME);
    LOG(greater(5, 10));

#ifdef DEBUG
    cout << "Debugging is enabled!" << endl;
#else
    cout << "Debugging is disabled!" << endl;
#endif

    // There are also some predefined macros in C++ that can be used to get information about the code.
    cout << "This is file: " << __FILE__ << endl;
    cout << "This is line: " << __LINE__ << endl;
    cout << "This is date: " << __DATE__ << endl;
    cout << "This is time: " << __TIME__ << endl;
    return 0;
}