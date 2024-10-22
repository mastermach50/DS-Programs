// Write a program to read two polynomials and store them in an array and calculate their sum

#include <stdio.h>
#include <stdlib.h>

// The polynomials are stored in an array of structs
// Each struct is a term of the polynomial i.e it holds the value of the coefficient and exponent
struct Term {
    int coeff;
    int exp;
} poly[100];

// A function that reads a polynomial and stores it in [poly] starting from [start] and
// returns the position of the last term of the polynominal stored
int read_poly(int start) {
    int n;
    printf("Enter the number of terms in the polynominal: ");
    scanf("%d", &n);

    for (int i = start; i < n + start; i++) {
        printf("[%d] Enter the term (coefficient exponent) ", i);
        scanf("%d %d", &poly[i].coeff, &poly[i].exp);
    }

    return start + n - 1;
}

// A function to display the terms in [poly] in the position [start] to [end] (both inclusive)
void display_poly(int start, int end) {
    for (int i = start; i < end; i++) {
        printf("%dx^%d + ", poly[i].coeff, poly[i].exp);
    }
    printf("%dx^%d\n", poly[end].coeff, poly[end].exp);
}

// A function that appends a term to the next free position in [poly] if there is space left
void attach(int coeff, int exp, int avail) {
    // if (avail + 1 <= 100) {
        poly[avail].coeff = coeff;
        poly[avail].exp = exp;
    // } else {
    //     printf("[ NO MORE SPACE IN ARRAY ]");
    //     exit(0);
    // }
}

// A function to add the two polynomials ([starta] to [finisha] and [startb] to [finshb])
// and store the result from [res_start] to [res_end] and return [res_end]
int add_poly(int starta, int finisha, int startb, int finishb, int res_start) {

    // Remember that [res_start] is free

    // Compare the exponents of the terms and add the terms to the result as required
    while (starta <= finisha && startb <= finishb) {
        if (poly[starta].exp == poly[startb].exp) {
            attach(poly[starta].coeff + poly[startb].coeff, poly[starta].exp, res_start);
            starta++;
            startb++;
            res_start++;
        } else if (poly[starta].exp > poly[startb].exp) {
            attach(poly[starta].coeff, poly[starta].exp, res_start);
            starta++;
            res_start++;
        } else {
            attach(poly[startb].coeff, poly[startb].exp, res_start);
            startb++;
            res_start++;
        }
    }

    // Insert any remaining terms from the first polynomial into the result
    while (starta <= finisha) {
        attach(poly[starta].coeff, poly[starta].exp, res_start);
        starta++;
        res_start++;
    }

    // Insert any remaining terms from the second polynomial into the result
    while (startb <= finishb) {
        attach(poly[startb].coeff, poly[startb].exp, res_start);
        startb++;
        res_start++;
    }

    // This will be [res_end]
    return res_start - 1;
}

void main() {
    // Read, store and display the first polynomial
    int starta = 0;
    int finisha = read_poly(starta);
    display_poly(starta, finisha);

    printf("\n");

    // Read, store and display the second polynomial
    int startb = finisha + 1;
    int finishb = read_poly(startb);
    display_poly(startb, finishb);

    printf("\n");

    // Add the polynomials
    int res_start = finishb + 1;
    int res_end = add_poly(starta, finisha, startb, finishb, res_start);

    // Display the result
    printf("The sum of the polynomials is:\n");
    display_poly(res_start, res_end);
}