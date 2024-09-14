#include <iostream>
// #include "constants.h" // this isn't needed, since cylinder.h includes it, but it shows how header guards work
#include "cylinder.h" // if you do this, you will have to compile the main.cpp and cylinder.cpp files together (g++ main.cpp cylinder.cpp -o main)
// #include "cylinder.cpp" // you can also include the implementation file, so you only have to compile the main.cpp file (g++ main.cpp -o main)
// however, this is not recommended, because it can lead to errors if you include the same file in multiple places

using namespace std;

int main()
{    
    Cylinder c1; // this uses the default constructor
    cout << "Volume of cylinder1 (default constructor): " << c1.volume() << endl << endl;

    Cylinder c2(2, 3); // this uses the parameterized constructor
    cout << "Volume of cylinder2 (parameterized constructor): " << c2.volume() << endl << endl;

    Cylinder c3(3, 4);
    cout << "Volume of cylinder3 (parameterized constructor): " << c3.volume() << endl;
    c3.setRadius(4);
    c3.setHeight(5);
    cout << "Volume of cylinder3 (after setting radius and height): " << c3.volume() << endl << endl;

    return 0;
}