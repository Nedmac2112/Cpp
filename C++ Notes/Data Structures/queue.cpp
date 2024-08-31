#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // Queues are a collection of elements of the same data type, stored in a FIFO (First In First Out) order
    // Elements are added at the back and removed from the front

    // Create a queue
    queue<int> q;

    // Push elements into the queue
    q.push(1);
    q.push(2);
    q.push(3);

    // Print the front element of the queue
    cout << "The front element of the queue is: " << q.front() << endl;

    // Pop the front element of the queue
    q.pop();

    cout << "The front element of the queue is: " << q.front() << endl;

    // Check if the queue is empty
    cout << "Is the queue empty? " << (q.empty() ? "Yes" : "No") << endl;
    return 0;
}