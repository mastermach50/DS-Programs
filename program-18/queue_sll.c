#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

int isEmpty() { return (head == NULL); }

int isSingle() { return (head->next == NULL); }

struct node *getLast() {
    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    return temp;
}

struct node *getNewnode() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;

    printf("Enter the data: ");
    scanf("%d", &newnode->data);

    return newnode;
}

void enqueue() {

    struct node *newnode = getNewnode();

    if (isEmpty()) {
        head = newnode;
    } else {
        struct node *tail = getLast();
        tail->next = newnode;
    }
}

void dequeue() {

    if (isEmpty()) {
        printf("[ Queue Underflow ]\n");
    } else if (isSingle()) {
        printf("%d was dequeued\n", head->data);
        free(head);
        head = NULL;
    } else {
        struct node *old_head;
        old_head = head;
        head = head->next;
        printf("%d was dequeued\n", old_head->data);
        free(old_head);
    }
}

void display() {
    if (isEmpty()) {
        printf("[ Empty List ]\n");
    } else {
        struct node *temp;
        printf("HEAD-> ");
        for (temp = head; temp != NULL; temp = temp->next) {
            printf("%d-> ", temp->data);
        }
        printf("NULL\n");
    }
}

int main() {
    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");

        int ch;
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting\n");
            return 0;
        default:
            printf("[ Invalid Choice ]\n");
            break;
        }
    }
}