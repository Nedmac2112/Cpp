#include <iostream>
using namespace std;

int main()
{

    // Linked lists are a collection of elements of the same data type, stored in non-contiguous memory locations
    // Each element is called a node, and each node contains data and a reference to the next node

    struct Node
    {
        int data;
        Node *next;
    };

    // Create nodes using dynamic memory allocation
    Node *head = new Node(); // You could do this with a static memory allocation as well (Node head)
    Node *second = new Node();
    Node *third = new Node();

    // Assign data and link the nodes
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    // Traverse and print the linked list (time complexity: O(n))
    cout << "Traversing the linked list: " << endl;
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << "NULL" << endl
         << endl;

    // Add a node after the first node (time complexity: O(1))
    Node *newNode = new Node();
    newNode->data = 4;
    newNode->next = head->next; // Point the new node to the second node
    head->next = newNode;       // Point the first node to the new node

    temp = head;
    cout << "After adding a node after the first node: " << endl;
    while (temp != NULL)
    {
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    // Clean up memory (time complexity: O(n))
    for (temp = head; temp != NULL; temp = head)
    {
        head = head->next;
        delete temp;
    }

    return 0;
}
