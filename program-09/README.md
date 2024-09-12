# Circular Queue

#### Aim:-
Write a program to implement a circular queue.

#### Algorithm:-
1. START
1. Declare an constant MAX and set it to 5.
1. In global scope declare an array queue[MAX], front=-1 and rear=-1.
1. Define an enqueue function using steps 5 to 8.
1. Get the element to enqueue and store it as data.
1. If (rear+1)%MAX==front display that the queue is full , else goto step 7.
1. If front and rear are equal to -1 set front and rear to 0 and set queue[rear]=data, else goto step 8.
1. Set rear=(rear+1)%MAX and set queue[rear]=data. 
1. Define a dequeue function using steps 10 to 12.
1. If front and rear are equal to -1 display that the queue is empty, else goto step 11.
1. If front==rear display that queue[front] was removed and set front and rear to -1, else goto step 12.
1. Display that queue[front] was removed, set front=(front+1)%MAX.
1. Define a display function using steps 14 to 16.
1. If front and rear are equal to -1 display that the queue is empty, else goto step 15.
1. Set a variable i to front and and loop until i is rear. In each iterartion of the loop print queue[i] and set i=(i+1)%MAX.
1. Print queue[rear].
1. In the main function get input from the user on what to do and execute the functions as needed.
1. STOP


#### Result:-
The program executed successfully.