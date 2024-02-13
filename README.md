# OneBadApple
A circular communication system where k processes will form a ring where each node is only connected to its direct neighbor

1. Design of Circular Communication System:
- Define a ring structure where each node is connected to its direct neighbor.
- Ensure one-way write connections between nodes, following the circular arrangement.
- Establish read connections to allow message reception.
- Ensure that the last node in the ring connects back to the first node.
- Apple Passing Mechanism:

2. Introduce the concept of an "apple" to synchronize the system.
- Define rules for passing the apple in a circular fashion.
- Implement logic for nodes to receive the apple, check if the message is intended for them, and process accordingly.
- If the message is intended for a node, copy the message and set the header to 'empty'.
- If the message is not intended for a node, forward it to the next node.

3. User Interaction and Control:
- Display verbose diagnostic messages to aid in understanding system behavior.
- Implement graceful shutdown mechanism using signals when the user presses Control-C.
- Prompt the user for input:
- Request the value of k (number of processes/nodes).
- Prompt for a string message to send and the destination node.
  
4. Implementation Guidelines:
- Utilize process management and IPC (Inter-Process Communication) system calls, such as fork, signal, pipe, etc.
- The parent process should create and manage child processes based on the provided value of k.
- After spawning processes, the parent process should interact with the user to send messages.
- Use descriptive variable names following the camelCase convention.
- Aim for self-documenting code with minimal inline documentation.
- Avoid using the sleep system call or any "no op loops" for efficiency.

5. Additional Notes:
Ensure the system can handle messages consisting of more than one word.
Prohibit the use of sleep system calls or any "no op loops" to maintain efficiency.
After the apple completes its traversal through the ring, prompt the parent process for the next message to send, including the destination node.
