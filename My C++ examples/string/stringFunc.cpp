#include <iostream>
using namespace std;

int main()
{
    string str = "0123456789";
    string str1 = "Camden lives in Texas";
    int index;
    string name;

    // // inserts the string "test" at index 0 in string "str"
    str.insert(0, "test");
    cout << str << endl;

    // erases change that was previously made. Starts at index 0, and erases 4 characters
    str.erase(0, 4);
    cout << str << endl;

    // replaces the numbers 1 and 2 in the string str. Starts at index 1, and replaces 2 characters with "test"
    str.replace(1, 2, "test");
    cout << str;

    index = str1.find("Texas");
    cout << index << endl;

    str1.replace(index, 5, "Dallas, Texas");
    cout << str1 << endl;

    cout << "What is your name? : ";
    getline(cin, name);

    if (name.length() > 12)
    {
        cout << "Your name can't be longer than 12 characters";
    }
    else
    {
        cout << "Hello " << name << endl;
    }

    cout << "What is your name? : ";
    getline(cin, name);

    if (name.empty())
    {
        cout << "You didn't enter your name";
    }
    else
    {
        cout << "Hello " << name << endl;
    }

    // // clears the contents of the name string
    name.clear();

    cout << "What is your name? : ";
    getline(cin, name);

    // // adds on to the end of a string
    name.append("@gmail.com");

    cout << "Your email is: " << name << endl;

    // outputs the first character of your name
    cout << "What is your name? : ";
    getline(cin, name);

    cout << name.at(0);
    return 0;
}