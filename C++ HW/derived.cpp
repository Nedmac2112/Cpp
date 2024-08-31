// Camden K., 11/14/23, cckirkpatrick@dmacc.edu
// program that uses a class that inherits from another class

// libraries
#include <iostream>
using namespace std;

// parent class
class Person
{
public:
    // constructor
    Person()
    {
        firstName = "No Name";
        lastName = "No Name";
    }

    // sets the value of private data members
    void SetName(string first, string last)
    {
        firstName = first;
        lastName = last;
    }

    // prints the value of private data members
    void Print()
    {
        cout << "First name: " << firstName << endl
             << "Last name:  " << lastName << endl;
    }

private:
    string firstName;
    string lastName;
};

// child class that inherits from the Person class
class Student : public Person
{
public:
    // constructor
    Student()
    {
        ID = 0;
    }

    // sets the value of the private data member
    void SetID(int id)
    {
        ID = id;
    }

    // prints the values of the data members of both classes
    void Print()
    {
        Person::Print();
        cout << "ID number: " << ID;
    }

private:
    int ID;
};

int main()
{
    // object created
    Student student1;

    // set values for first and last name
    student1.SetName("Camden", "Kirkpatrick");
    // set the ID number
    student1.SetID(1234);
    // printed the results to the console
    student1.Print();

    return 0;
}

/* Test:
Expected: First name: Camden
Last name: Kirkpatrick
ID number: 1234

Received: First name: Camden
Last name: Kirkpatrick
ID number: 1234
*/