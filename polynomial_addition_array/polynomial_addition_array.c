#include <stdio.h>
#define MAXSIZE 100

struct term {
    int coeff;
    int exp;
} arr[MAXSIZE];

// Print all the terms from [start] to [end] position
void display_poly(int start, int end) {
    // Print all the terms before the [end] position
    for (int i = start; i < end; i++) {
        printf("%d^%d+", arr[i].coeff, arr[i].exp);
    }
    // Print the term at the [end] position
    printf("%d^%d\n", arr[end].coeff, arr[end].exp);
}

// Read and store terms into [arr] starting from position [start] and
// return the last position in which a term was stored
int read_poly(int start) {
    int n;
    printf("Enter number of terms in the polynomial: ");
    scanf("%d", &n);
    for (int i = start; i < start + n; i++) {
        printf("Enter the term (coefficient exponent): ");
        scanf("%d %d", &arr[i].coeff, &arr[i].exp);
    }

    return start + n - 1;
}

// Attach a term at [res] if the array [arr] is not full
void attach_poly(int res, int coeff, int exp) {
    if (res >= MAXSIZE - 1) {
        printf("ERROR: Array out of space");
        exit(-1);
    } else {
        arr[res].coeff = coeff;
        arr[res].exp = exp;
    }
}

// Add the polynomials at the given positions and start storing the result
// to the position [res] and return the final position in which a term of the
// result polynomial was stored
int add_poly(int startA, int endA, int startB, int endB, int res) {
    while (startA <= endA && startB <= endB) {
        // Add the polynomials together and store the result
        if (arr[startA].exp == arr[startB].exp) {
            attach_poly(res, arr[startA].coeff + arr[startB].coeff, arr[startA].exp);
            res++;
            startA++;
            startB++;
        } else if (arr[startA].exp > arr[startB].exp) {
            attach_poly(res, arr[startA].coeff, arr[startA].exp);
            res++;
            startA++;
        } else {
            attach_poly(res, arr[startB].coeff, arr[startB].exp);
            res++;
            startB++;
        }
    }

    // Insert any remaining terms in the two polynomials
    while (startA <= endA) {
        attach_poly(res, arr[startA].coeff, arr[startA].exp);
        res++;
        startA++;
    }
    while (startB <= endB) {
        attach_poly(res, arr[startB].coeff, arr[startB].exp);
        res++;
        startB++;
    }

    return res - 1;
}

void main() {
    // Read and store the first polynomial
    printf("Enter the first polynomial\n");
    int startA = 0;
    int endA = read_poly(startA);
    display_poly(startA, endA);
    printf("\n");

    // Read and store the second polynomial
    printf("Enter the second polynomial\n");
    int startB = endA + 1;
    int endB = read_poly(startB);
    display_poly(startB, endB);
    printf("\n");

    // Add the two polynomials and dispaly the result
    int res = endB + 1;
    int resend = add_poly(startA, endA, startB, endB, res);
    display_poly(res, resend);
}