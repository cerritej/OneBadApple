#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "node.h"

// Function to prompt the user for the number of nodes
int promptNumNodes() {
    int k;
    printf("Enter the number of nodes in the ring: ");
    scanf("%d", &k);
    return k;
}

// Function to initialize nodes
void initNodes(int k, struct Node* nodes) {
    for (int i = 0; i < k; i++) {
        initializeNode(&nodes[i], i);
    }
}

// Function to prompt the user for a message and destination node
void promptUser(char* message, int* destNode, int k) { 
    printf("Enter the message to send: ");
    getchar();  // consume newline character from previous scanf
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';  // remove newline character from message

    printf("Enter the destination node (0-%d): ", k-1);
    scanf("%d", destNode);
}

// Function to send the apple to the destination node
void sendAppleToNode(struct Node* nodes, int nodeIndex, const char* message, int destNode) {
    sendApple(&nodes[nodeIndex], &nodes[destNode], message);
    printf("Node %d sent the message '%s' to node %d.\n", nodeIndex, message, destNode);
}

// Function to receive the apple and process it
void recvAndProcess(struct Node* nodes, int nodeIndex) {
    receiveApple(&nodes[nodeIndex]);
}

int main() {
    int k, destNode;
    char message[256];

    k = promptNumNodes();

    struct Node* nodes = malloc(k * sizeof(struct Node));
    if (nodes == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    initNodes(k, nodes);

    for (int i = 0; i < k; i++) {
        promptUser(message, &destNode, k); 
        sendAppleToNode(nodes, i, message, destNode);
        recvAndProcess(nodes, i);
    }

    free(nodes);

    return 0;
}
