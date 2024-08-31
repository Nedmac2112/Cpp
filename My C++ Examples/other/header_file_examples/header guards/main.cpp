#include <iostream>
using namespace std;
#include "car.h"
#include "engine.h" 

int main()
{
	Engine e(450);
	Car c("red");
	
	e.printHorsePower();
	cout << endl;
	c.printColor();

    return 0;
}