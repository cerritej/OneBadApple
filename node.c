#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define APPLE_MESSAGE 256

void initializeNode(struct Node* node, int id) {
    node->id = id;
    node->hasApple = false;
    int fd[2];
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    node->read_fd = fd[0];    // Read end of the pipe
    node->write_fd = fd[1];   // Write end of the pipe
}

void sendApple(struct Node* sender, struct Node* receiver, const char* message) {
    ssize_t bytes_written = write(sender->write_fd, message, APPLE_MESSAGE);
    if (bytes_written == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }
}

void receiveApple(struct Node* node) {
    char buffer[1024];
    ssize_t bytes_read = read(node->read_fd, buffer, sizeof(buffer));
    if (bytes_read == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    printf("Node %d received the apple with message: %s\n", node->id, buffer);
    node->hasApple = true;
}
