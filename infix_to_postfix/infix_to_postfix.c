#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define MAX 50

// define a stack the operators
char stack[MAX];
int top = -1;

// Define two character arrays for the infix and postfix expression
char infix[MAX], postfix[MAX];

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
void infixToPostfix() {
    // [k] is used to track the items in the postfix expression
    int k = 0;

    // Loop through all the characters of the infix expression
    for (int i = 0; i < strlen(infix); i++) {

        // Get the character
        char c = infix[i];

        // If the character is a letter or a number then
        // directly insert it into the postfix expression
        if (isalnum(c)) {
            postfix[k++] = c;

        // If it is an opening bracket push it to stack
        } else if (c == '(') {
            stack[++top] = c;

        // If the character is a closing bracket then pop and insert elements from the
        // stack into the postfix expression until you encounter an opening bracket
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = stack[top--];
            }
            // Pop out the opening bracket
            stack[top--];

        // If the characher is an operator then
        } else {
            // If its precedence is lower than the element at the top of the stack
            // pop out that element and insert it into the postfix expression
            while (top != -1 && precedence(stack[top]) > precedence(c)) {
                postfix[k++] = stack[top--];
            }

            // finally push the operator onto the stack
            stack[++top] = c;
        }
    }

    // Pop out and insert any remaining elements in the stack into the postfix expression
    while (top != -1) {
        postfix[k++] = stack[top--];
    }

    // Finally insert the string terminating character into the postfix expression
    // to make it into a string
    postfix[k++] = '\0';
}

void main() {
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    infixToPostfix();
    printf("The postfix expression is:\n%s", postfix);
}