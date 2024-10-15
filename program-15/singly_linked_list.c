#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

int isEmpty() { return (head == NULL); }

int isSingle() { return (head->next == NULL); }

struct node* getLast() {
    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    return temp;
}

struct node* getNewnode() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    
    return newnode;
}

int isValidPos(int pos) {
	struct node *temp = head;
    int len = 0;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }

	return (pos <= len && pos >= 1);
}

void ins_beg() {

    struct node *newnode = getNewnode();

    if (isEmpty()) {
        head = newnode;
    } else {
        newnode->next = head;
        head = newnode;
    }
}

void ins_end() {

    struct node *newnode = getNewnode();

    if (isEmpty()) {
        head = newnode;
    } else {
        struct node *tail = getLast();
        tail->next = newnode;
    }
}

void ins_pos() {

    int pos;
    printf("Enter the position to add: ");
    scanf("%d", &pos);

    struct node *newnode = getNewnode();

    if (!isValidPos(pos)) {
        printf("Invalid position\n");
    } else {
        struct node *temp = head;
        for (int i = 1; i < pos-1; i++) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void del_beg() {

    if (isEmpty()) {
        printf("Linked list empty\n");
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

    if (isEmpty()) {
        printf("Linked list empty\n");
    } else if (isSingle()) {
        free(head);
        head = NULL;
    } else {
        // Traverse the list till we get the second to last node
    	struct node *temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = NULL;
    }
}

void del_pos() {

    // Read the position to delete from
    int pos;
    printf("Enter the position to delete: ");
    scanf("%d", &pos);

    if (!isValidPos(pos)) {
        printf("Invalid position\n");
    } else {
        struct node *temp = head, *to_del;
        for (int i = 1; i < pos-1; i++) {
            temp = temp->next;
        }
        to_del = temp->next;
        temp->next = temp->next->next;
        free(to_del);
    }
}

void display() {
	if (isEmpty()) {
		printf("[ Empty List ]\n");
	} else {
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
            printf("Exiting\n");
            return 0;
        default:
            printf("[ Invalid Choice ]\n");
            break;
        }
    }
}