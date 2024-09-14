// this is the header file for the cylinder class
// it contains the class definition and the function prototypes
// this is helpful, because it allows people to see what the class looks like without having to look at the implementation

#ifndef CYLINDER_H
#define CYLINDER_H

#include "constants.h"

class Cylinder
{
private:
    double radius;
    double height;

public:
    // Default constructor
    Cylinder();

    // Parameterized constructor
    Cylinder(double r, double h);

    // Function to calculate volume
    double volume();

    // Setters
    void setRadius(double r);
    void setHeight(double h);

    // Getters
    double getRadius();
    double getHeight();
};

#endif // CYLINDER_H
