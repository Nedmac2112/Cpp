#include "engine.h" // already included in main.cpp!

class Car
{
	private:
		string color;
	public:
		Car(string c): color(c) {}
		void printColor() {cout << "Color: " << color;}

};