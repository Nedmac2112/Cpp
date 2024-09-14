#include <iostream>
using namespace std;

const double PI = 3.14159;

class Cylinder
{   
    // only accessible within the class
    private:
        // member variables 
        double radius;
        double height;

    // accessible outside the class
    public:
        // default constructor, sets up the cylinder with a radius of 1 and a height of 1
        Cylinder()
        {
            radius = 1;
            height = 1;
        }

        // parameterized constructor, allows us to set the radius and height of the cylinder
        Cylinder(double r, double h)
        {
            radius = r;
            height = h;
        }

        // member function to calculate the volume of the cylinder
        double volume()
        {
            return PI * radius * radius * height;
        }

        void setRadius(double r)
        {
            radius = r;
        }

        void setHeight(double h)
        {
            height = h;
        }

        double getRadius()
        {
            return radius;
        }

        double getHeight()
        {
            return height;
        }
};

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