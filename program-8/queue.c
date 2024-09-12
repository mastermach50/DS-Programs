#include <stdio.h>

#define max 4

int queue[max], front = -1, rear = -1;

void enqueue() {
    if (rear == max - 1) {
        printf("Overflow\n");
    } else if (front == -1 && rear == -1) {
        printf("Enter element to enquque: ");
        scanf("%d", &queue[++rear]);
        front = rear;
    } else {
        printf("Enter element to enquque: ");
        scanf("%d", &queue[++rear]);
    }
}

void dequeue() {
    if (front == -1) {
        printf("Underflow\n");
    } else if (front == rear) {
        printf("%d was dequeued\n", queue[front]);
        front = -1;
        rear = -1;
    } else {
        printf("%d was dequeued\n", queue[++front - 1]);
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else {
        for (int i = front; i < rear + 1; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    while (1) {
        int ch;
        printf("What would you like to do?\n"
               "\t[0] Display the queue\n"
               "\t[1] Enqueue\n"
               "\t[2] Dequeue\n"
               "\t[3] Exit\n"
               "Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 0:
            display();
            break;
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            return 0;
        default:
            printf("[ Enter a valid choice ]\n");
        }
        printf("\n");
    }
}
