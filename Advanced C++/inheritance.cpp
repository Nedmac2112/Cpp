// Camden K., 9/9/24, cckirkpatrick@dmacc.edu
// Program that demonstrates inheritance in C++, by using a Shape class and three classes that inherit from it: Rectangle, Triangle, and Box

#include <iostream>
#include <string>
using namespace std;

class Shape
{
private:
    string lineColor;
    string fillColor;

public:
    Shape(string lineColor, string fillColor) : lineColor(lineColor), fillColor(fillColor) {}
    void setLineColor(string lineColor) { this->lineColor = lineColor; }
    void setFillColor(string fillColor) { this->fillColor = fillColor; }
    string getLineColor() { return lineColor; }
    string getFillColor() { return fillColor; }
};

class Rectangle : public Shape
{
private:
    double width, height;

public:
    Rectangle(double width, double height, string lineColor, string fillColor) : Shape(lineColor, fillColor), width(width), height(height) {}
    double getArea()
    {
        return (width * height);
    }
};

// Triangle class inherits from Shape class
class Triangle : public Shape
{
private:
    double base, height;

public:
    // Constructor for Triangle class, inherits from Shape class
    Triangle(double base, double height, string lineColor, string fillColor) : Shape(lineColor, fillColor), base(base), height(height) {}
    // Area of a triangle
    double getArea()
    {
        return (0.5 * base * height);
    }
};

// Box class inherits from Shape class
class Box : public Shape
{
private:
    double width, height, depth;

public:
    // Constructor for Box class, inherits from Shape class
    Box(double width, double height, double depth, string lineColor, string fillColor) : Shape(lineColor, fillColor), width(width), height(height), depth(depth) {}

    // Area of a box
    double getArea()
    {
        return (6 * width * width);
    }
};

int main()
{
    Rectangle exampleShape(10, 5, "green", "transparent");

    exampleShape.setLineColor("black");
    cout << "Fill area " << exampleShape.getArea() << " with color "
         << exampleShape.getFillColor() << endl;

    // Create an instance of the Triangle class
    Triangle exampleShape2(4, 10, "green", "transparent");

    // Use the method of the base class to set the line color, then output the area and fill color
    exampleShape2.setLineColor("green");
    cout << "Fill area " << exampleShape2.getArea() << " with color "
         << exampleShape2.getFillColor() << endl;

    // Create an instance of the Box class
    Box exampleShape3(10, 10, 10, "green", "transparent");

    // Use the method of the base class to set the line color, then output the area and fill color
    exampleShape3.setLineColor("red");
    cout << "Fill area " << exampleShape3.getArea() << " with color "
         << exampleShape3.getFillColor() << endl;

    return 0;
}

/*
Tests:

Test 1: Triangle with base = 4 and height = 10
Expected output: Fill area 20 with color transparent
Actual output: Fill area 20 with color transparent

Test 2: Box with width = 10, height = 10, and depth = 10
Expected output: Fill area 600 with color transparent
Actual output: Fill area 600 with color transparent

*/