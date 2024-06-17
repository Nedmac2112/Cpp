// Purpose: Show how to use static members and methods in a class
// Description: Static members are shared between all objects of the class.
// Static methods can only access static members and can be called without an object.
// Last modified: 05/09/2024

#include <iostream>
using namespace std;

class Integer
{
private:
    int value;
    // Static members are shared between all objects of the class
    static int sharedValue;

public:
    Integer(int v) { value = v; }

    void setValue(int v)
    {
        value = v;
    }

    int getValue()
    {
        return value;
    }

    int getSharedValue()
    {
        return sharedValue;
    }

    void incrementShared()
    {
        sharedValue++;
    }

    // Static methods can only access static members
    // They can be called without an object
    static int retrieveShared()
    {
        return sharedValue;
    }

    static void updateShared(int i)
    {
        sharedValue = i;
    }
};

// Static members must be defined outside the class
int Integer::sharedValue = 0;

int main()
{
    Integer i1(24), i2(15);

    // i1 and i2 have share the same static member
    cout << i1.getSharedValue() << ", " << i2.getSharedValue() << endl;
    i1.incrementShared();
    cout << i1.getSharedValue() << ", " << i2.getSharedValue() << endl;

    // Static methods called without an object
    Integer::updateShared(10);
    cout << Integer::retrieveShared();

    return 0;
}
