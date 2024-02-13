#ifndef NODE_H
#define NODE_H

// Define a structure for a node
struct Node {
    int data;            // Data stored in the node
    struct Node* next;   // Pointer to the next node
};

// Function to create a new node
struct Node* createNode(int data);

// Function to create a ring structure
struct Node* createRing(int n);

// Function to print the ring
void printRing(struct Node* head, int size);

#endif /* NODE_H */
