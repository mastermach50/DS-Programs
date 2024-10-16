#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

int isEmpty() { return (head == NULL); }

int isSingle() { return (head->next == NULL); }

struct node *getNewnode() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;

    printf("Enter the data: ");
    scanf("%d", &newnode->data);

    return newnode;
}

void push() {

    struct node *newnode = getNewnode();

    if (isEmpty()) {
        head = newnode;
    } else {
        newnode->next = head;
        head = newnode;
    }
}

void pop() {

    if (isEmpty()) {
        printf("[ Stack Underflow ]\n");
    } else if (isSingle()) {
        printf("%d was popped\n", head->data);
        free(head);
        head = NULL;
    } else {
        struct node *old_head;
        old_head = head;
        head = head->next;
        printf("%d was popped\n", old_head->data);
        free(old_head);
    }
}

void display() {
    if (isEmpty()) {
        printf("[ Stack Empty ]\n");
    } else {
        printf("HEAD-> ");
        struct node *temp;
        for (temp = head; temp != NULL; temp = temp->next) {
            printf("%d-> ", temp->data);
        }
        printf("NULL\n");
    }
}

int main() {
    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1.Push to stack\n");
        printf("2.Pop from stack\n");
        printf("3.Display\n");
        printf("4.Exit\n");

        int ch;
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            push();
            break;
        case 2:
            pop();
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