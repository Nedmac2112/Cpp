// Program that passes a pointer to a function, thant changes a variable outside the function



#include <iostream>
using namespace std;

 void outputSize(int *size) // An easier way to do this would be to pass by reference. (See passByRef.cpp)
{
    cout << *size << " inches" << endl;
    *size = 20;
}

int main()
{

    int deskHeight = 30;
    outputSize(&deskHeight);
    // deskHeight is now 20
    cout << deskHeight;
    return 0;
}
