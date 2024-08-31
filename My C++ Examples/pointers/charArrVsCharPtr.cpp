#include <iostream>
#include <cstring>
using namespace std;

int main()
{
     // C style strings
     cout << "C style strings" << endl
          << endl;
     // Method 1: Using character pointer
     cout << "Character pointer (char*)" << endl;
     const char *message1 = "Hello";
     cout << message1 << endl;
     cout << "Size of message1 : " << sizeof(message1) // this will give the size of a pointer (8 bytes)
          << endl
          << endl;
     // message1[0] = 'M'; // This will give error as message1 is a const pointer

     // Method 2: Using character array
     cout << "Character array (char[])" << endl;
     char message2[] = "Hello"; // stored as {'H', 'e', 'l', 'l', 'o', '\0'}
     cout << message2 << endl;
     cout << "Size of message2 : " << sizeof(message2) << endl; // this will give the size of the array (6 bytes)
     message2[0] = 'M';                                         // This will work as message2 is a character array
     cout << message2 << endl
          << endl;

     cout << "Dynamic memory allocation" << endl;
     // Dynamically allocating memory for character array and character pointer
     char *message3 = new char[6];
     // You could also initialize message3: char *message3 = new char[6]{"Hello"};
     // message3 = "Hello"; // This will give error as you can't directly assign a string to a pointer
     strcpy(message3, "Hello"); // This is how you can assign a string to a pointer
     cout << message3 << endl;
     // message3[0] = 'M'; // This will give error as message3 is a pointer
     delete[] message3; // delete the memory allocated on the heap
     message3 = nullptr; // this makes sure that the pointer is not pointing to any memory location
     

     return 0;
}