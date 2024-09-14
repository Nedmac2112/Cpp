// Camden K., 9/9/24, cckirkpatrick@dmacc.edu
// Program that demonstrates multiple inheritance in C++, by using a Fish class that inherits from two base classes: Animal and Aquatic

#include <iostream>
using namespace std;

// Base class 1
class Animal
{
public:
    void eat()
    {
        cout << "Eating..." << endl;
    }
};

// Base class 2
class Aquatic
{
public:
    void swim()
    {
        cout << "Swimming..." << endl;
    }
};

// Derived class, Fish, is inheriting from both the Animal and Aquatic classes
class Fish : public Animal, public Aquatic
{
private:
    string type;

public:
    // Constructors
    Fish() : type("Unknown") {}
    Fish(string type) : type(type) {}

    // Destructor
    ~Fish() {}

    void showType()
    {
        cout << "Type: " << type << endl;
    }
};

int main()
{
    // Creating object of Fish class
    Fish f("Shark");
    // Method from Fish class
    f.showType();
    // Method from Animal class
    f.eat();
    // Method from Aquatic class
    f.swim();

    return 0;
}

// Test: The derived class inheritings from multiple base classes is working correctly, and displaying the expected output.

/*
    Multiple inheritence combines the methods and attributes of multiple classes into a single derived class.
    This is useful when you have features in two seperate classes that you want to combine into a single class
    The derived class can access the methods and attributes of both base classes, as well as its own methods and attributes.
    This is useful for creating complex class hierarchies and relationships between classes, while maintaining code reusability, and avoiding code duplication.
*/