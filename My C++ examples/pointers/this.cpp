#include <iostream>
using namespace std;

class Airplane
{
private:
    int altitude;

public:
    Airplane();
    void Print() const;
    void SetAltitude(int altitude);
};

Airplane::Airplane()
{
    altitude = 0;
}

void Airplane::SetAltitude(int altitude)
{
    // this is used to refer to the object itself
    // so this->altitude is the altitude of the object
    this->altitude = altitude;
}

void Airplane::Print() const
{
    cout << altitude << " meters" << endl;
}

int main()
{
    Airplane boeing747;

    boeing747.SetAltitude(10000);
    boeing747.Print();

    return 0;
}