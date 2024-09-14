// this is the implementation of our Cylinder class methods

#include "cylinder.h" // need to include the header file that contains the class definition

// Default constructor
Cylinder::Cylinder() : radius(1), height(1) {}

// Parameterized constructor
Cylinder::Cylinder(double r, double h) : radius(r), height(h) {}

// Member function to calculate the volume
double Cylinder::volume()
{
    return PI * radius * radius * height;
}

// Setters
void Cylinder::setRadius(double r)
{
    radius = r;
}

void Cylinder::setHeight(double h)
{
    height = h;
}

// Getters
double Cylinder::getRadius()
{
    return radius;
}

double Cylinder::getHeight()
{
    return height;
}
