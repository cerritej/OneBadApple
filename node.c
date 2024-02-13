#include <stdio.h>
#include <stdlib.h>
#include "node.h"

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a ring structure
struct Node* createRing(int n) {
    if (n <= 0) {
        printf("Invalid number of nodes\n");
        return NULL;
    }

    struct Node* head = createNode(0);
    struct Node* current = head;

    for (int i = 1; i < n; i++) {
        current->next = createNode(i);
        current = current->next;
    }

    current->next = head;

    return head;
}

// Function to print the ring
void printRing(struct Node* head, int size) {
    struct Node* current = head;
    printf("Ring: ");
    for (int i = 0; i < size; i++) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("...\n");
}
