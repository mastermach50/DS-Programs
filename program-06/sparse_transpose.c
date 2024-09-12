// Write a program to find the transpose of a sparse matrix.

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

// A function to read a sparse matrix of size [r]x[c] and insert it into [mat]
// and also insert its sparse matrix representation int [smat].
void read_matrix(int r, int c, int sm[r][c], int smr[100][3]) {

    int k = 1;

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
}

// A function to get the transpose of a sparse matrix representation.
int trans_matrix(int smr[100][3], int tsmr[100][3]) {
    int k = 1;
    // The outer loop loops over all the column values
    // and the inner loop goes from 0 till the number of non zero elements (both inclusive).
    for (int i = 0; i < smr[0][1]; i++) {
        for (int j = 0; j <= smr[0][2]; j++) {
            // The row column values are only interchanged and inserted if the column value matches i. #TODO
            if (smr[j][1] == i) {
                tsmr[k][0] = smr[j][1];
                tsmr[k][1] = smr[j][0];
                tsmr[k][2] = smr[j][2];
                k++;
            }
        }
    }

    // The first row of the transposed matrix representation is created.
    tsmr[0][0] = smr[0][1];
    tsmr[0][1] = smr[0][0];
    tsmr[0][2] = smr[0][2];
}

void main() {

    // Get the size of the sparse matrix from the user.
    int r, c;
    printf("Enter the size of the matrix (rows columns): ");
    scanf("%d %d", &r, &c);

    // Create the sparse matrix from the sizes and another matrix for the sparse matrix representation.
    int sm[r][c];
    int smr[100][3];
    int tsmr[100][3];

    // Read the sparse matrix and get its sparse matrix representation.
    read_matrix(r, c, sm, smr);

    // Print the sparse matrix.
    printf("The sparse matrix is\n");
    print_matrix(r, c, sm);

    // Print the sparse matrix representaion.
    printf("The sparse matrix representation is\n");
    print_matrix(smr[0][2] + 1, 3, smr);

    // Print the transpose of the sparse matrix representaion.
    printf("The transpose of the sparse matrix in representation is\n");
    trans_matrix(smr, tsmr);
    print_matrix(tsmr[0][2] + 1, 3, tsmr);
}