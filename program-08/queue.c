// Write a program to implement a queue using an array

#include <stdio.h>
#define size 5

// Define a queue
int queue[size], front = -1, rear = -1;

// Define an enqueue function
void enqueue() {
    if (rear == size - 1) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear++;
    }

    printf("Enter the element to enqueue: ");
    scanf("%d", &queue[rear]);
}

// Define a dequeue function
void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue Underflow\n");
        return;
    }

    printf("%d was dequeue\n", queue[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

// Define a display function
void display() {
    if (front == -1 && rear == -1) {
        printf("Queue Empty\n");
        return;
    }

    for (int i = front; i < rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("%d\n", queue[rear]);
}

void main() {
    while (1) {
        int ch;
        printf("1. Display\n"
               "2. Enqueue\n"
               "3. Dequeue\n"
               "0. Exit\n");
        printf("> ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            display();
            break;
        case 2:
            enqueue();
            break;
        case 3:
            dequeue();
            break;
        case 0:
            exit(0);
            break;
        default:
            break;
        }
    }
}