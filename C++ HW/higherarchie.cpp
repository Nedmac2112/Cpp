// Camden K., 11/19/23, cckirkpatrick@dmacc.edu

// libraries
#include <iostream>
using namespace std;

// Ship class
class Ship
{
private:
    string name;
    string year;

public:
    // Constructor
    Ship(const string &name, const string &year) : name(name), year(year){};

    // Mutator for name
    void setName(string name)
    {
        this->name = name;
    }

    // Mutator for year
    void setYear(string year)
    {
        this->year = year;
    }

    // Accessor for name
    string getName() const
    {
        return name;
    }

    // Accessor for year
    string getYear() const
    {
        return year;
    }

    // Virtual print function
    virtual void Print() const
    {
        cout << "Name: " << name << endl;
        cout << "Year: " << year;
    }
};

// CruiseShip class
class CruiseShip : public Ship
{
private:
    int maxPassengers;

public:
    // Constructor
    CruiseShip(const string &name, const string &year, int maxPass) : Ship(name, year), maxPassengers(maxPass){};

    // Mutator
    void setMaxPas(int maxPas)
    {
        maxPassengers = maxPas;
    }

    // Accessor
    int getMaxPas() const
    {
        return maxPassengers;
    }

    // Override Print function
    void Print() const override
    {
        cout << "Cruise ship name: " << getName() << "\n"
             << "Max Passenger capacity: " << maxPassengers;
    }
};

// CargoShip class
class CargoShip : public Ship
{
private:
    int cargoCapacity;

public:
    // Constructor
    CargoShip(const string &name, const string &year, int capacity) : Ship(name, year), cargoCapacity(capacity) {}

    // Mutator
    void setCargoCapacity(int capacity)
    {
        cargoCapacity = capacity;
    }

    // Accessor
    int getCargoCapacity() const
    {
        return cargoCapacity;
    }

    // Override print function
    void Print() const override
    {
        cout << "Cargo Ship Name: " << getName() << "\n"
             << "Cargo Capacity: " << cargoCapacity << " tons" << endl;
    }
};

int main()
{
    // array of Ship objects created
    Ship *ships[3];
    // objects are given parameters used in the member functions
    ships[0] = new Ship("USS Pearl", "2000");
    ships[1] = new CruiseShip("Alaska Cruise", "2010", 3200);
    ships[2] = new CargoShip("Big Bertha", "2020", 1000000);

    // Calling Print() function for each object in the array
    for (int i = 0; i < 3; ++i)
    {
        ships[i]->Print();
        cout << endl;
    }

    return 0;
}

/* Test
Expected:
Name: USS Pearl
Year: 2000
Cruise ship name: Alaska Cruise
Max Passenger capacity: 3200
Cargo Ship Name: Big Bertha
Cargo Capacity: 1000000 tons

Received:
Name: USS Pearl
Year: 2000
Cruise ship name: Alaska Cruise
Max Passenger capacity: 3200
Cargo Ship Name: Big Bertha
Cargo Capacity: 1000000 tons
*/