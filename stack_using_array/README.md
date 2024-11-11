# [Program-5] Stack Implementation Using Array
## Aim:-
Write a program to implement a stack using an array.

## Algorithm:-
1. START
2. Define MAX as 5 and declare `int stack[MAX]` and `int top=-1`.
3. Declare a function `display()`, consider steps 4 to 5.
4. If `top == -1` display that the stack is empty.
5. Otherwise loop from i=0 to i<=top and print stack[i].
6. Declare a function `push()`, consider steps 7 to 8.
7. If `top >= MAX-1` display that the stack is full and return.
8. Otherwise get an element from the user, increment top and set that element as `stack[top]`.
9. Declare a function `pop()`, consider steps 10 to 11.
10. If `top == -1` display that the stack is empty and return.
11. Otherwise display that `stach[top]` was popped and decrement top.
12. Declare a function `pop()`, consider steps 13 to 14.
13. If `top == -1` display that the stack is empty and return.
14. Otherwise display that `stach[top]` is at the top.
15. Use a menu to allow the user to call these functions as needed.
16. STOP

## Result:-
A stack was implemented using as array.
