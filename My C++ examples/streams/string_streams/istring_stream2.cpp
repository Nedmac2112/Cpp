#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    // Input string
    string str = "1a 2b 3c";

    // Object class of istringstream
    istringstream my_stream(str);

    // Variable to store the number n
    // and character c
    int n;
    char c;

    // Traverse till input stream is valid
    while (my_stream >> n >> c)
    {

        cout << "That stream was successful: "
             << n << c << "\n";
    }
    cout << "The stream has failed."
         << "\n";

    return 0;
}