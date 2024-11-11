# [Program-6] Conversion Of Infix To Postfix Expression
## Aim:-
Write a program to convert an infix expression to a postfix expression.

## Algorithm:-
1. START
2. Define MAX to 100
3. Create three character arrays `char infix[MAX]`, `char postfix[MAX]`, `char stack[MAX]` to store the infix expression, postfix expression and a stack of characters respectively.
4. Get the infix expression from the user and store it in `infix`.
5. Loop over the characters in infix and for each character follow steps 6 to 9
6. If the character is a letter or a number push it to `postfix`.
7. If the character is an opening bracket push it to `stack`.
8. If the character is a closing bracket then pop elements one by one from `stack` and push them to `postfix` until an opening bracket is encountered. Pop out the opening bracket.
9. If the character is an operator then pop out and push characters from `stack` into `postfix` until the character at the top of the stack has a lower precedence than the current character.
10. Finally insert a `\0` to `postfix` to make it into a string and display it.
11. STOP

## Result:-
An infix expression was converted into postfix expression.