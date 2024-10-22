// Write a program to implement a stack using an array

#include <stdio.h>
#define size 5

// Define the stack
int stack[size], top = -1;

// Define a function to print all the elements in the stack
void display() {
    if (top < 0) {
        printf("Stack is Empty\n");
        return;
    }

    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

// Define a function to push an element to the stack
void push() {
    if (top >= size) {
        printf("Stack Overflow\n");
        return;
    }

    printf("Enter the element to push to stack: ");
    scanf("%d", &stack[++top]);
}

// Define a function to pop an element from the stack
void pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return;
    }

    printf("%d was popped from the stack\n", stack[top--]);
}

// Define a function to find the  element at the top of the stack
void peek() {
    if (top < 0) {
        printf("Stack is Empty\n");
        return;
    }

    printf("%d is at top of the stack\n", stack[top]);
}

void main() {
    while (1) {
        int ch;
        printf("1. Display\n"
               "2. Push\n"
               "3. Pop\n"
               "4. Peek\n"
               "0. Exit\n");
        printf("> ");
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
            exit(0);
            break;
        default:
            break;
        }
    }
}