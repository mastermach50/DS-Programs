// Write a program to read a sparse matrix and convert it into sparse matrix representation

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

void main() {
    // Get the sparse matrix from the user, at the same time add the non zero
    // elements to the sparse matrix representaion [smatr]
    int r, c;
    printf("Enter the size of the sparse matrix (rows columns): ");
    scanf("%d %d", &r, &c);
    int smat[r][c], smatr[100][3], k = 1;
    printf("Enter the elements in the sparse matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &smat[i][j]);

            if (smat[i][j] != 0) {
                smatr[k][0] = i;
                smatr[k][1] = j;
                smatr[k][2] = smat[i][j];
                k++;
            }
        }
    }

    // Add the first line of the sparse matrix representation
    smatr[0][0] = r;
    smatr[0][1] = c;
    smatr[0][2] = k - 1;

    // Print the sparse matrix
    printf("The sparse matrix is:\n");
    print_matrix(r, c, smat);

    // Print the sparse matrix representaion
    printf("The sparse matrix representation is:\n");
    print_matrix(k, 3, smatr);
}