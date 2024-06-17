#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head; // Pointer to the head of the linked list

public:
    LinkedList(); // Constructor
    ~LinkedList(); // Destructor

    void insertAtBeginning(int value); // Inserts value at beginning
    void insertAtEnd(int value);
    void insertAtPosition(int position, int value);
    void deleteAtBeginning();
    void deleteAtEnd();
    void deleteAtPosition(int position);
    void display();
};

#endif // LINKEDLIST_H
