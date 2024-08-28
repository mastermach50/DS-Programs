# Polynomial Addition

#### Aim:-
Write a program to read two polynomials and store them in an array and calculate their sum.


#### Algorithm:-
1. START
1. Create a struct Poly with two attributes int coeff and int exp.
1. Create an array of 100 of this struct and store it as poly.
1. Read each term of the polynomial and store each term as coefficient exponent pairs in the struct Poly in the array poly.
1. Set starta=0 and finisha to number of terms in the first polynomial - 1.
1. Repeat Step 4 to read and store a second polynomial
1. Set startb=finisha+1 and finishb = startb + number of terms of the second polynomial - 1.
1. Set avail=finishb+1.
1. Create a function void attach(int coeff, int exp, int avail) that sets poly[avail].coeff = coeff and poly[avail].exp = exp if avail + 1 < 100.
1.  ```
    while (starta <= finisha && startb <= finishb) {  
        if (poly[starta].exp == poly[startb].exp) {  
            attach(poly[starta].coeff + poly[startb].coeff, poly[starta].exp, avail)  
            increment starta, startb, avail  
        } else if (poly[starta].exp > poly[startb].exp) {  
            attach(poly[starta].coeff, poly[starta].exp, avail)  
            increment starta, avail  
        } else {  
            attach(poly[startb].coeff, poly[startb].exp, avail)  
            increment startb, avail  
        }  
    }  
    ```
1.  ```
    while (starta <= finisha) {  
        attach(poly[starta].coeff, poly[starta].exp, avail)  
        increment starta, avail  
    }  
    ```
1.  ```
    while (startb <= finishb) {  
        attach(poly[startb].coeff, poly[startb].exp, avail)  
        increment startb, avail  
    }  
    ```
1. Set avail_end = avail - 1
1. Loop from i=finishb+1 to avail_end and print the values poly[i].
1. STOP

#### Result:-
Program executed successfully.