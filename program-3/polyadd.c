// Write a program to read two polynomials and store them in an array and calculate their sum.

#include <stdio.h>

// The polynomials and their sum will be stored in the same array of structs called [poly].
// Each struct contains a term of the polynomial as [coeff]icient and [exp]ponent pairs.
struct Poly {
    int coeff;
    int exp;
} poly[100];

// A function to read a polynomial from the user
// and insert it into the array starting from the position given as an argument [start].
// The ending position after inserting the polynomial is returned.
int read_poly(int start) {
    int n_terms;
    printf("Enter number of terms: ");
    scanf("%d", &n_terms);

    for (int i = start; i < start + n_terms; i++) {
        printf("Enter term [%d] (coeff exp): ", i + 1);
        scanf("%d %d", &poly[i].coeff, &poly[i].exp);
    }

    return start + n_terms - 1;
}

// A function to display the values in the array from the position given as an argument [start]
// to the position given as the second argument [finish] (both inclusive).
void print_poly(int start, int finish) {
    for (int i = start; i < finish + 1; i++) {
        printf("%dx^%d ", poly[i].coeff, poly[i].exp);
    }
    printf("\n\n");
}

// A function that inserts the [coeff]-[exp] pair given to it into the array
// at position [avail] only if the array is not full.
void attach(int coeff, int exp, int avail) {
    if (avail + 1 <= 100) {
        poly[avail].coeff = coeff;
        poly[avail].exp = exp;
    } else {
        printf("ERROR No more space in array");
    }
}

// A function that loops over both the polynomials in the array [poly] simultaneously and
// a) adds the coefficients and inserts it into [poly] if the exponents are the same
// b) inserts the term with the lower coefficient into [poly] if the exponents are not the same
int add_poly(int starta, int finisha, int startb, int finishb, int avail) {
    while (starta <= finisha && startb <= finishb) {
        if (poly[starta].exp == poly[startb].exp) {
            attach(poly[starta].coeff + poly[startb].coeff, poly[starta].exp, avail);
            starta++;
            startb++;
            avail++;
        } else if (poly[starta].exp > poly[startb].exp) {
            attach(poly[starta].coeff, poly[starta].exp, avail);
            starta++;
            avail++;
        } else {
            attach(poly[startb].coeff, poly[startb].exp, avail);
            startb++;
            avail++;
        }
    }

    // Inserts any remaining terms of the polynomials at the end
    while (starta <= finisha) {
        attach(poly[starta].coeff, poly[starta].exp, avail);
        starta++;
        avail++;
    }
    while (startb <= finishb) {
        attach(poly[startb].coeff, poly[startb].exp, avail);
        startb++;
        avail++;
    }

    return avail - 1;
}

void main() {

    // Read the first polynomial and display it
    printf("Enter the first polynomial\n");
    int starta = 0;
    int finisha = read_poly(starta);
    print_poly(starta, finisha);

    // Read the second polynomial and display it
    printf("Enter the second polynomial\n");
    int startb = finisha + 1;
    int finishb = read_poly(startb);
    print_poly(startb, finishb);

    // Find the sum of the polynomials and display it
    printf("The sum of the polynomials is\n");
    int avail = finishb + 1;
    int avail_end = add_poly(starta, finisha, startb, finishb, avail);
    print_poly(avail, avail_end);
}