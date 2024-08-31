// Camden K., 11/8/23, cckirkpatrick@dmacc.edu
// program that uses a factory class and a product class and outputs the production info

// libraries
#include <iostream>
using namespace std;

// Class that stores the product information
class Product
{
private:
    string name;

public:
    Product(string name) : name(name) {}
    string getName()
    {
        return name;
    }
};

// class that stores the factory information
class Factory
{
private:
    string location;
    int capacity;

public:
    Factory(string location, int capacity) : location(location), capacity(capacity) {}
    void makeProduct(Product product);
};

void Factory::makeProduct(Product product)
{

    cout << "Factory is now making " << product.getName() << endl;
    cout << "Capacity is: " << capacity << endl;
    // decreases the capacity by one each time a product is made (Extra credit)
    capacity--;

    // if the capacity is zero, output: "Out of capacity" (Extra credit)
    if (capacity == 0)
    {
        cout << "Out of capacity" << endl;
    }
}

int main()
{
    // created a Kellogs factory with 3 products
    Factory Kellogs("Dallas, Texas", 3);

    Product cereal("FrostedFlakes");
    Kellogs.makeProduct(cereal);

    Product bars("Nutri Grain");
    Kellogs.makeProduct(bars);

    Product treats("RiceKripies Treats");
    Kellogs.makeProduct(treats);

    cout << endl;

    // created a Pepsi factory with 2 products
    Factory Pepsi("Kansas City, Missouri", 4);

    Product soda("Cherry Pepsi");
    Pepsi.makeProduct(soda);

    Product chips("Doritos");
    Pepsi.makeProduct(chips);

    return 0;
}

/* Test
Expected:
Factory is now making FrostedFlakes
Capacity is: 3
Factory is now making Nutri Grain
Capacity is: 2
Factory is now making RiceKripies Treats
Capacity is: 1
Out of capacity

Factory is now making Cherry Pepsi
Capacity is: 4
Factory is now making Doritos
Capacity is: 3

Received:
Factory is now making FrostedFlakes
Capacity is: 3
Factory is now making Nutri Grain
Capacity is: 2
Factory is now making RiceKripies Treats
Capacity is: 1
Out of capacity

Factory is now making Cherry Pepsi
Capacity is: 4
Factory is now making Doritos
Capacity is: 3
*/