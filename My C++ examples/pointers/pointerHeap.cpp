#include <iostream>
using namespace std;

class Test
{
private:
    int data;

public:
    Test() { data = -1; }

    void setData(int data) { this->data = data; }

    int getData() const { return data; }
};

main()
{
    // This creates a pointer that points to a memory location in the heap
    // This int does not have a name, but the pointer does
    int *ptr = new int;
    *ptr = 10;
    // You can also do this in one line
    // int *ptr = new int(10);

    cout << *ptr << endl;
    cout << ptr << endl;

    // This deletes the memory allocated to the pointer
    delete ptr;
    // This makes sure that the pointer is not pointing to any memory location
    ptr = nullptr;

    // You can also create a pointer to an object in the heap
    Test *t = new Test;
    t->setData(100);
    cout << t->getData() << endl;

    delete t;
    t = nullptr;

    // You can also create an array of pointers in the heap
    int *arr = new int[5];

    for (int i = 0; i < 5; i++)
    {
        arr[i] = i + 1;
    }

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    delete[] arr;
    arr = nullptr;

    return 0;
}