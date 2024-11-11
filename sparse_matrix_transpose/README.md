# [Program-4] Sparse Matrix Transpose
## Aim:-
Write a program to find the transpose of a sparse matrix representation.

## Algorithm:-
1. START
2. Declare two sparse matrix representations smatr[100][3] and tsmatr[100][3] to store the original sparse matrix and it's transpose respectively.
3. Read a sparse matrix representation from the user and store it in smatr.
4. Set the first row of tsmatr to have the number of rows and columns of smatr inverted and the number of non zero elements to be the same.
5. Set k=1 to track the number of rows of the transposed sparse matrix representation.
6. Using a nested loop, loop from i=0 to i<number of columns of the sparse matrix and j=1 to j<=number of non zero elements of the sparse matrix.
7. Inside the nested loop if (smatr[j][1] == i) then insert the j<sup>th</sup> row of smatr into tsmatr with the row and column values inverted.
8. Display smatr and tsmatr.
9. STOP

## Result:-
The transpose of a sparse matrix representation was calculated.