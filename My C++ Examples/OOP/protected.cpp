// Purpose: Show how protected data members work in C++ classes
// Description: This program shows how protected data members work in C++ classes. The private data members are only accessible within the base class. The protected data members are accessible from all derived classes. The program defines a base class with private and protected data members. The program defines a derived class that inherits from the base class. The program demonstrates how the protected data members are accessible from the derived class.
// Last modified: 5/7/2024

#include <iostream>
using namespace std;

class Base
{
    // Private data members are only accessible within the base class
private:
    int privateVar;

    // Protected data members are accessible from all derived classes
protected:
    int protectedVar;

public:
    Base() : privateVar(0), protectedVar(0){};

    void setPrivate(int x)
    {
        privateVar = x;
    }

    void setProtected(int x)
    {
        protectedVar = x;
    }

    int getPrivateBase() const
    {
        return privateVar;
    }

    int getProtectedBase() const
    {
        return protectedVar;
    }
};

class Derived : public Base
{
public:
    Derived() : Base(){};

    // This function will work because the protected variable is accessible from the Derived class
    int getProtectedDerived() const
    {
        return protectedVar;
    }

    // This function will not work because the private variable is not accessible from the Derived class
    // int getPrivateDerived() const
    // {
    //     return privateVar;
    // }
};

int main()
{
    Base baseObj;
    Derived derivedObj;

    baseObj.setPrivate(3);
    baseObj.setProtected(4);

    cout << "Base private: " << baseObj.getPrivateBase() << endl;
    cout << "Base protected: " << baseObj.getProtectedBase() << endl;

    cout << "\n";

    derivedObj.setPrivate(5);
    derivedObj.setProtected(6);

    cout << "Accessing the private variable through the Base class: " << derivedObj.getPrivateBase() << endl;
    // This will work because the protected variable is accessible from the Derived class
    cout << "Derived protected: " << derivedObj.getProtectedDerived() << endl;

    // This will not work because the private variable is not accessible from the Derived class
    // cout << "Accessing the private variable through the Derived class: " << derivedObj.getPrivateDerived() << endl;

    return 0;
}
