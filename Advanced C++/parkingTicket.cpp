// Camden K., 8/30/24, cckirkpatrick@dmacc.edu
/*
    This program creates a car, parking meter, police officer, and parking ticket class to simulate
    a police officer issuing a parking ticket to a car that has been parked longer than the time
    purchased on the parking meter.
*/

#include <iostream>
using namespace std;

// Class Definitions

// ParkedCar class, sets up a car object, stores car info, and time parked
class ParkedCar
{
private:
    string make;
    string model;
    string color;
    string licenseNumber;
    int minutesParked;

public:
    ParkedCar(string make, string model, string color, string licenseNumber, int minutesParked) : make(make), model(model), color(color), licenseNumber(licenseNumber), minutesParked(minutesParked) {}

    string getMake() { return make; }
    string getModel() { return model; }
    string getColor() { return color; }
    string getLicenseNumber() { return licenseNumber; }
    int getMinutesParked() { return minutesParked; }
};
/*



*/
// ParkingMeter class, sets up a parking meter object to store the time purchased
class ParkingMeter
{
private:
    int purchasedTime;

public:
    ParkingMeter(int purchasedTime) : purchasedTime(purchasedTime) {}

    int getPurchasedTime() { return purchasedTime; }
};
/*



*/
// ParkingTicket class, sets up a parking ticket object (this will be issued by the police officer)
class ParkingTicket
{
private:
    ParkedCar car;
    ParkingMeter meter;
    int fine;
    int minutesOver;

public:
    ParkingTicket(ParkedCar car, ParkingMeter meter, int fine, int minutesOver) : car(car), meter(meter), fine(fine), minutesOver(minutesOver) {}

    int getFine() { return fine; }
    int getMinutesOver() { return minutesOver; }

    void printTicket()
    {
        cout << "Car: " << car.getMake() << " " << car.getModel() << " " << car.getColor() << " " << car.getLicenseNumber() << endl;
        cout << "Minutes Parked: " << car.getMinutesParked() << endl;
        cout << "Purchased Time: " << meter.getPurchasedTime() << endl;
        cout << "Fine: $" << fine << endl;
    }
};
/*


*/
// PoliceOfficer class, sets up a police officer object to examine the car and issue a ticket
class PoliceOfficer
{
private:
    string name;
    string badgeNumber;

public:
    PoliceOfficer(string name, string badgeNumber) : name(name), badgeNumber(badgeNumber) {}

    string getName() { return name; }
    string getBadgeNumber() { return badgeNumber; }

    // Examine the car and parking meter to determine if a ticket should be issued
    bool examineCar(ParkedCar &car, ParkingMeter &meter)
    {
        if (car.getMinutesParked() > meter.getPurchasedTime())
        {
            return true;
        }
        return false;
    }

    // Issue a ticket to the car
    ParkingTicket issueTicket(ParkedCar &car, ParkingMeter &meter)
    {
        // Fine starts at $25
        int fine = 25;
        // Calculate the minutes over the purchased time
        int minutesOver = car.getMinutesParked() - meter.getPurchasedTime();
        // Calculate the hours over the purchased time
        int hoursOver = minutesOver / 60;

        // Add $10 for each hour over the purchased time
        for (int i = 0; i < hoursOver; i++)
        {
            fine += 10;
        }

        // Return the parking ticket object
        return ParkingTicket(car, meter, fine, minutesOver);
    }
};

int main()
{
    ParkedCar car("Toyota", "Camry", "Black", "123abc", 120);
    ParkingMeter meter(60);
    PoliceOfficer officer("John", "300");

    // if the car has been parked longer than the purchased time, issue a ticket
    if (officer.examineCar(car, meter))
    {
        ParkingTicket ticket = officer.issueTicket(car, meter);
        ticket.printTicket();
    }
    else
    {
        cout << "No ticket issued" << endl;
    }

    cout << endl;

    ParkedCar car2("Toyota", "Corolla", "Red", "456def", 30);
    ParkingMeter meter2(60);

    if (officer.examineCar(car2, meter2))
    {
        ParkingTicket ticket2 = officer.issueTicket(car2, meter2);
        ticket2.printTicket();
    }
    else
    {
        cout << "No ticket issued" << endl;
    }
    return 0;
}

/*
Tests

Test Case 1:
Car: Toyota Camry Black 123abc
Minutes Parked: 120
Purchased Time: 60

Expected Output:
Fine: $35

Actual Output:
Fine: $35


Test Case 2:
Car: Toyota Corolla Red 456def
Minutes Parked: 30
Purchased Time: 60

Expected Output:
No ticket issued

Actual Output:
No ticket issued

*/