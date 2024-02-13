Design Overview 
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
