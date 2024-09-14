// Camden K., 9/9/24, cckirkpatrick@dmacc.edu
// Program that demonstrates pure virtual functions in C++, by using a Boat class and three classes that inherit from it: Sailboat, Powerboat, and Blaster

#include <iostream>
using namespace std;
class Boat
{
protected:
    int length;

public:
    int getLength() { return length; }
    virtual void Model() = 0;
};

class Sailboat : public Boat
{
protected:
    int mast;

public:
    int getMast() { return mast; }
    virtual void Boom() = 0;
};

class Laser : public Sailboat
{
public:
    Laser()
    {
        mast = 19;
        length = 35;
    }
    ~Laser() {}
    void Model() { cout << "Laser Classic" << endl; }
    void Boom() { cout << "Boom: 14ft" << endl; }
};

// Powerboat class inherits from Boat class
class Powerboat : public Boat
{
protected:
    int power;

public:
    int getPower() { return power; }
    // Pure virtual function, that Blaster implements
    virtual void Engine() = 0;
};

// Blaster class inherits from Powerboat class
class Blaster : public Powerboat
{
public:
    // Constructor for Blaster class
    Blaster()
    {
        power = 220;
        length = 10;
    }
    ~Blaster() {}
    // Model of Blaster (implementation of pure virtual function in Boat class)
    void Model() { cout << "Blaster 2400" << endl; }
    // Engine of Blaster (implementation of pure virtual function in Powerboat class)
    void Engine() { cout << "Engine: 2400cc" << endl; }
};
int main()
{
    Laser *pLaser = new Laser;
    pLaser->Model();
    cout << "Length: " << pLaser->getLength() << "ft" << endl;
    cout << "Height: " << pLaser->getMast() << "ft" << endl;
    pLaser->Boom();
    cout << endl;

    // Create a Blaster object
    Blaster *pBlaster = new Blaster;
    // Call the Model function (inherited from Boat class)
    pBlaster->Model();
    // Call the getLength function (inherited from Boat class)
    cout << "Length: " << pBlaster->getLength() << "ft" << endl;
    // Call the getPower function (inherited from Powerboat class)
    cout << "Power: " << pBlaster->getPower() << "hp" << endl;
    // Call the Engine function (inherited from Powerboat class)
    pBlaster->Engine();
    return 0;
}

// Test: the derived classes all work properly, giving the correct output
