#ifndef NODE_H
#define NODE_H

#include <stdbool.h>

// Define a structure for a node
struct Node {
    int id;             // Node ID
    int read_fd;        // File descriptor for reading
    int write_fd;       // File descriptor for writing
    bool hasApple;      // Flag to indicate if the node has the apple
};

// Function to create and initialize a node
void initializeNode(struct Node* node, int id);

// Function for a node to send the apple
void sendApple(struct Node* sender, struct Node* receiver, const char* message);

// Function for a node to receive and process the apple
void receiveApple(struct Node* node);

#endif /* NODE_H */
