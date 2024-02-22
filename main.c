#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main() {
    int k, destNode;
    char message[256];

    // Prompt the user for the number of nodes
    printf("Enter the number of nodes in the ring: ");
    scanf("%d", &k);

    // Prompt the user for the message
    printf("Enter the message to send: ");
    scanf("%s", message);

    // Prompt the user for the destination node
    printf("Enter the destination node (0-%d): ", k-1);
    scanf("%d", &destNode);

    // Validate destination node input
    if (destNode < 0 || destNode >= k) {
        printf("Invalid destination node. Please enter a node between 0 and %d.\n", k-1);
        return 1;
    }

    // Allocate memory for nodes
    struct Node* nodes = malloc(k * sizeof(struct Node));
    if (nodes == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    // Create child processes to represent nodes
    for (int i = 0; i < k; i++) {
        if (fork() == 0) {
            // Child process
            initializeNode(&nodes[i], i);
            sendApple(&nodes[i], &nodes[(i + 1) % k], message);
            printf("Node %d sent the message '%s' to node %d.\n", i, message, (i + 1) % k);
            receiveApple(&nodes[i]);
            exit(EXIT_SUCCESS);
        }
    }

    // Wait for child processes to complete
    for (int i = 0; i < k; i++) {
        wait(NULL);
    }

    // Free dynamically allocated memory
    free(nodes);

    return 0;
}
