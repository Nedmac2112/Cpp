#include <iostream>
using namespace std;

const double PI = 3.14159;
constexpr int X = 10;
// constinit int Y = 20; // must compile with C++20 (g++ -std=c++20 5_constants.cpp -o 5_constants)
int main()
{    
    // this checks the value of X at compile time
    static_assert(X == 10, "X should be 10");
    return 0;
}

