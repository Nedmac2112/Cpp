// Purpose: Demonstrate how to define member functions outside of the class definition
// Description: This program demonstrates how to define member functions outside of the class definition in C++. The program defines a class called Restaurant with private data members name and rating. The program declares the member functions SetName, SetRating, GetName, GetRating, and Print inside the class definition. The program defines the member functions SetName, SetRating, GetName, GetRating, and Print outside of the class definition. The program creates an object of the class and sets the name and rating using the member functions. The program then gets the name and rating using the member functions and outputs them to the console.
// Last modified: 5/7/2024

#include <iostream>
#include <string>
using namespace std;

class Restaurant
{

private:
    string name;
    int rating;

// You can declare the function prototypes in the private section of the class
public:
    void SetName(string restaurantName); 
    void SetRating(int userRating);      
    string GetName() const;              
    int GetRating() const;              
    void Print() const;                  
};

// You can define the member functions outside of the class
void Restaurant::SetName(string restaurantName)
{
    name = restaurantName;
}

void Restaurant::SetRating(int userRating)
{
    rating = userRating;
}

string Restaurant::GetName() const
{
    return name;
}

int Restaurant::GetRating() const
{
    return rating;
}

void Restaurant::Print() const
{
    cout << name << " -- " << rating << endl;
}

int main()
{
    Restaurant myPlace;

    myPlace.SetName("Maria's Diner");
    myPlace.SetRating(5);

    cout << myPlace.GetName() << " is rated ";
    cout << myPlace.GetRating() << " stars." << endl;

    myPlace.Print();

    return 0;
}