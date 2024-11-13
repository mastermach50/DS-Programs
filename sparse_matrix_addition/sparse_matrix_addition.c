#include <stdio.h>

// Print any matrix of size [r] x [c]
void print_mat(int r, int c, int mat[r][c]) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Read a sparse matrix representation from the user with the size spqcified
void read_smatr(int smatr[100][3], int r, int c) {
    // Get each element of the sparse matrix and create its representation
    int k = 1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int e;
            printf("Enter the element[%d][%d]: ", i, j);
            scanf("%d", &e);

            // If the element is not 0 then make an entry for it in the sparse matrix representation
            if (e != 0) {
                smatr[k][0] = i;
                smatr[k][1] = j;
                smatr[k][2] = e;
                k++;
            }
        }
    }

    // Fill in the header of the sparse matrix representation
    smatr[0][0] = r;
    smatr[0][1] = c;
    smatr[0][2] = k - 1;
}

void add_smatr(int smatrA[100][3], int smatrB[100][3], int smatrR[100][3]) {
    // Set variabels for the number of terms in each of the sparse matrix representations
    int k1 = 1, k2 = 1, k3 = 1;

    while (k1 <= smatrA[0][2] && k2 <= smatrB[0][2]) {
        if (smatrA[k1][0] == smatrB[k2][0]) {
            if (smatrA[k1][1] == smatrB[k2][1]) {
                smatrR[k3][0] = smatrA[k1][0];
                smatrR[k3][1] = smatrA[k1][1];
                smatrR[k3][2] = smatrA[k1][2] + smatrB[k2][2];
                k1++;
                k2++;
                k3++;
            } else if (smatrA[k1][1] < smatrB[k2][1]) {
                smatrR[k3][0] = smatrA[k1][0];
                smatrR[k3][1] = smatrA[k1][1];
                smatrR[k3][2] = smatrA[k1][2];
                k1++;
                k3++;
            } else {
                smatrR[k3][0] = smatrB[k2][0];
                smatrR[k3][1] = smatrB[k2][1];
                smatrR[k3][2] = smatrB[k2][2];
                k2++;
                k3++;
            }
        } else if (smatrA[k1][0] < smatrB[k2][0]) {
            smatrR[k3][0] = smatrA[k1][0];
            smatrR[k3][1] = smatrA[k1][1];
            smatrR[k3][2] = smatrA[k1][2];
            k1++;
            k3++;
        } else {
            smatrR[k3][0] = smatrB[k2][0];
            smatrR[k3][1] = smatrB[k2][1];
            smatrR[k3][2] = smatrB[k2][2];
            k2++;
            k3++;
        }
    }

    // Insert any remaining elements
    while (k1 <= smatrA[0][2]) {
        smatrR[k3][0] = smatrA[k1][0];
        smatrR[k3][1] = smatrA[k1][1];
        smatrR[k3][2] = smatrA[k1][2];
        k1++;
        k3++;
    }
    while (k2 <= smatrB[0][2]) {
        smatrR[k3][0] = smatrB[k2][0];
        smatrR[k3][1] = smatrB[k2][1];
        smatrR[k3][2] = smatrB[k2][2];
        k2++;
        k3++;
    }

    // Fill in the header of the sparse matrix representation
    smatrR[0][0] = smatrA[0][0];
    smatrR[0][1] = smatrA[0][1];
    smatrR[0][2] = k3 - 1;
}

void main() {
    // Define three sparse matrix representations. Two for the matrices to be
    // added and one for the resulting sparse matrix representation
    int smatrA[100][3], smatrB[100][3], smatrR[100][3];

    // Get the size of the matrices first to make sure that both the sparse matrices will have the same size
    int r, c;
    printf("Enter the size of the sparse matrix (rows columns): ");
    scanf("%d %d", &r, &c);

    // Read and store the matrices
    printf("Enter the first matrix:\n");
    read_smatr(smatrA, r, c);
    printf("\n");
    printf("Enter the second matrix:\n");
    read_smatr(smatrB, r, c);

    // Add the sparse matrix representations
    add_smatr(smatrA, smatrB, smatrR);

    // Print all the matrices
    printf("First matrix:\n");
    print_mat(smatrA[0][2] + 1, 3, smatrA);
    printf("Second matrix:\n");
    print_mat(smatrB[0][2] + 1, 3, smatrB);
    printf("Sum of the matrices:\n");
    print_mat(smatrR[0][2] + 1, 3, smatrR);
}