// Write a program to add two sparse matrices.

#include <stdio.h>

// A function to print a sparse matrix representation.
void print_matrix(int smr[100][3]) {
    for (int i = 0; i < smr[0][2] + 1; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", smr[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

// A function to read a sparse matrix from the user and store it's
// representation in [smr].
void read_matrix(int smr[100][3], int r, int c) {
    int k = 1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int val;
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &val);

            if (val != 0) {
                smr[k][0] = i;
                smr[k][1] = j;
                smr[k][2] = val;
                k++;
            }
        }
    }

    // Set the first row of the sparse matrix representation.
    smr[0][0] = r;
    smr[0][1] = c;
    smr[0][2] = k - 1;

    print_matrix(smr);
}

// A function that adds two sparse matrix representation [m1], [m2]
// and stores the result in [res].
void add_matrix(int m1[100][3], int m2[100][3], int res[100][3]) {

    // Each of these is to track the next row to be read in [m1] and [m2]
    // and the next row to be written to in [res].
    int k = 1, k1 = 1, k2 = 1;

    // Loop until all rows are read in either [m1] or [m2].
    // In different cases different things will happen.
    while (k1 <= m1[0][2] && k2 <= m2[0][2]) {
        // Simply add and insert the value if row and column values are equal.
        if (m1[k1][0] == m2[k2][0] && m1[k1][1] == m2[k2][1]) {
            res[k][0] = m1[k1][0];
            res[k][1] = m1[k1][1];
            res[k][2] = m1[k1][2] + m2[k2][2];
            k++;
            k1++;
            k2++;
        // Insert the value with the lower row value if the row values are not equal.
        } else if (m1[k1][0] < m2[k2][0]) {
            res[k][0] = m1[k1][0];
            res[k][1] = m1[k1][1];
            res[k][2] = m1[k1][2];
            k++;
            k1++;
        // Insert the value with the lower row value if the row values are not equal.
        } else if (m1[k1][0] > m2[k2][0]) {
            res[k][0] = m2[k2][0];
            res[k][1] = m2[k2][1];
            res[k][2] = m2[k2][2];
            k++;
            k2++;
        // This else is triggered if the row values were equal but the column values were not.
        } else {
            // Insert the value with the lower column value.
            if (m1[k1][1] < m2[k2][1]) {
                res[k][0] = m1[k1][0];
                res[k][1] = m1[k1][1];
                res[k][2] = m1[k1][2];
                k++;
                k1++;
            // Insert the value with the lower column value.
            } else if (m1[k1][1] > m2[k2][1]) {
                res[k][0] = m2[k2][0];
                res[k][1] = m2[k2][1];
                res[k][2] = m2[k2][2];
                k++;
                k2++;
            }
        }
    }
    // Insert any remaing rows in the sparse matrix representaion.
    while (k1 <= m1[0][2]) {
        res[k][0] = m1[k1][0];
        res[k][1] = m1[k1][1];
        res[k][2] = m1[k1][2];
        k++;
        k1++;
    }
    while (k2 <= m2[0][2]) {
        res[k][0] = m2[k2][0];
        res[k][1] = m2[k2][1];
        res[k][2] = m2[k2][2];
        k++;
        k2++;
    }

    // Set the first row of [res].
    res[0][0] = m1[0][0];
    res[0][1] = m1[0][1];
    res[0][2] = k - 1;
}

void main() {

    int r, c;
    // Create the two matrices and another matrix to store their sum.
    int m1[100][3];
    int m2[100][3];
    int res[100][3];

    // Get the size of the matrices.
    printf("Enter the size of the matrices (rows columns): ");
    scanf("%d %d", &r, &c);

    // Read the first sparse matrix from the user.
    printf("Enter the first matrix\n");
    read_matrix(m1, r, c);

    // Read the second sparse matrix from the user.
    printf("Enter the second matrix\n");
    read_matrix(m2, r, c);

    // Add the two matrices and print the result.
    add_matrix(m1, m2, res);
    printf("The sum of the two matrices is\n");
    print_matrix(res);
}