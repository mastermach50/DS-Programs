#include <stdio.h>

#define MAX 5

// Declare the queue and [front] and [rear]
int queue[MAX], front = -1, rear = -1;

void display() {
    if (front == -1 && rear == -1) {
        printf("[ Queue is Empty ]\n");
        return;
    }
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void enqueue() {
    if (rear >= MAX - 1) {
        printf("[ Queue Overflow ]\n");
        return;
    }

    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear++;
    }

    printf("Enter the element to push to queue: ");
    scanf("%d", &queue[rear]);
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("[ Queue Underflow ]\n");
        return;
    }
    
    printf("%d was popped\n", queue[front]);
    
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

void main() {
    while (1) {
        printf("What would you like to do?\n"
               "[1] Display the queue\n"
               "[2] Enqueue item\n"
               "[3] Dequeue\n"
               "[0] Exit\n");
        int ch;
        printf("Enter your choice: ");
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
            printf("Exiting\n");
            return;
            break;
        default:
            printf("[ INVALID CHOICE ]\n");
            break;
        }

        printf("\n");
    }
}