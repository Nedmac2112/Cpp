#include <iostream>
#include <stack>
using namespace std;

int main()
{
    // Stacks are a collection of elements of the same data type, stored in a LIFO (Last In First Out) order
    // Elements are added and removed from the top

    stack<int> s;

    // Push elements into the stack
    s.push(1);
    s.push(2);
    s.push(3);

    // Print the top element of the stack
    cout << "The top element of the stack is: " << s.top() << endl;

    // Pop the top element of the stack
    s.pop();

    cout << "The top element of the stack is: " << s.top() << endl;

    // Check if the stack is empty
    cout << "Is the stack empty? " << (s.empty() ? "Yes" : "No") << endl;

    return 0;
}