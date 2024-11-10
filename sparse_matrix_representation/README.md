# [Program-2] Sparse Matrix Representation
## Aim:-
Write a program to convert a sparse matrix to its representation form.

## Algorithm:-
1. START
2. Get the number of rows and columns of the sparse matrix from the user and store them as r and c respectively.
3. Declare the sparse matrix smat[r][c] and the sparse matrix representation smatr[100][3] and set k=1.
4. Using two nested loops from i=0 to r and j=0 to c read and store each element in the sparse matrix into smat[i][j].
5. If the element is not 0 then set smatr[k][0]=i, smatr[k][1]=j, smatr[k][2]=smat[i][j]. Increment k.
6. After the completion of the loops set smatr[0][0]=r, smatr[0][1]=c, smatr[0][2]=k-1.
7. Display the sparse matrix smat by looping from i=0 to r and j=0 to c.
8. Display the sparse matrix representation smatr by looping from i=0 to smatr[0][2]+1 and j=0 to 3.
9. STOP

## Result:-
A sprase matrix was converted to its representation form.