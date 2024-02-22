#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main() {
    int k, destNode;
    char message[256];

    // Prompt the user for the number of nodes
    printf("Enter the number of nodes in the ring: ");
    scanf("%d", &k);

    // Allocate memory for nodes
    struct Node* nodes = malloc(k * sizeof(struct Node));
    if (nodes == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    // Create and initialize nodes
    for (int i = 0; i < k; i++) {
        initializeNode(&nodes[i], i);
    }

    // Main loop for sending and receiving messages
    for (int i = 0; i < k; i++) {
        // Prompt the user for the message
        printf("Enter the message to send to node %d: ", i);
        getchar();  // consume newline character from previous scanf
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = '\0';  // remove newline character from message

        // Prompt the user for the destination node
        printf("Enter the destination node (0-%d): ", k-1);
        scanf("%d", &destNode);

        // Validate destination node input
        if (destNode < 0 || destNode >= k) {
            printf("Invalid destination node. Please enter a node between 0 and %d.\n", k-1);
            return 1;
        }

        // Send the message to the destination node
        sendApple(&nodes[i], &nodes[destNode], message);
        printf("Node %d sent the message '%s' to node %d.\n", i, message, destNode);

        // Receive the apple
        receiveApple(&nodes[i]);
    }

    // Free dynamically allocated memory
    free(nodes);

    return 0;
}
