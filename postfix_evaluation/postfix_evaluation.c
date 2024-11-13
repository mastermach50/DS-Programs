#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Define the stack to store the numbers
int stack[MAX], top = -1;

// Define simple push and pop functions for the stack
void push(int e) { stack[++top] = e; }
int  pop()       { return stack[top--]; }

// Define a function to evaluate the postfix expression
int evalPostfix(char postfix[]) {
    int val, A, B;

    // Loop through all the characters in the postfix expression
    for (int i = 0; i < strlen(postfix); i++) {
        // Get each character
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
    // Define an array for the postfix expression
    char postfix[MAX];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    printf("The result is : %d", evalPostfix(postfix));
}