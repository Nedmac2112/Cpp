#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class StackEmptyException : public runtime_error
{
public:
    StackEmptyException() : runtime_error("Stack is empty") {}
};

class StackFullException : public runtime_error
{
public:
    StackFullException() : runtime_error("Stack is full") {}
};

class Stack
{
private:
    int top;
    int maxSize;
    string *stackItems; // you could also use a vector<string> instead of a string pointer

public:
    // Default constructor
    Stack() : maxSize(5), top(-1)
    {
        stackItems = new string[maxSize];
    }

    // Parameterized constructor
    Stack(int size) : maxSize(size), top(-1)
    {
        stackItems = new string[maxSize];
    }

    // Destructor
    ~Stack()
    {
        delete[] stackItems;
    }

    // Check if the stack is full
    bool isFull() const
    {
        return top == maxSize - 1;
    }

    // Check if the stack is empty
    bool isEmpty() const
    {
        return top == -1;
    }

    // Get the number of elements in the stack
    int size() const
    {
        return top + 1;
    }

    // Peek at the top element
    string peek() const
    {
        if (!isEmpty())
        {
            return stackItems[top];
        }
        else
        {
            throw StackEmptyException();
        }
    }

    // Pop the top element
    string pop()
    {
        if (!isEmpty())
        {
            string item = stackItems[top];
            stackItems[top] = ""; // Clear the element
            top--;
            return item;
        }
        else
        {
            throw StackEmptyException();
        }
    }

    // Push an element onto the stack
    void push(const string &item)
    {
        if (!isFull())
        {
            top++;
            stackItems[top] = item;
        }
        else
        {
            throw StackFullException();
        }
    }

    // Print stack elements from bottom to top
    string printStackUp() const
    {
        if (!isEmpty())
        {
            string stackString;
            for (int i = 0; i <= top; i++)
            {
                stackString += stackItems[i] + "\n";
            }
            return stackString;
        }
        else
        {
            throw StackEmptyException();
        }
    }
};

int main()
{
    try
    {
        Stack myStack(3); // Create a stack with max size of 3

        myStack.push("Item1");
        myStack.push("Item2");
        myStack.push("Item3");

        cout << "Stack contents:\n"
             << myStack.printStackUp() << endl;

        cout << "Popped item: " << myStack.pop() << endl;
        cout << "Popped item: " << myStack.pop() << endl;
        cout << "Popped item: " << myStack.pop() << endl;
    }
    catch (const StackEmptyException &e)
    {
        cerr << e.what() << endl;
    }
    catch (const StackFullException &e)
    {
        cerr << e.what() << endl;
    }

    try
    {
        Stack myStack; // Create a stack with max size of 3
        

    
    }
    catch (const StackEmptyException &e)
    {
        cerr << e.what() << endl;
    }
    catch (const StackFullException &e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}
