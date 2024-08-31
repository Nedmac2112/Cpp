#include <iostream>
#include <windows.h> // library for SetConsoleOutputCP
using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8); // this line is needed to display emojis and other unicode characters
    cout << "Hello, World!" << u8"\u270C" << endl;

    string utf8String = u8"Hello 😊 \U0001f44b";
    // "\u" is used for characters in the range (u0000 - uffff)
    // and "\U" is used for characters greater than "uffff"
    cout << utf8String << endl
         << endl;

    // Define the box edge characters
    string topLeft = u8"╔";
    string topRight = u8"╗";
    string bottomLeft = u8"╚";
    string bottomRight = u8"╝";
    string horizontal = u8"═";
    string vertical = u8"║";

    // Print the top edge
    cout << topLeft;
    for (int i = 0; i < 30; ++i)
    { // 16x32 box, so 30 horizontal characters
        cout << horizontal;
    }
    cout << topRight << endl;

    // Print the sides
    for (int i = 0; i < 10; ++i)
    { // 16x32 box, so 14 vertical rows
        cout << vertical;
        for (int j = 0; j < 30; ++j)
        {                 // 16x32 box, so 30 spaces in width
            cout << "*"; 
        }
        cout << vertical << endl;
    }

    // Print the bottom edge
    cout << bottomLeft;
    for (int i = 0; i < 30; ++i)
    { // 16x32 box, so 30 horizontal characters
        cout << horizontal;
    }
    cout << bottomRight << endl;
    return 0;
}
