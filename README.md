# Inter-Process-Communication-flow-controlled
Three variants of the program P1 and program P2 (one each for communicating using Unix domain sockets, FIFOs and message passing queues respective) were created for the interprocess communication.

The reliability of each interprocess communication mechanism was not assumed unless guaranteed by the mechanism itself. Proper error handling and synchronization mechanisms were implemented to ensure reliable communication.


To implement the abovemechanisms, the following steps were taken for each technique:

## (i) Unix domain sockets:

- Program P1 generated an array of 50 random strings of fixed length.
- P1 created a Unix domain socket and established a connection to P2.
- P1 divided the array of strings into groups of five consecutive elements.
- For each group, P1 sent the strings and their corresponding IDs (indices) to P2 through the socket.
- P2 accepted the received strings and their IDs from P1 through the socket.
- P2 determined the highest ID received and sent it back to P1 to acknowledge the strings received.
- P2 printed the IDs and strings on the console.
- On receiving the acknowledged packet, P1 sent the next five strings starting from the successor of the acknowledged ID through the socket.

## (ii) FIFOs:

- Program P1 generated an array of 50 random strings of fixed length.
- P1 created a FIFO (named pipe) for communication with P2.
- P2 also created the same FIFO to establish a bidirectional communication channel.
- P1 divided the array of strings into groups of five consecutive elements.
- For each group, P1 wrote the strings and their corresponding IDs to the FIFO.
- P2 read the strings and their IDs from the FIFO.
- P2 determined the highest ID received and sent it back to P1 to acknowledge the strings received.
- P2 printed the IDs and strings on the console.
- On receiving the acknowledged packet, P1 sent the next five strings starting from the successor of the acknowledged ID through the FIFO.

## (iii) Message passing queues:

- Program P1 generated an array of 50 random strings of fixed length.
- P1 created a message queue to communicate with P2.
- P1 divided the array of strings into groups of five consecutive elements.
- For each group, P1 sent the strings and their corresponding IDs to P2 via the message queue.
- P2 received the strings and their IDs from P1 through the message queue.
- P2 determined the highest ID received and sent it back to P1 to acknowledge the strings received.
- P2 printed the IDs and strings on the console.
- On receiving the acknowledged packet, P1 sent the next five strings starting from the successor of the acknowledged ID through the message queue.

Note: 
