#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {
} // Destructor

void LinkedList::insertAtBeginning(int value) {
    Node* newNode = new Node; // Instantiate the node by dynamically allocating memory
    newNode->data = value; // Set the data to be the value
    newNode->next = nullptr; // Set the next node to be null

    if (head == nullptr) {
        head = newNode; // If list is empty, set newNode as head
    } else {
        newNode->next = head; // Else, make the newNode point to current head
        head = newNode; // Update head
    }
}

void LinkedList::insertAtEnd(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr; 

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

void LinkedList::insertAtPosition(int position, int value) {
    // Create a new node
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    // Handle insertion at the beginning (position == 0) separately
    if (position == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Traverse to the node just before the position
    Node* current = head;
    int index = 0;
    while (current != nullptr && index < position - 1) {
        current = current->next;
        index++;
    }

    // Check if the position is valid
    if (current == nullptr) {
        std::cerr << "Invalid position. Insertion failed." << std::endl;
        delete newNode;
        return;
    }

    // Perform the insertion
    newNode->next = current->next;
    current->next = newNode;
}

void LinkedList::deleteAtBeginning() {
    if (head == nullptr) {
        std::cerr << "List is empty. \n";
        return; 
    }

    Node* temp = head;
    head = head->next;
    delete temp;
    return;
}

void LinkedList::deleteAtPosition(int position) {
    // Handle case where list is empty
    if (head == nullptr) {
        std::cerr << "List is empty. Deletion failed." << std::endl;
        return;
    }

    // Handle deletion at the beginning (position == 0) separately
    if (position == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Traverse to the node just before the position
    Node* current = head;
    int index = 0;
    while (current != nullptr && index < position - 1) {
        current = current->next;
        index++;
    }

    // Check if the position is valid
    if (current == nullptr || current->next == nullptr) {
        std::cerr << "Invalid position. Deletion failed." << std::endl;
        return;
    }

    // Perform the deletion
    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
}


void LinkedList::display() {
    // Start from the head of the list
    Node* current = head;

    // Traverse the list and print each node's data
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl; // Print a newline after displaying all elements
}
