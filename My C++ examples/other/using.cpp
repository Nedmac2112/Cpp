#include <iostream>
using namespace std;

// allows you to use a keyword, instead of writing the type of the variable
// typedef string text;

// It's usually better to use the keyword "using", instead of typedef
// first you type the keyword, then set it equal to the variable type that you want
using text = string;

int main()
{
    text firstName = "Camden";
    cout << firstName << endl;
    return 0;
}