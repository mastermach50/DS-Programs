#include <stdio.h>

#define MAX 5

// Declare the stack and [top]
int stack[MAX], top = -1;

void display() {
    if (top == -1) {
        printf("[ Stack is Empty ]\n");
        return;
    }
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void push() {
    if (top >= MAX-1) {
        printf("[ Stack Overflow ]\n");
        return;
    }
    printf("Enter the element to push to stack: ");
    scanf("%d", &stack[++top]);
}

void pop() {
    if (top == -1) {
        printf("[ Stack Underflow ]\n");
        return;
    }
    printf("%d was popped\n", stack[top--]);
}

void peek() {
    if (top == -1) {
        printf("[ Stack is Empty ]\n");
        return;
    }
    printf("%d is at the top\n", stack[top]);
}

void main() {
    while (1) {
        printf("What would you like to do?\n"
               "[1] Display the stack\n"
               "[2] Push to the stack\n"
               "[3] Pop from the stack\n"
               "[4] Peek the stack\n"
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