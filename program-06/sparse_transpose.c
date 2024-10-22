// Write a program to find the transpose of a sparse matrix

#include <stdio.h>

// A function to print any matrix of size [r] x [c]
void print_matrix(int r, int c, int mat[r][c]) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// A function to read a sparse matrix from the user and convert it
// into a sparse matrix representation
void read_smatr(int smatr[100][3]) {
    int r, c, k = 1;
    printf("Enter the size of the sparse matrix (rows columns): ");
    scanf("%d %d", &r, &c);
    printf("Enter the elements in the sparse matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int val;
            printf("[%d][%d]: ", i, j);
            scanf("%d", &val);

            if (val != 0) {
                smatr[k][0] = i;
                smatr[k][1] = j;
                smatr[k][2] = val;
                k++;
            }
        }
    }

    // Add the first line of the sparse matrix representation
    smatr[0][0] = r;
    smatr[0][1] = c;
    smatr[0][2] = k - 1;
}

void transpose_smatr(int smatr[100][3], int tsmatr[100][3]) {
    int k = 1;

    // Loop from 0 to the number of columns of the sparse matrix
    for (int i = 0; i < smatr[0][1]; i++) {
        // Loop from 0 to the number of non zero elements in the sparse matrix
        for (int j = 0; j <= smatr[0][2]; j++) {
            if (smatr[j][1] == i) {
                tsmatr[k][0] = smatr[j][1];
                tsmatr[k][1] = smatr[j][0];
                tsmatr[k][2] = smatr[j][2];
                k++;
            }
        }
    }

    // Don't forget to write the first line of the sparse matrix representation
    tsmatr[0][0] = smatr[0][1];
    tsmatr[0][1] = smatr[0][0];
    tsmatr[0][2] = smatr[0][2];
}

void main() {
    // Get the sparse matrix representation from the user
    int smatr[100][3], tsmatr[100][3];
    printf("Enter the sprse matrix\n");
    read_smatr(smatr);

    // Print the sparse matrix representation
    print_matrix(smatr[0][2] + 1, 3, smatr);

    // Get the transpose of the sparse matrix representation
    transpose_smatr(smatr, tsmatr);

    // Print the transposed matrix
    print_matrix(tsmatr[0][2] + 1, 3, tsmatr);
}