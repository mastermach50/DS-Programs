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
int isSingle() { return head->next == NULL; }
int getLength() {
    int len = 0;
    temp = head;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

// Define a function to create a newnode
struct node *getNewnode() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("ERROR: Program out of memory\n");
        exit(-1);
    }
    newnode->next = NULL;
    printf("Enter element: ");
    scanf("%d", &newnode->data);
    return newnode;
}

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

void insBeg() {
    newnode = getNewnode();
    newnode->next = head;
    head = newnode;
}

void insPos() {
    int pos;
    printf("Enter the position to insert the element into: ");
    scanf("%d", &pos);

    if (pos > getLength()+1) {
        printf("[ Invalid Position ]\n");
        return;
    }

    int count = 1;
    temp = head;
    while (count < pos - 1) {
        count++;
        temp = temp->next;
    }

    newnode = getNewnode();
    newnode->next = temp->next;
    temp->next = newnode;
}

void insEnd() {
    if (isEmpty()) {
        head = getNewnode();
        return;
    }

    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    newnode = getNewnode();
    temp->next = newnode;
    newnode->next = NULL;
}

void delBeg() {
    if (isEmpty()) {
        printf("[ Linked List is Empty ]\n");
        return;
    }

    todel = head;
    head = head->next;
    free(todel);
}

void delPos() {
    if (isEmpty()) {
        printf("[ Linked List is Empty ]\n");
        return;
    }

    int pos;
    printf("Enter the position to delete the element at: ");
    scanf("%d", &pos);

    if (pos > getLength()) {
        printf("[ Invalid Position ]\n");
        return;
    }

    int count = 1;
    temp = head;
    while (count < pos - 1) {
        count++;
        temp = temp->next;
    }

    todel = temp->next;
    temp->next = temp->next->next;
    free(todel);
}

void delEnd() {
    if (isEmpty()) {
        printf("[ Linked List is Empty ]\n");
        return;
    }
    if (isSingle()) {
        todel = head;
        head = NULL;
        free(todel);
        return;
    }

    temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    todel = temp->next;
    temp->next = NULL;
    free(todel);
}

void main() {
    while (1) {
        printf("What would you like to do?\n"
               "[1] Display the linked list\n"
               "[2] Insert element at beginning\n"
               "[3] Insert element at position\n"
               "[4] Insert element at end\n"
               "[5] Delete element at beginning\n"
               "[6] Delete element at position\n"
               "[7] Delete element at end\n"
               "[0] Exit\n");
        int ch;
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            display();
            break;
        case 2:
            insBeg();
            break;
        case 3:
            insPos();
            break;
        case 4:
            insEnd();
            break;
        case 5:
            delBeg();
            break;
        case 6:
            delPos();
            break;
        case 7:
            delEnd();
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