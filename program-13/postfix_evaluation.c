// Write a program to evalusta a posfix expression

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define POSTFIXSIZE 100

// Define the stack
int stack[MAX], top = -1;

// Define a push function for the stack
void push(int e) {
    if (top >= MAX - 1) {
        printf(" Stack Overflow\n");
        exit(0);
    }

    stack[++top] = e;
}

// Define a pop function for the stack
int pop() {
    if (top < 0) {
        printf(" Stack Underflow\n");
        exit(0);
    }

    return stack[top--];
}

// Define a function to evaluate the postfix expression
int evalPostfix(char postfix[]) {
    int val, A, B;

    // Loop through all the characters in the postfix expression
    for (int i = 0; i < strlen(postfix); i++) {
        char ch = postfix[i];

        // If the character is a digit then we can push it to the stack
        // ch - '0' will convert ch from an integer stored as a string to just that integer
        if (isdigit(ch)) {
            push(ch - '0');

        // If the character is an operator then we pop out the last two elements on the stack
        // and perform that specific operation on them
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            B = pop();
            A = pop();

            switch (ch) {
            case '+':
                val = A + B;
                break;
            case '-':
                val = A - B;
                break;
            case '*':
                val = A * B;
                break;
            case '/':
                val = A / B;
                break;
            case '^':
                val = pow(A, B);
                break;
            default:
                printf("Invalid Operator\n");
                exit(0);
                break;
            }

            // We push the value to the stack after performing the operation
            push(val);
        }
    }
    // We can pop out the final value remaining in the stack. That is out answer
    return pop();
}

void main() {
    char postfix[POSTFIXSIZE];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    printf("The result is : %d", evalPostfix(postfix));
}