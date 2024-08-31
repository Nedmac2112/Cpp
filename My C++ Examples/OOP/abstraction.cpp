// Purpose: To demonstrate the use of abstract classes in C++
// Description: Abstract classes are classes that have at least one pure virtual function.
// Pure virtual functions are declared with the = 0 syntax. They are used as a blueprint for derived classes,
// and must be implemented in the derived class. Abstract classes cannot be instantiated, but pointers to abstract classes can be created.
// This allows for polymorphism, where a pointer to a base class can point to a derived class object.
// This allows for the use of virtual functions, which are functions that are resolved at runtime, rather than compile time.
// This allows for the use of the most specific function for the object being pointed to, rather than the function in the base class.
// This is useful for creating a common interface for a group of classes, and allows for the use of derived classes without knowing the specific type of the derived class.
// Last modified: 05/08/2024

#include <iostream>
using namespace std;

// An abstract class is a class that has at least one pure virtual function
class Person
{
protected: 
    string name;
    int age;
    char sex;

public:
    Person(string n, int a, char s) : name(n), age(a), sex(s) {}

    // Pure virtual functions are declared with the = 0 syntax
    // They are used as a blueprint for derived classes, and must be implemented in the derived class
    virtual void setName(string n) = 0;
    virtual void setAge(int a) = 0;
    virtual void setSex(char s) = 0;
    virtual void display() = 0;

    virtual string getName() = 0;
    virtual int getAge() = 0;
    virtual char getSex() = 0;
};

class Employee : public Person
{
private:
    int wage;

public:
    Employee(string n, int a, char s, int w) : Person(n, a, s), wage(w) {}

    // Implementing the pure virtual functions from the base class
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setSex(char s) { sex = s; }
    void setWage(int w) { wage = w; }

    string getName() { return name; }
    int getAge() { return age; }
    char getSex() { return sex; }
    int getWage() { return wage; }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Sex: " << sex << endl;
        cout << "Wage: " << wage << endl;
    }
};

int main()
{
    Employee e1("Camden", 19, 'M', 15);
    e1.display();
    

    return 0;
}