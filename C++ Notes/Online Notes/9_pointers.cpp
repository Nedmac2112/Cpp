#include <iostream>
using namespace std;

int main()
{
    cout << "Pointers - Declaring, Initializing, and Using\n";

    // Declare a pointer
    int *p1 = nullptr; // p1 does not point to any address

    // Initialize a pointer
    int x = 20;
    p1 = &x; // p1 now points to the memory address of x

    // Declare and Initialize a pointer
    int *p2 = &x;

    // Print pointer address
    cout << "Address stored in p1: " << p1 << endl;
    cout << "Address stored in p2: " << p2 << endl;

    // Changing what a pointer points to
    int y = 4;
    p1 = &y; // p1 now points to the memory address of y
    cout << "Address stored in p1 after reassignment: " << p1 << endl;

    // Dereferencing a pointer
    cout << "Value pointed to by p1: " << *p1 << endl;

    cout << endl
         << endl;

    // Character pointers
    cout << "Character Pointers\n";

    // C-style string
    const char *message = "Hello World";
    cout << "Message: " << message << endl;
    cout << "First character: " << *message << endl;

    // Character pointer array
    const char *messages[] = {"Hello", "Goodbye", "How are you?", "What's your name?"};
    cout << "First message: " << messages[0] << endl;
    cout << "Second message: " << messages[1] << endl;

    cout << endl
         << endl;

    // Constant Pointers
    cout << "Constant Pointers\n";

    int z = 20;
    const int *p3 = &z;
    // *p3 = 30; // This will not work, p3 points to a constant value

    int w = 4;
    int *const p4 = &z;
    // p4 = &w; // This will not work, p4 is a constant pointer

    const int *const p5 = &z;
    // *p5 = 30; // This will not work
    // p5 = &w; // This will not work

    cout << "Value pointed to by p3: " << *p3 << endl;
    cout << "Value pointed to by p4: " << *p4 << endl;

    cout << endl
         << endl;

    // Swapping two arrays using pointers
    int arr0[5]{1, 2, 3, 4, 5};
    int arr1[5]{6, 7, 8, 9, 10};
    int *p_arr1{arr1};
    int *p_arr0{arr0};

    int *temp{nullptr};

    // Swap pointers
    temp = p_arr1;
    p_arr1 = p_arr0;
    p_arr0 = temp;

    cout << "Swapping Two Arrays Using Pointers\n";
    cout << "arr0 : ";
    for (int i = 0; i < size(arr0); ++i)
    {
        cout << p_arr0[i] << " ";
    }
    cout << endl;

    cout << "arr1 : ";
    for (int i = 0; i < size(arr1); ++i)
    {
        cout << p_arr1[i] << " ";
    }
    cout << endl
         << endl;

    cout << "Pointer Arithmetic\n";

    int nums[4] = {34, 21, 88, 67};
    int *p6 = nums;

    cout << "First element pointed to by p6: " << *p6 << endl;
    p6++;
    cout << "Second element pointed to by p6: " << *p6 << endl;

    *(p6 - 1) = 10; // equivalent to nums[1] = 10;

    cout << "Modified array: ";
    for (int i = 0; i < 4; ++i)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    int *p7 = (nums + 1);
    int *p8 = (nums + 3);
    cout << "Distance between p7 and p8: " << (p8 - p7) << endl;

    cout << endl
         << endl;

    // Dynamic Memory Allocation
    cout << "Dynamic Memory Allocation\n";

    // Creating dynamic memory
    int *p9 = new int; // allocates memory for one int on the heap

    // Assigning a value to dynamic memory
    int *p10 = new int(10);
    cout << "Value pointed to by p10: " << *p10 << endl;

    // Deleting dynamic memory
    delete p9;
    p9 = nullptr;

    delete p10;
    p10 = nullptr;

    // Dynamic array
    int *numsArray = new int[5]{23, 12, 82, 45, 76};
    cout << "Dynamic array values: ";
    for (int i = 0; i < 5; ++i)
    {
        cout << numsArray[i] << " ";
    }
    cout << endl;

    delete[] numsArray;
    numsArray = nullptr;

    return 0;
}
