# Inter-Process-Communication-flow-controlled
Three variants of the program P1 and program P2 (one each for communicating using Unix domain sockets, FIFOs and message passing queues respective) were created for the interprocess communication.

The reliability of each interprocess communication mechanism was not assumed unless guaranteed by the mechanism itself. Proper error handling and synchronization mechanisms were implemented to ensure reliable communication.

## (i) Unix domain sockets:
Socket programming enables two nodes on a network to establish communication with each other. One node acts as a server and listens on a specific port at an IP address, while the other node acts as a client and connects to the server to form a connection.

## (ii) FIFOs:
FIFO, also known as a named pipe, facilitates inter-process communication. It extends the traditional pipe concept on Unix systems. A FIFO file is a special file on the local storage that allows multiple processes to communicate by reading from and writing to this file.

## (iii) Message passing queues:
Message queues consist of a linked list of messages stored within the kernel and are identified by a message queue identifier. New queues are created or existing ones are opened using the msgget() function. Messages can be added to the end of a queue with the msgsnd() function, which specifies the type, length, and data of the message. Messages are retrieved from a queue using the msgrcv() function.

To implement the above mechanisms, the following steps were taken for each technique:

- Program P1 generated an array of 50 random strings of fixed length.
- P1 created a Unix domain socket/FIFO/Message Queue and established a connection to P2.
- P1 divided the array of strings into groups of five consecutive elements.
- For each group, P1 sent the strings and their corresponding IDs (indices) to P2 through the socket/FIFO.Message Queue.
- P2 accepted the received strings and their IDs from P1 through the socket/FIFO.Message Queue.
- P2 determined the highest ID received and sent it back to P1 to acknowledge the strings received.
- P2 printed the IDs and strings on the console.
- On receiving the acknowledged packet, P1 sent the next five strings starting from the successor of the acknowledged ID through the socket/FIFO.Message Queue.


Note: 
