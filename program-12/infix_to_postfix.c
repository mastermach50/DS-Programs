// Convert an infix expression to a postfix expression

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#define size 50

// Initialize a stack of characters
char stack[size];
int top = -1;

// Define push and pop functions for the stack
// We are avoiding boundary checking in this case
void push(char e) { stack[++top] = e; }
char pop() { return stack[top--]; }

// Define a function that returns the precedence of the operator passed to it
int precedence(char op) {
    switch (op) {
    case '(':
        return 0;
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

// Define a function to convert the infix expression to a postfix expression
void infixToPostfix(char *infix, char *postfix) {
    int k = 0;

    // Loop through all the characters of the infix expression
    for (int i = 0; i < strlen(infix); i++) {

        char c = infix[i];

        // If the character is a letter or a number insert it into the postfix
        if (isalnum(c)) {
            postfix[k++] = c;

        // If it is an opening bracket push it to stack
        } else if (c == '(') {
            push(c);

        // If the character is a closing bracket pop and insert elements from the
        // stack to postfix until you encounter an opening bracket
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = pop();
            }
            // Pop out the opening bracket
            pop();

        // If the characher is an operator then
        } else {
            // If its precedence is lower than the element at the top of the stack
            // pop out that element and insert it into the postfix expression
            while (top != -1 && precedence(stack[top]) > precedence(c)) {
                postfix[k++] = pop();
            }

            // finally push the operator onto the stack
            push(c);
        }
    }

    // Pop out and insert any remaining elements in the stack into the postfix expression
    while (top != -1) {
        postfix[k++] = pop();
    }

    // Finally insert the string terminating character into the postfix expression
    // to make it into a string
    postfix[k++] = '\0';
}

void main() {
    char infix[size], postfix[size];
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("The postfix expression is:\n%s", postfix);
}