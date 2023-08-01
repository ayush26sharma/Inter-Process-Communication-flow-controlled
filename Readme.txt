eadme file for Assignment-3 (Operating Sytems)


First connect the VS code to ssh host and login with kern.
now add the Assignment_1 folder in the kern folder in VS code.
now open VM Ware and login with kern and then open the forlder Assignment_1


Now we can run all the codes one by one.

For question 2:


In ques 2, we need to first generate 50 strings with their IDs and then send them in packets of 5 strings. 
So first I generated 50 strings of 5 characters each randomly by using the rand() function. 
I created an array if string of 1 characters which contains all the alphabets from a to z, then I used the 
random function to determine which character I shall add to my randomly generated string and then I concatenate
it to a temp variable. In this tempo variable total 5 characters will be conactenated. Now after generating the
strings, I had to group them in number of 5 strings along with their IDs, so I basically converted the ID into string
and then conactenatedit with the randomly generated string corresponding to that particular ID. After concatenating
the ID to string I then concatenated other 4 strings. Now we just need to send these strings from server to client
for this we need them to communicate with each other. We do so by using various methods.


Sockets: Socket programming is a way of connecting two nodes on a network to communicate with each other. 
One socket(node) listens on a particular port at an IP, while other socket reaches out to the other to form a 
connection. Server forms the listener socket while client reaches out to the server.

FIFO: In computing, a named pipe (also known as a FIFO) is one of the methods for inter-process communication. 
It is an extension to the traditional pipe concept on Unix. A FIFO file is a special kind of file on the local 
storage which allows two or more processes to communicate with each other by reading/writing to/from this file.

MSGQUEUE: A message queue is a linked list of messages stored within the kernel and identified by a message 
queue identifier. A new queue is created or an existing queue opened by msgget(). New messages are added to 
the end of a queue by msgsnd(). Every message has a positive long integer type field, a non-negative length,
and the actual data bytes (corresponding to the length), all of which are specified to msgsnd() when the 
message is added to a queue. Messages are fetched from a queue by msgrcv(). 

To run the socket files (p1.c and p2.c) type "make q2_socket" and then type "./p1" first
and then "./p2" on other terminal.

To run the fifo files (fifo1.c and fifo2.c) type "make q2_fifo" and then type "./f1" first
and then "./f2" on other terminal.

To run the msgqueue files (q1.c and q2. c) type "make q2_queue" and then type "./q2" first
and then "./q1" on other terminal.


/* All the definitions are refrenced from geeksforgeeks and orcale. They are not mine. */