// Create a priority queue to make sure that an element is added in order following its priority

#include <stdio.h>
#include <stdlib.h>
#define size 10

// Define an array of struct to store the priority queue
// Also define [temp] to hold a term later 
struct PQ_Term {
    int data;
    int prio;
} pq[size], temp;

int front = -1, rear = -1;

// Remember that priority queue is circular

// In this implementation the larger the value of [prio] the higher the priority of that term
// The highest priority term is dequeued first

// A function to display the priority queue from [front] to [rear]
void display() {
    if (front == -1) {
        printf("Queue Empty\n");
        return;
    }

    int i = front;
    while (i != rear) {
        printf("(p:%d d:%d) ", pq[i].prio, pq[i].data);
        i = (i + 1) % size;
    }
    printf("(p:%d d:%d)\n", pq[i].prio, pq[i].data);
}

// A function that gets a term from the user and inserts it into the priority queue
// and then sorts the queue in reverse based on the priority of the terms
void enqueue() {
    if ((rear + 1) % size == front) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % size;
    }

    printf("Enter the element (priority data): ");
    scanf("%d %d", &pq[rear].prio, &pq[rear].data);

    // Sort the queue in reverse order of priority
    // This only needs to be looped over once because
    // at a time only one term is inserted into the queue
    for (int i = rear; i > front; i--) {
        if (pq[i].prio > pq[i - 1].prio) {
            temp = pq[i - 1];
            pq[i - 1] = pq[i];
            pq[i] = temp;
        }
    }
}

// The dequeue function is not much different than that of a regular queue
void dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }

    printf("(p:%d d:%d) was dequeued\n", pq[front].prio, pq[front].data);
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % size;
    }
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

        switch (ch)
        {
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