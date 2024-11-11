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

// Read a sparse matrix representation from the user
void read_smatr(int smatr[100][3]) {
    // Get the size of the sparse matrix
    int r, c;
    printf("Enter the size of the sparse matrix (rows columns): ");
    scanf("%d %d", &r, &c);

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

void transpose_smatr(int smatr[100][3], int tsmatr[100][3]) {

    // Invert the rows and columns and set the first row of the transposed sparse matrix
    tsmatr[0][0] = smatr[0][1];
    tsmatr[0][1] = smatr[0][0];
    tsmatr[0][2] = smatr[0][2];

    // Set [k] to track the number of elements of the transposed sparse matrix representation
    int k = 1;

    // Loop from 0 to the number of columns of the sparse matrix
    for (int i = 0; i < smatr[0][1]; i++) {
        // Loop from 0 to the number of non zero elements of the sparse matrix
        for (int j = 1; j <= smatr[0][2]; j++) {
            if (smatr[j][1] == i) {
                tsmatr[k][0] = smatr[j][1];
                tsmatr[k][1] = smatr[j][0];
                tsmatr[k][2] = smatr[j][2];
                k++;
            }
        }
    }
}

void main() {
    // Declare the sparse matrix representation and its transpose
    int smatr[100][3], tsmatr[100][3];

    // Get the sparse matrix representation from the user
    printf("Enter the matrix to transpose: \n");
    read_smatr(smatr);

    // Get the transpose of the sparse matrix representation
    transpose_smatr(smatr, tsmatr);

    // Finally print the two matrices
    printf("The sparse matrix representation is:\n");
    print_mat(smatr[0][2] + 1, 3, smatr);
    printf("The transpose of the sparse matrix representation is:\n");
    print_mat(tsmatr[0][2] + 1, 3, tsmatr);
}