// #ifndef ENGINE_H // this will prevent any errors from occurring, if engine.h is included more than once
// #define ENGINE_H // everything after this line is considered "ENGINE_H"

#pragma once // this is a simpler way to do the above

class Engine
{
	private:
		int horsePower;
	public:
		Engine(int h): horsePower(h) {}
		void printHorsePower() {cout << "HP: " << horsePower;}


};

// #endif