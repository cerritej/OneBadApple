#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main() {
    int k;
    printf("Enter the number of nodes in the ring: ");
    scanf("%d", &k);

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
        sendApple(&nodes[i], &nodes[(i + 1) % k], "Apple Message");
        receiveApple(&nodes[i]);
    }

    // Free dynamically allocated memory
    free(nodes);

    return 0;
}
