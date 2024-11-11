# [Program-7] Postfix Evaluation
## Aim:-
Write a program to evaluate a postfix expression.

## Algorithm:-
1. START
2. Define a stack to store integers.
3. Get a postfix expression from the user.
4. Loop over each character in the postfix expression and follow steps 5 to 6.
5. If the character is a digit then push it to the stack.
6. If the character is an operator then pop out two elements from the stack and perform that specific operation between them. Then push the result of that operation onto the stack.
7. Finally pop out the element in the stack, that will be the final result.
8. STOP

## Result:-
A postfix expression was evaluated.