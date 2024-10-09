#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

int getLast() {
    struct node *temp;
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    return temp;
}

int isEmpty() { return (head == NULL); }

int isSingle() { return (head->next == NULL); }

void ins_beg() {

    // Create a newnode
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;

    // Get data from user and insert it into newnode
    int data;
    printf("Enter the data:");
    scanf("%d", &newnode->data);

    if (isEmpty()) {
        head = newnode;
    } else {
        newnode->next = head;
        head = newnode;
    }
}

void ins_end() {

    // Create a newnode
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;

    // Get data from user and insert it into newnode
    int data;
    printf("Enter the data:");
    scanf("%d", &newnode->data);

    if (isEmpty()) {
        head = newnode;
    } else {
        struct node *tail = getLast();
        tail->next = newnode;
    }
}

void ins_pos() {
    struct node *temp, *prev;
    temp = head;

    // Read the position ro insert to
    int pos;
    printf("\nEnter the position to add:");
    scanf("%d", &pos);

    // Find the length of the linked list
    int count = 0;
    while (temp != NULL) {
        temp = temp->next;
        count++;
    }

    // Create a newnode
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;

    // Get data from user and insert it into newnode
    int data;
    printf("Enter the data:");
    scanf("%d", &newnode->data);

    if ((pos > count) || (pos < 1)) {
        printf("Invalid position");
    } else {
        temp = head;
        for (int i = 1; i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = newnode;
        newnode->next = temp;
    }
}

void del_beg() {

    if (isEmpty()) {
        printf("Linked list empty");
    } else if (isSingle()) {
        free(head);
        head = NULL;
    } else {
        struct node *old_head;
        old_head = head;
        head = head->next;
        free(old_head);
    }
}

void del_end() {
    struct node *temp = NULL;
    if (isEmpty()) {
        printf("Linked list empty");
    } else if (isSingle()) {
        free(head);
        head = NULL;
    } else {
        // Traverse the list till we get the second to last node
        temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = NULL;
    }
}

void del_pos() {
    struct node *temp, *prev;
    temp = head;

    // Read the position ro insert to
    int pos;
    printf("\nEnter the position to delete:");
    scanf("%d", &pos);

    // Find the length of the linked list
    int count = 0;
    while (temp != NULL) {
        temp = temp->next;
        count++;
    }

    if ((pos > count) || (pos < 1)) {
        printf("Invalid position");
    } else {
        temp = head;
        for (int i = 1; i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
    }
}

void display() {
    struct node *temp;
    for (temp = head; temp != NULL; temp = temp->next) {
        printf("%d->", *temp);
    }
    printf("NULL");
}

int main() {
    while (1) {
        printf("\n\n*****MENU*****\n");
        printf("1.Insert a node at beginning\n");
        printf("2.Insert a node at end\n");
        printf("3.Insert a node at a given position\n");
        printf("4.Delete the node at the beginning\n");
        printf("5.Delete the node at the end\n");
        printf("6.Delete the node at a given position\n");
        printf("7.Display\n");
        printf("8.Exit\n");

        int ch;
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            ins_beg();
            break;
        case 2:
            ins_end();
            break;
        case 3:
            ins_pos();
            break;
        case 4:
            del_beg();
            break;
        case 5:
            del_end();
            break;
        case 6:
            del_pos();
            break;
        case 7:
            display();
            break;
        case 8:
            printf("***Program Terminated***");
            return 0;
        }
    }
}