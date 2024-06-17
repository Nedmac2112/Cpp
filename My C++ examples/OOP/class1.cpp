// Purpose: Demonstrate a simple class in C++
// Description: This program demonstrates a simple class in C++. The class has a private data member and public member functions to set and get the value of the private data member. The program creates an object of the class and sets the value of the private data member using the public member function. The program then gets the value of the private data member using the public member function and outputs it to the console.
// Last modified: 5/7/2024

#include <iostream>
using namespace std;

// This is a class declaration
class Billboard
{
// This is where the private data members are declared
// Private data members are only accessible within the class
private:
    string title;

// This is where the public member functions are declared
// Public member functions are accessible from outside the class
// These functions are used to set and get the value of the private data members
public:
    void setTitle(string x)
    {
        title = x;
    }

    // This function is const, which means it cannot modify the object's data members
    // All member functions that do not modify the object's data members should be declared const
    string getTitle() const
    {
        return title;
    }
};

int main()
{
    // Create an object of the class
    Billboard bill;
    // Set the title of the billboard
    bill.setTitle("Top 10 songs of 1981");
    // Output the title of the billboard
    cout << bill.getTitle();
    return 0;
}