// Purpose: Demonstrate the Singleton design pattern in C++.
// Description: The Singleton design pattern is a creational design pattern that ensures that a class has only one instance and provides a global point of access to that instance. The Singleton pattern is implemented by creating a class with a method that creates a new instance of the class if one does not exist. If an instance already exists, it simply returns a reference to that object. To make sure that the class has only one instance, the constructor is made private, and a static variable is used to hold the instance of the class. The Singleton pattern is used in scenarios where a single instance of a class is required
// Last modified: 05/14/2024

#include <iostream>

using namespace std;

class Planet
{
private:
  static Planet *inst;
  Planet() {}
  ~Planet() {}

public:
  static Planet *GetInstance();
};

// inst is a pointer to a Planet object, and is initialized to NULL.
Planet *Planet::inst = nullptr;

// GetInstance() is a static member function that returns a pointer to a Planet object.
Planet *Planet::GetInstance()
{
  if (inst == 0)
  {
    inst = new Planet();
  }
  return inst;
}

int main()
{
  // Only one instance of the Planet object is created.
  Planet *MyPlanet = Planet::GetInstance();
  cout << "MyPlanet address: " << MyPlanet << endl;

  // MyPlanet2 is a pointer to a Planet object, and is initialized to the same address as MyPlanet.
  Planet *MyPlanet2 = Planet::GetInstance();
  cout << "MyPlanet2 address: " << MyPlanet2 << endl;
  return 0;
}
