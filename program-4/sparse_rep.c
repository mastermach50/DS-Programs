// Write a program to read a sparse matrix and convert it into a sparse matrix representation.

#include <stdio.h>

// A function to print a matrix [mat] having [r] rows and [c] columns.
void print_matrix(int r, int c, int mat[r][c]) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void main() {

    // Get the size of the sparse matrix from the user.
    int r, c;
    printf("Enter the size of the matrix (rows columns): ");
    scanf("%d %d", &r, &c);

    // Create the sparse matrix from the sizes and another matrix for the sparse matrix representation.
    int sm[r][c];
    int smr[100][3];
    int k = 1;

    // Get all the elements of the sparse matrix from the user and also
    // make the sparse matrix representation during this process.
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &sm[i][j]);

            if (sm[i][j] != 0) {
                smr[k][0] = i;
                smr[k][1] = j;
                smr[k][2] = sm[i][j];
                k++;
            }
        }
    }

    smr[0][0] = r;
    smr[0][1] = c;
    smr[0][2] = k - 1;

    // Finally print the sparse matrix and it's representation.
    printf("The sparse matrix is\n");
    print_matrix(r, c, sm);

    printf("The sparse matrix representation is\n");
    print_matrix(k, 3, smr);
}