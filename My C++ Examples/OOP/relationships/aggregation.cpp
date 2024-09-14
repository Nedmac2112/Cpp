/*

    Aggregation is another type of association, and is similar to composition, but with a weaker relationship between the objects.
    In aggregation, the objects are independent of each other, and the lifetime of the objects can be different.
    In aggregation, the objects can exist independently of each other. In aggregation, the objects are related to
    each other, but they are not part of each other.

    This example uses an Employee and University class, where the University has an Employee object as a member.
    Aggregation makes sense here, since the Employee can exist independently of the University.

*/

#include <iostream>
using namespace std;

class Employee
{
private:
    int id;
    string name;

public:
    Employee(int id, string name) : id(id), name(name)
    {
        cout << "Employee " << name << " (ID: " << id << ") created at " << this << endl;
    }

    ~Employee()
    {
        cout << "Employee " << name << " (ID: " << id << ") destroyed at " << this << endl;
    }

    void display() const
    {
        cout << "Employee Details: ID: " << id << ", Name: " << name << " at " << this << endl;
    }
};

class University
{
private:
    string name;
    Employee *employee; // Pointer to an Employee, but doesn't own it

public:
    University(string name, Employee *employee) : name(name), employee(employee)
    {
        cout << "University " << name << " created, using Employee at " << employee << endl;
    }

    ~University()
    {
        cout << "University " << name << " destroyed, but Employee at " << employee << " still exists" << endl;
    }

    void display() const
    {
        cout << "University: " << name << endl;
        if (employee != nullptr)
            employee->display();
        else
            cout << "No employee assigned." << endl;
    }
};

int main()
{
    // Dynamically allocate an Employee object
    Employee *employee1 = new Employee(1, "Alice");

    {
        University university("Stanford University", employee1); // Aggregation: university refers to employee1
        university.display();
        cout << endl;
    } // University object destroyed, but employee1 is still in memory

    // Now we show that employee1 still exists independently of the University
    cout << "Employee details after University object is destroyed (should still be intact):" << endl;
    employee1->display(); // Employee1 still exists after University is destroyed

    // Manually destroy the employee now
    delete employee1;
    cout << "Employee manually deleted." << endl;

    return 0;
}
