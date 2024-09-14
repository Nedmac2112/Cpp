#include <iostream>
using namespace std;

int main()
{
    cout << "Hello, World";
    return 0;
}

// 1. Preprocessing
// g++ -E main.cpp -o main.ii

// 2. Compilation to assembly
// g++ -S main.ii -o main.s

// 3. Assembly to object code
// g++ -c main.s -o main.o

// 4. Linking to create executable
// g++ main.o -o main.exe
