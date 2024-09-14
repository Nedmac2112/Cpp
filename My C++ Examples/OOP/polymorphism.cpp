// Purpose: shows how polymorphism works in C++ using virtual functions
// Description: This program defines a base class called Square and a derived class called Rectangle. The Square class has a virtual function called print() that prints out information about the square. The Rectangle class overrides the print() function to print out information about the rectangle. The main function creates objects of both classes and calls the print() function on them. It also demonstrates how polymorphism works with pointers and arrays of objects.
// Last modified on: 05/08/2024

#include <iostream>
using namespace std;

// Base class: Square
class Square
{
private:
    int x;

public:
    Square(int x) : x(x) {}

    void setX(int x)
    {
        this->x = x;
    }

    int getX() const
    {
        return x;
    }

    // This function is marked as virtual so that it can be overridden by derived classes
    virtual void print()
    {
        cout << "I am a square with side length " << x << endl;
    }
};

// Derived class: Rectangle
class Rectangle : public Square
{
private:
    int y;

public:
    Rectangle(int x, int y) : Square(x), y(y) {}

    void setY(int y)
    {
        this->y = y;
    }

    int getY() const
    {
        return y;
    }

    // This function overrides the print() function in the base class
    void print() override
    {
        cout << "I am a rectangle with side lengths " << getX() << " and " << getY() << endl;
    }
};

// This function takes a reference to a Square object and calls the print() function on it
// Polymorphism allows this function to work with both Square and Rectangle objects
void foo(Square &s)
{
    s.print();
}

// This function does the same thing as the one above, but it uses a pointer instead of a reference
// void foo(Square *s)
// {
//     s->print();
// }

int main()
{
    Square s1(5);
    Rectangle r1(4, 6);

    foo(s1);
    foo(r1);
    cout << endl;
    /*



    */
    // This creates a Square object and a Rectangle object on the heap
    Square *s2 = new Square(7);
    Square *r2 = new Rectangle(8, 10);

    // The pointers are dereferenced and passed to the foo() function
    foo(*s2);
    foo(*r2);
    cout << endl;

    // Use these lines instead of the ones above if you want to use a pointer instead of a reference
    // foo(s2);
    // foo(r2);

    delete s2;
    delete r2;
    s2 = nullptr;
    r2 = nullptr;
    /*



    */
    // This array contains pointers to Square objects allocated on the heap
    Square *squares[] = {new Square(8), new Rectangle(5, 6)};

    // Iterate through the array and call the print() function on each object and then delete it and set it to nullptr
    for (Square *s : squares)
    {
        foo(*s);
        delete s;
        s = nullptr;
    }

    return 0;
}
