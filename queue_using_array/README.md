# [Program-8] Queue Implementation Using Array
## Aim:-
Write a program to implement a queue using an array.

## Algorithm:-
1. START
2. Define MAX as 5.
3. Declare a queue `int queue[MAX]` and declare front and rear as -1.
4. Define a function `display()`, consider steps 5 to 6.
5. If front==rear==-1 display that the queue is empty.
6. Otherwise loop from i=front to i=rear and disply each `queue[i]`.
7. Define a function `enqueue()`, consider steps 8 to 11.
8. If `rear >= MAX-1` display that the queue is full and return.
9. If front and rear are -1 set `front=rear=0`.
10. Otherwise increment rear.
11. Insert the element to `queue[rear]`.
12. Define a function `dequeue()`, consider steps 13 to 16.
13. If front and rear are -1 display that the queue is empty and return.
14. Display that `queue[front]` was dequeued.
15. If front and rear are equal then set `front=rear=-1`.
16. Otherwise increment front.
17. Use a menu to allow the user to call the functions as needed.
18. STOP

## Results:-
A queue was implemented using an array.