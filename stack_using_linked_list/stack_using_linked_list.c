#include <stdio.h>
#include <stdlib.h>

// Create a struct for each node in the linked list
struct node {
    int data;
    struct node *next;
};

// Define the head, temp, todel and newnode pointers to the struct node
struct node *head = NULL, *temp = NULL, *todel = NULL, *newnode = NULL;

// Define helper functions to identify the condition of the linked list
int isEmpty() { return head == NULL; }


void display() {
    if (isEmpty()) {
        printf("[ Linked List is Empty ]\n");
        return;
    }

    temp = head;
    while (temp->next != NULL) {
        printf("%d-> ", temp->data);
        temp = temp->next;
    }
    printf("%d-> NULL\n", temp->data);
}

void push() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = head;
    printf("Enter element to push to stack: ");
    scanf("%d", &newnode->data);
    head = newnode;
}


void pop() {
    if (isEmpty()) {
        printf("[ Linked List is Empty ]\n");
        return;
    }

    todel = head;
    printf("%d was popped\n", todel->data);
    head = head->next;
    free(todel);
}

void peek() {
    if (isEmpty()) {
        printf("[ Linked List is Empty ]\n");
        return;
    }

    printf("%d is at the top of the stack\n", head->data);
}

void main() {
    while (1) {
        printf("What would you like to do?\n"
               "[1] Display \n"
               "[2] Push to stack\n"
               "[3] Pop from stack\n"
               "[4] Peek\n"
               "[0] Exit\n");
        int ch;
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            display();
            break;
        case 2:
            push();
            break;
        case 3:
            pop();
            break;
        case 4:
            peek();
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