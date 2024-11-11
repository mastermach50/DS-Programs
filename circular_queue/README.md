# [Program-9] Circular Queue
## Aim:-
Write a program to implement a circular queue.

## Algorithm:-
1. START
2. Define MAX as 5.
3. Declare a queue `int queue[MAX]` and declare front and rear as -1.
4. Define a function `display()`, consider steps 5 to 7.
5. If front==rear==-1 display that the queue is empty.
6. Otherwise loop using the for loop `for (int i=front;i!=rear;i=(i+1)%MAX)` and disply each `queue[i]`.
7. Finally display the element at `queue[rear]`.
8. Define a function `enqueue()`, consider steps 9 to 12.
9. If `(rear+1)%MAX == front` display that the queue is full and return.
10. If front and rear are -1 set `front=rear=0`.
11. Otherwise set `rear=(rear+1)%MAX`.
12. Insert the element to `queue[rear]`.
13. Define a function `dequeue()`, consider steps 14 to 17.
14. If front and rear are -1 display that the queue is empty and return.
15. Display that `queue[front]` was dequeued.
16. If front and rear are equal then set `front=rear=-1`.
17. Otherwise set `front=(front+1)%MAX`.
18. Use a menu to allow the user to call the functions as needed.
19. STOP

## Results:-
A queue was implemented using an array.