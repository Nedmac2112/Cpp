// Purpose: Demonstrate inheritance in C++ using a Food class and a Pizza class that inherits from Food class
// Decription: This program demonstrates inheritance in C++ using a Food class and a Pizza class that inherits from the Food class.
// The Food class has private data members name and calories, and public member functions to set and get the values of the private data members.
// The Pizza class inherits from the Food class and has additional private data members diameter, slices, and meat, and public member functions to set and get the values of the private data members.
// The program creates objects of the Food and Pizza classes using both default and parameterized constructors and prints the values of the private data members to the console.
// Last modified: 5/7/2024

#include <iostream>
using namespace std;

class Food
{
private:
    string name;
    int calories;

public:
    Food() : name("None"), calories(-1) { cout << "Default constructor\n"; };
    Food(string n, int c) : name(n), calories(c) { cout << "Parameterized constructor\n"; };

    string getName() const
    {
        return name;
    }

    int getCalories() const
    {
        return calories;
    }

    void setName(string n)
    {
        name = n;
    }

    void setCalories(int c)
    {
        calories = c;
    }

    void print()
    {
        cout << name << " has " << calories << " calories\n";
    }
};

class Pizza : public Food
{
private:
    int diameter;
    int slices;
    string meat;

public:
    Pizza() : Food(), diameter(-1), slices(-1), meat("None"){};
    Pizza(string n, int c, int d, int s, string m) : Food(n, c), diameter(d), slices(s), meat(m){};

    int getDiameter() const
    {
        return diameter;
    }

    int getSlices() const
    {
        return slices;
    }

    string getMeat() const
    {
        return meat;
    }

    void setDiameter(int d)
    {
        diameter = d;
    }

    void setSlices(int s)
    {
        slices = s;
    }

    void setMeat(string m)
    {
        meat = m;
    }

    void print()
    {
        cout << getName() << " pizza has " << getCalories() << " calories\n";
        cout << "Diameter: " << diameter << " inches\n";
        cout << "Slices: " << slices << "\n";
        cout << "Meat: " << meat << "\n";
    }
};

int main()
{
    cout << "Objects using default constructors\n\n";
    Food f1;
    f1.setName("Banana");
    f1.setCalories(105);
    f1.print();
    cout << "\n";
    Pizza p1;
    p1.setName("Cheese");
    p1.setCalories(250);
    p1.setDiameter(10);
    p1.setSlices(6);
    p1.setMeat("None");
    p1.print();
    /*

    */
    cout << "\n\nObjects using parameterized constructors\n\n";

    Food f2("Apple", 95);
    f2.print();
    cout << "\n";
    Pizza p2("Pepperoni", 300, 12, 8, "Pepperoni");
    p2.print();

    return 0;
}