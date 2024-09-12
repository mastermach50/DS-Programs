// Write a program to implement a double ended queue.

#include<stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue_front(){
	int data;
	printf("Enter the element to enqueue: ");
	scanf("%d", &data);
	
	if ((front==0 && rear==MAX-1) || (front==rear+1) ){
		printf("Queue is full");
	} else if (front==-1 && rear ==-1) {
		front = rear = 0;
		queue[front] = data;
	} else if (front == 0) {
		front = MAX-1;
		queue[front] = data;
	} else {
		front--;
		queue[front] = data;
	}
}

void enqueue_rear(){
	int data;
	printf("Enter the element to enqueue: ");
	scanf("%d", &data);
	
	if ((front==0 && rear==MAX-1) || (front==rear+1)) {
		printf("Queue is full");
	} else if (front==-1 && rear ==-1) {
		front = rear = 0;
		queue[rear] = data;
	} else if (rear == MAX-1) {
		rear = 0;
		queue[rear] = data;
	} else {
		rear++;
		queue[rear] = data;
	}
}

void dequeue_front(){
	if (front==-1 && rear ==-1) {
		printf("Queue is empty");
	} else if (front == rear) {
		printf("%d was removed" ,queue[front]);
		front = rear = -1;
	} else if (front == MAX-1) {
		printf("%d was removed" ,queue[front]);
		front = 0;
	} else {
		printf("%d was removed" ,queue[front]);
		front++;
	}
}

void dequeue_rear(){
	if (front==-1 && rear ==-1) {
		printf("Queue is empty");
	} else if (front == rear) {
		printf("%d was removed" ,queue[rear]);
		front = rear = -1;
	} else if (rear == 0) {
		printf("%d was removed" ,queue[rear]);
		rear = MAX-1;
	} else {
		printf("%d was removed" ,queue[rear]);
		rear--;
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
    [2] Enqueue Front\n\
    [3] Enqueue Rear\n\
    [4] Dequeue Front\n\
    [5] Dequeue Rear\n\
    [6] Exit\n");
        printf("Enter your choice[1/2/3/4/5/6]: ");

        // Get the user's choice
        int ch;
        scanf("%d", &ch);
        
        // Execute the user's choice
        switch (ch) {
        case 1:
            display();
            break;
        case 2:
            enqueue_front();
            break;
        case 3:
            enqueue_rear();
            break;
        case 4:
            dequeue_front();
            break;
        case 5:
            dequeue_rear();
            break;
        case 6:
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
