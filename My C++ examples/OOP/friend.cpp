// Purpose: To demonstrate the use of friend functions and friend classes in C++
// Description: This program creates a class called EqualateralTriangle with private members side, area, and perimeter. It then creates a friend function and a friend class that can access the private members of the class. The friend function and friend class are then used to access the private members of the class and print them to the console.
// Last modified: 05-15-2024

#include <iostream>
using namespace std;

class EqualateralTriangle
{
private:
    int side;
    float area;
    float perimeter;

public:
    EqualateralTriangle(int s)
    {
        side = s;
        area = (1.732 / 4) * s * s;
        perimeter = 3 * s;
    }

    // // This tells the compiler that the friendFunction function is a friend of the class
    // friend void friendFunction(EqualateralTriangle &t);

    // This tells the compiler that the FriendClass class is a friend of the class
    friend class FriendClass;
};

// // This function is a friend of the class and can access its private members
// void friendFunction(EqualateralTriangle &t)
// {
//     cout << "Area: " << t.area << endl;
//     cout << "Perimeter: " << t.perimeter << endl;
// }

// This class is a friend of the class and can access its private members
class FriendClass
{
public:
    void friendFunction(EqualateralTriangle &t)
    {
        cout << "Area: " << t.area << endl;
        cout << "Perimeter: " << t.perimeter << endl;
    }
};

int main()
{
    EqualateralTriangle t(5);
    // friendFunction(t);
    FriendClass fc;
    fc.friendFunction(t);

    return 0;
}