// Write a program to add two sparse matrices

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

void add_smatr(int smatr_a[100][3], int smatr_b[100][3], int sum[100][3]) {
    int a = 1, b = 1, k = 1;

    while (a <= smatr_a[0][2] && b <= smatr_b[0][2]) {
        if (smatr_a[a][0] == smatr_b[b][0]) {
            if (smatr_a[a][1] == smatr_b[b][1]) {
                sum[k][0] = smatr_a[a][0];
                sum[k][1] = smatr_a[a][1];
                sum[k][2] = smatr_a[a][2] + smatr_b[b][2];
                a++;
                b++;
                k++;
            } else if (smatr_a[a][1] < smatr_b[b][1]) {
                sum[k][0] = smatr_a[a][0];
                sum[k][1] = smatr_a[a][1];
                sum[k][2] = smatr_a[a][2];
                a++;
                k++;
            } else {
                sum[k][0] = smatr_b[b][0];
                sum[k][1] = smatr_b[b][1];
                sum[k][2] = smatr_b[b][2];
                b++;
                k++;
            }
        } else if (smatr_a[a][0] < smatr_b[b][0]) {
            sum[k][0] = smatr_a[a][0];
            sum[k][1] = smatr_a[a][1];
            sum[k][2] = smatr_a[a][2];
            a++;
            k++;
        } else {
            sum[k][0] = smatr_b[b][0];
            sum[k][1] = smatr_b[b][1];
            sum[k][2] = smatr_b[b][2];
            b++;
            k++;
        }
    }

    while (a <= smatr_b[0][2]) {
        sum[k][0] = smatr_a[a][0];
        sum[k][1] = smatr_a[a][1];
        sum[k][2] = smatr_a[a][2];
        a++;
        k++;
    }
    while (b <= smatr_b[0][2]) {
        sum[k][0] = smatr_b[b][0];
        sum[k][1] = smatr_b[b][1];
        sum[k][2] = smatr_b[b][2];
        b++;
        k++;
    }

    sum[0][0] = smatr_a[0][0];
    sum[0][1] = smatr_a[0][1];
    sum[0][2] = k-1;
}

void main() {
    // Declare two sparse matrix representations and read data into them
    int smatr_a[100][3], smatr_b[100][3], sum[100][3];
    printf("Enter the first sparse matrix\n");
    read_smatr(smatr_a);
    print_matrix(smatr_a[0][2]+1, 3, smatr_a);
    printf("\n");
    printf("Enter the second sparse matrix\n");
    read_smatr(smatr_b);
    print_matrix(smatr_b[0][2]+1, 3, smatr_b);
    printf("\n");

    if ((smatr_a[0][0] != smatr_b[0][0]) || (smatr_a[0][1] != smatr_b[0][1])) {
        printf("Matrices are not of same size");
        return;
    }

    // Find the sum of the matrices and print it
    printf("The sum of the sparse matrices is\n");
    add_smatr(smatr_a, smatr_b, sum);
    print_matrix(sum[0][2]+1, 3, sum);
    printf("\n");
}