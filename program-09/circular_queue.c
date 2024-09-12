// Write a program to implement a circular queue.

#include <stdio.h>
#define MAX 5

// Declare the queue and other global variables
int queue[MAX];
int front = -1;
int rear = -1;

void enqueue() {
    // Get the element to enqueue
    int data;
    printf("Enter the element to enqueue: ");
    scanf("%d", &data);

    // When the queue is full
    if ((rear + 1) % MAX == front) {
        printf("Queue is full\n");
    }
    // When the queue is empty
    else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = data;
    }
    // Every other case
    else {
        rear = (rear + 1) % MAX;
        queue[rear] = data;
    }
}

void dequeue() {
    // When the queue is empty
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    }
    // When the queue has a single element
    else if (front == rear) {
        printf("%d was dequeued", queue[front]);
        front = rear = -1;
    }
    // Every other case
    else {
        printf("%d was dequeued", queue[front]);
        front = (front + 1) % MAX;
    }
}

void display() {
    // When the queue is empty
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    }
    // Every other case
    else {
        int i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", queue[rear]);
    }
}

int main() {
    // A menu for the user
    while (1) {
        printf("What would you like to do?\n\
    [1] Display the queue\n\
    [2] Enqueue\n\
    [3] Dequeue\n\
    [4] Exit\n");
        printf("Enter your choice[1/2/3/4]: ");

        // Get the user's choice
        int ch;
        scanf("%d", &ch);
        
        // Execute the user's choice
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
        case 4:
            printf("Exiting\n");
            return 0;
            break;
        default:
            printf("[ INVALID CHOICE ]");
            break;
        }
        printf("\n");
    }
}
