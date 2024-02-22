Design Overview and Implementation
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*A. Designing a circular communication system*

1. **Define a ring structure where each node is connected to its direct neighbor**:
   - The `createRing()` function in `node.c` creates a ring structure where each node is connected to its direct neighbor. It iterates through the number of nodes specified and links each node to its next neighbor, forming a circular arrangement.

2. **Ensure one-way write connections between nodes, following the circular arrangement**:
   - While the code doesn't explicitly handle write connections (as it's primarily a data structure implementation), the linked list structure established in `createRing()` ensures a one-way connection from each node to its next neighbor, thus facilitating data transmission in one direction along the circular arrangement.

3. **Establish read connections to allow message reception**:
   - Again, the code doesn't explicitly handle read connections, but the linked list structure allows for traversal from any node to its neighbor, enabling message reception by each node in the ring.

4. **Ensure that the last node in the ring connects back to the first node**:
   - After creating the ring structure in `createRing()`, the code links the last node back to the first node, thus ensuring that the circular arrangement is closed, and the last node connects back to the first node as required.
  
*B. Apple Passing Mechanism*

1. **Introduce the Concept of an "Apple"**:
   - The "apple" represents a message that is passed between nodes in the circular communication system. In our implementation, the apple contains a message payload.

2. **Define Rules for Passing the Apple in a Circular Fashion**:
   - We implement a loop within the `main()` function to iterate through each node in the circular communication system. Each node sends the apple to the next node in the ring.

3. **Implement Logic for Nodes to Receive the Apple**:
   - We define the `receiveApple()` function in `node.c`, which allows a node to receive and process the apple sent by the previous node. This function reads the message from the pipe associated with the node and prints it.

4. **Check if the Message is Intended for Them**:
   - When a node receives the apple, it checks if the message is intended for it. This check is performed by examining the message content.

5. **Process the Apple Accordingly**:
   - If the message is intended for the node, it processes the message by printing it (or performing any other desired action) and sets the message content to 'empty'.
   - If the message is not intended for the node, it forwards the message to the next node in the circular communication system by calling the `sendApple()` function.
  
*C. User Interaction and Control:*

1. **Display Verbose Diagnostic Messages**:
   - The program provides verbose diagnostic messages by printing information about the actions it takes, such as sending a message from one node to another, receiving an apple, and handling any errors that occur.
   - These messages are printed using `printf` statements in various parts of the code, including the `sendApple` and `receiveApple` functions in `node.c`, as well as the `main` function in `main.c`.

2. **Implement Graceful Shutdown Mechanism using Signals**:
   - The program implements a graceful shutdown mechanism using signals, specifically the `SIGINT` signal, which is sent when the user presses `Ctrl+C`.
   - This mechanism is implemented in the `main` function in `main.c`, where a signal handler is set up using the `signal` function, and the handler function is defined to gracefully shut down the program by freeing memory and exiting.

3. **Prompt User for Input**:
   - The program prompts the user for input using `printf` statements in the `main` function in `main.c`.
   - It requests the value of `k` (number of processes/nodes) by printing "Enter the number of nodes in the ring: ".
   - It prompts for a string message to send by printing "Enter the message to send to node [node_id]: ".
   - It prompts for the destination node by printing "Enter the destination node (0-k-1): ".

*D. Implementation Guidelines*

1. **Utilize Process Management and IPC System Calls**:
   - The program utilizes process management and IPC system calls, such as `fork`, `signal`, and `pipe`. These system calls are used to create and manage child processes, establish communication channels between them, and synchronize their actions.

2. **Create and Manage Child Processes**:
   - The program creates and manages child processes based on the provided value of `k` (number of processes/nodes). It uses a loop to create child processes, each representing a node in the circular communication system.

3. **Interact with the User to Send Messages**:
   - The program interacts with the user to send messages by prompting for input in the `main` function in `main.c`. It prompts the user for the message to send and the destination node.

4. **Use Descriptive Variable Names**:
   - The program uses descriptive variable names following the `camelCase` convention. For example, `nodes` represents an array of `struct Node` representing the nodes in the ring, and `destNode` represents the destination node for a message.

5. **Aim for Self-Documenting Code**:
   - The program aims for self-documenting code with minimal inline documentation. It uses meaningful variable and function names, clear logic, and consistent coding style to make the code easy to understand without the need for extensive comments.
