all: q2_fifo q2_queue q2_socket

q2_fifo:
	gcc fifo1.c -o f1
	gcc fifo2.c -o f2

q2_queue:
	gcc q1.c -o q1
	gcc q2.c -o q2

q2_socket:
	gcc p1.c -o p1
	gcc p2.c -o p2