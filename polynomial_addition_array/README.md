# [Program-1] Polynomial Addition Using Array
## Aim:-
Write a program to add two polynomials using an array

## Algorithm:-
1. START
2. Create an array called arr of struct of maxsize 100, each struct contains two integers coeff and exp.
3. Read two polynomials from the user and store them in arr.
4. Let the start and end positions of the first polynomial in the array be startA and endA respectively and that of the secon polynomial be startB and endB.
5. Let res = startB + 1
6. While startA <= endA and startB <= endB follow steps 7 to 9
7. If the exponents of the terms at startA and endA are equal then add the coefficients of the terms at that positions and store them at arr[res] with the exponent at any of the terms. Increment startA, startB and res.
8. If the exponent of the term at startA is greater than that at startB then store the term at startA at arr[res]. Increment startA and res.
9. If the exponent of the term at startB is greater than that at startA then store the term at startB at arr[res]. Increment startB and res.
10. Insert any remaing terms in the two polynomials at the end of the array
11. Display the resulting polynomial.
12. STOP
    
## Result:-
Two polynomials were added using an array.