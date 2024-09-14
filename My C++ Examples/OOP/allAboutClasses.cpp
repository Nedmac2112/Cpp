// A program that demonstrates all the important concepts of classes in C++

#include <iostream>
using namespace std;

// this is what a basic class looks like in C++
class Test
{

    // private members are only accessible within the class, through member functions/methods
private:
    int m_x; // "m_" is a common naming convention for private members (m stands for member)
    string y;

    // public members are accessible from outside the class, and can be accessed through objects of the class
public:
    // Default constructor, this is called when an object is created without any arguments, and sets the members to default values
    Test()
    {
        m_x = 0;
        y = "Empty";
    }
    // Test() : m_x(0), m_y("Empty") {} // this is a simpler way to initialize the members

    // Parameterized constructor, this is called when an object is created with arguments, and sets the members to the values passed
    Test(int x, string y)
    {
        m_x = x;
        this->y = y; // if the member variable and the parameter have the same name, you can use "this->" to refer to the member variable
    }
    // Test(int x, string y) : m_x(x), m_y(y) {} // this is a simpler way to initialize the members

    // Getters and setters, these are used to access and modify the private members of the class
    int getX()
    {
        return m_x;
    }

    string getY()
    {
        return y;
    }

    void setX(int x)
    {
        m_x = x;
    }

    void setY(string y)
    {
        this->y = y;
    }

    // This prints all the members of the class
    void printInfo()
    {
        cout << m_x << ", " << y << endl;
    }
};

/*







*/
// Inheritance is a way to create a new class that reuses the properties of an existing class. The new class is called a derived class,
// Base class
class Animal
{
private:
    string m_name;
    string m_habitat;
    int m_age;
    string m_size;

public:
    Animal() : m_name("Empty"), m_habitat("Empty"), m_age(0), m_size("Empty") {}
    Animal(string name, string habitat, int age, string size) : m_name(name), m_habitat(habitat), m_age(age), m_size(size) {}

    string getName()
    {
        return m_name;
    }

    string getHabitat()
    {
        return m_habitat;
    }

    int getAge()
    {
        return m_age;
    }

    string getSize()
    {
        return m_size;
    }

    void setName(string name)
    {
        m_name = name;
    }

    void setHabitat(string habitat)
    {
        m_habitat = habitat;
    }

    void setAge(int age)
    {
        m_age = age;
    }

    void setSize(string size)
    {
        m_size = size;
    }

    void printInfo()
    {
        cout << "Name: " << m_name << ", Habitat: " << m_habitat << ", Age: " << m_age << ", Size: " << m_size << endl;
    }
};

// Derived/sub class
// This class has access to all the members of the base class, and can add its own members
class Mammal : public Animal
{

    // Unique member of the Mammal class
private:
    bool m_hasFur;

public:
    // The constructor's inherit from the base class, and add their own members
    Mammal() : m_hasFur(false), Animal() {}
    Mammal(string name, string habitat, int age, string size, bool hasFur) : m_hasFur(hasFur), Animal(name, habitat, age, size) {}

    bool getHasFur()
    {
        return m_hasFur;
    }

    void setHasFur(bool hasFur)
    {
        m_hasFur = hasFur;
    }
};

/*







*/
// Polymorphism is the ability of a function to behave differently based on the object that it is called on. This is achieved through virtual functions.
// Base class
class Square
{
private:
    int m_width;

public:
    Square() : m_width(0) {}
    Square(int width) : m_width(width) {}

    int getWidth()
    {
        return m_width;
    }

    void setWidth(int width)
    {
        m_width = width;
    }

    // This function is marked as virtual so that it can be overridden by derived classes
    // This is an example of polymorphism, since the printInfo() function can be called on both Square and Rectangle objects
    virtual void printInfo()
    {
        cout << "I am a square with side length " << m_width << endl;
    }
};

// Derived class
class Rectangle : public Square
{
private:
    int m_height;

public:
    Rectangle() : m_height(0), Square() {}
    Rectangle(int width, int height) : m_height(height), Square(width) {}

    int getHeight()
    {
        return m_height;
    }

    void setHeight(int height)
    {
        m_height = height;
    }

    // This function overrides the printInfo() function in the base class
    void printInfo() override
    {
        cout << "I am a rectangle with side lengths " << getWidth() << " and " << m_height << endl;
    }
};

// This function takes a reference to a Square object and calls the printInfo() function on it
// This works, since a Rectangle object is a Square object as well
void printSquareInfo(Square &s)
{
    s.printInfo();
}

/*







*/

// Abstract classes are classes that cannot be instantiated, and are used as base classes for other classes. They contain one or more pure virtual functions.
class Shape
{
public:
    // Pure virtual functions are functions that have no implementation, and must be overridden by derived classes
    virtual void draw() = 0;
    virtual double area() = 0;
};

// Concrete class
class Circle : public Shape
{
private:
    double m_radius;

public:
    Circle(double r) : m_radius(r) {}

    double getRadius()
    {
        return m_radius;
    }

    void setRadius(double r)
    {
        m_radius = r;
    }

    // These functions must be implemented, since they are pure virtual functions in the base class
    void draw() override
    {
        cout << "Drawing a circle" << endl;
    }

    double area() override
    {
        return 3.14159 * m_radius * m_radius;
    }
};

/*







*/

class Base
{
private:
    int privateVar;

protected:
    int protectedVar;

public:
    Base() : privateVar(1), protectedVar(2) {}

    void showBase()
    {
        cout << "Base class: privateVar = " << privateVar << ", protectedVar = " << protectedVar << endl;
    }

    int getPrivateVar()
    {
        return privateVar;
    }
};

class Derived : public Base
{
public:
    Derived() : Base() {}

    void showDerived()
    {
        // Private varibales can't be directly accessed (without using a method) in the derived class
        // cout << "Derived class: privateVar = " << privateVar << endl;
        // This is how you access the private variable in the base class
        // cout << "Derived class: privateVar = " << getPrivateVar() << endl;

        // Protected variables can be accessed directly in the derived class (without using a method)
        cout << "Derived class: protectedVar = " << protectedVar << endl;
    }
};

int main()
{
    cout << "Basic class example" << endl;
    Test t1;
    t1.printInfo();

    Test t2(20, "Camden");
    t2.printInfo();
    cout << "--------------------------------" << endl
         << endl;
    /*


    */
    cout << "Inheritance example" << endl;
    cout << "Animal class (base class): ";
    Animal penguin("Penguin", "Arctic", 7, "Medium");
    penguin.printInfo();
    cout << "Mammal class (subclass of Animal): ";
    Mammal lion("Lion", "Savannah", 10, "Large", true);
    lion.printInfo();
    cout << "--------------------------------" << endl
         << endl;
    /*


    */
    cout << "Polymorphism example" << endl;
    Square s(5);
    Rectangle r(4, 6);

    printSquareInfo(s); // calls the printInfo() function in the Square class
    printSquareInfo(r); // calls the printInfo() function in the Rectangle class
    cout << "--------------------------------" << endl
         << endl;
    /*


    */
    cout << "Abstract class example" << endl;
    Circle c(5);
    c.draw();
    cout << "Area: " << c.area() << "u^2" << endl;
    cout << "--------------------------------" << endl
         << endl;
    /*


    */
    cout << "Access specifiers example" << endl;
    Base b;
    Derived d;

    b.showBase();
    d.showDerived();
    return 0;
}