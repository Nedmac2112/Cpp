// Camden K., 11/7/23, cckirkpatrick@dmacc.edu
// program that creates a vector and populates it with objects

// libraries
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// class that stores information for each car object
class CarAuction
{
    // private class members
private:
    string id;
    int sold;
    int bluebook;
    int profit;
    // public class members
public:
    // mutators
    void setID(string ID)
    {
        id = ID;
    }
    void setSold(int Sold)
    {
        sold = Sold;
    }
    void setBluebook(int Bluebook)
    {
        bluebook = Bluebook;
    }
    void setProfit()
    {
        profit = sold - bluebook;
    }
    // accessors (I created accessors, but I used a print function to print the output)
    string getID() const
    {
        return id;
    }
    int getSold() const
    {
        return sold;
    }
    int getBluebook() const
    {
        return bluebook;
    }
    int getProfit() const
    {
        return profit;
    }
    // prints the info to the console
    void Print()
    {
        cout << "ID: " << id << endl
             << "Sold: $" << sold << endl
             << "Bluebook: $" << bluebook << endl;
    }

    // default constructor
    CarAuction()
    {
        id = "House";
        sold = 0;
        bluebook = 0;
    }
};

int main()
{
    // created 3 objects of class CarAuction
    CarAuction car1;
    CarAuction car2;
    CarAuction car3;

    // used set and get member functions on the car objects
    cout << "Stats of first car:" << endl;
    car1.setBluebook(20000);
    car1.setID("A46");
    car1.setSold(28000);
    car1.Print();
    car1.setProfit();
    cout << "Profit: $" << car1.getProfit() << endl;
    cout << endl;

    cout << "Stats of second car:" << endl;
    car2.setBluebook(34000);
    car2.setID("J81");
    car2.setSold(41000);
    car2.Print();
    car2.setProfit();
    cout << "Profit: $" << car2.getProfit() << endl;
    cout << endl;

    cout << "Stats of third car:" << endl;
    car3.Print();
    car3.setProfit();
    cout << "Profit: $" << car3.getProfit() << endl;
    cout << endl;

    // variables used when the user inputs object info
    int sold;
    int bluebook;
    string id;
    int i;
    int vSize;

    cout << "Input number of cars sold: " << endl;
    cin >> vSize;

    // created a vector with the size that the user inputs
    vector<CarAuction> carVector(vSize);

    // while its not the end of the vector, add objects to the vector
    for (i = 0; i < vSize; i++)
    {

        cout << "Please input the price sold for car " << i + 1 << ":" << endl;
        cin >> sold;
        cout << "PLease enter the bluebook price for car " << i + 1 << ":" << endl;
        cin >> bluebook;
        cout << "Please enter the ID for car " << i + 1 << ":" << endl;
        cin >> id;
        // sets the values of the object
        carVector[i].setSold(sold);
        carVector[i].setBluebook(bluebook);
        carVector[i].setID(id);
        carVector[i].setProfit();
        cout << endl;
    }

    for (i = 0; i < vSize; i++)
    {
        // prints out the values of the object
        cout << "Stats for car " << i + 1 << ":" << endl;
        carVector[i].Print();
        cout << "Profit for car " << i + 1 << ":"
             << "$" << carVector[i].getProfit() << endl;
        cout << endl;
    }

    return 0;
}

/*Test
Input: 1, 1000, 500, dh6.

Expected:
Stats for car 1:
ID: dh6
Sold: $1000
Bluebook: $500
Profit for car 1:
$500

Received:
Stats for car 1:
ID: dh6
Sold: $1000
Bluebook: $500
Profit for car 1:
$500
*/