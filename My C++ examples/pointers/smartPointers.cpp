#include <iostream>
#include <memory>
using namespace std;

class MyClass
{
private:
    int data;

public:
    MyClass() { cout << "Constructor\n"; }

    void setData(int data) { this->data = data; }
    int getData() const { return data; }

    ~MyClass() { cout << "Destructor\n"; }
};
int main()
{
    // Unique pointers can only have one owner

    unique_ptr<int> uniquePtr1 = make_unique<int>(10);
    // You could also do this:
    // unique_ptr<int> uniquePtr1(new int(10));

    cout << "Address of uniquePtr1: " << uniquePtr1.get() << "\n";
    cout << "uniquePtr1: " << *uniquePtr1 << "\n\n";

    // You can't share ownership of a unique pointer
    // uniquePtr2 = uniquePtr1;

    // Now uniquePtr2 has ownership of the memory location of uniquePtr1
    unique_ptr<int> uniquePtr2 = move(uniquePtr1);
    cout << *uniquePtr2 << "\n";
    // Now uniquePtr1 is nullptr
    cout << uniquePtr1.get() << "\n";

    unique_ptr<MyClass> myClassPtr = make_unique<MyClass>();
    myClassPtr->setData(10);
    // cout << myClassPtr->getData() << "\n";

    /*


    */

    // Shared pointers can share ownership of a memory location

    shared_ptr<MyClass> sharedPtr1 = make_shared<MyClass>();
    cout << "Shared count: " << sharedPtr1.use_count() << "\n";

    {
        shared_ptr<MyClass> sharedPtr2 = sharedPtr1;
        cout << "Shared count: " << sharedPtr1.use_count() << "\n";
        // sharedPtr2 goes out of scope here, and it is destroyed
    }

    cout << "Shared count: " << sharedPtr1.use_count() << "\n";

    return 0;
}
