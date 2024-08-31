#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{

    stringstream ss1;
    ss1 << 100;           // 100 is placed in the string stream
    string s = ss1.str(); // s now contains the string "100"

    cout << s + "#" << endl; // now you can concatenate with string "100"

    stringstream ss2("12345");
    int num;
    ss2 >> num; // num now contains 12345

    cout << num + 1 << endl; // now you can do math operations

    int x = 19;
    string a;
    stringstream ss3;

    ss3 << x; // x is placed in the string stream
    ss3 >> a; // a now has the value 19
    cout << "Age: " + a << endl;

    return 0;
}
