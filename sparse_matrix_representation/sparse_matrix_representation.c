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

void main() {
    // Get the number of rows and columns of the sparse matrix
    int r, c;
    printf("Enter the size of the sparse matrix (rows columns): ");
    scanf("%d %d", &r, &c);

    // Get each element of the sparse matrix
    int smat[r][c], smatr[100][3], k = 1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("Enter the element[%d][%d]: ", i, j);
            scanf("%d", &smat[i][j]);

            // If the element is not 0 then make an entry for it in the sparse matrix representation
            if (smat[i][j] != 0) {
                smatr[k][0] = i;
                smatr[k][1] = j;
                smatr[k][2] = smat[i][j];
                k++;
            }
        }
    }

    // Fill in the header of the sparse matrix representation
    smatr[0][0] = r;
    smatr[0][1] = c;
    smatr[0][2] = k - 1;

    // Print the sparse matrix and its representation
    printf("The sparse matrix is:\n");
    print_mat(r, c, smat);

    printf("The sparse matrix is:\n");
    print_mat(smatr[0][2] + 1, 3, smatr);
}