// Purpose: To demonstrate the use of friend functions and friend classes in C++
// Description: Friend functions and friend classes can access the private members of a class.
// This is useful when you want to allow a function or class to access the private members of
// a class without making them a member of the class.
// Last modified: 9-7-2024

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

    // This tells the compiler that the friendFunction function is a friend of the class
    friend void friendFunction(EqualateralTriangle &t);

    // This tells the compiler that the FriendClass class is a friend of the class
    friend class FriendClass;
};

// This class is a friend of the class and can access its private members
class FriendClass
{
public:
    void friendMethod(EqualateralTriangle &t)
    {
        cout << "Area: " << t.area << endl;
        cout << "Perimeter: " << t.perimeter << endl;
    }
};

// This function is a friend of the class and can access its private members
void friendFunction(EqualateralTriangle &t)
{
    cout << "Area: " << t.area << endl;
    cout << "Perimeter: " << t.perimeter << endl;
}

int main()
{
    EqualateralTriangle t(5);
    // friendFunction(t);
    FriendClass fc;
    cout << "Inside FriendClass: " << endl;
    fc.friendMethod(t);

    cout << endl;

    cout << "Inside friendFunction: " << endl;
    friendFunction(t);

    return 0;
}