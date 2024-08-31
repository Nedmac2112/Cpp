#include <iostream>
using namespace std;

class Test
{
private:
    int x;

public:
    Test() : x(0){};
    void setX(int x) { this->x = x; }
    // Return by reference (the address of x is returned)
    int &getX() { return x; }
    void print()
    {
        cout << "x = " << x << endl;
    }
};

int main()
{
    Test obj;
    obj.print();

    // ref shares the same memory location as x
    int &ref = obj.getX();
    // thr private member x is changed to 10
    ref = 10;
    obj.print();
    return 0;
}