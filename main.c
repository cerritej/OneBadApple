#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main() {
    int n;
    printf("Enter the number of nodes in the ring: ");
    scanf("%d", &n);

    struct Node* ring = createRing(n);
    printRing(ring, n);

    struct Node* current = ring;
    struct Node* temp;
    for (int i = 0; i < n; i++) {
        temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
