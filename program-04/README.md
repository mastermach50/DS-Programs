# Sparse Representation 

#### Aim:-
Write a program to read a sparse matrix and convert it into a sparse matrix representation.

#### Algorithm:-
1. START
1. Get the number of rows and columns of the sparse matrix and store them as r and c.
1. Create two matrices int sm[r][c] and int smr[100][3].
1. Initialize k = 0
1.  ```
    Loop from i=0 to r  
        Loop from j=0 to c  
            Read the element and store it at sm[i][j]  
            If element!=0  
                smr[k][0] = i;  
                smr[k][1] = j;  
                smr[k][2] = sm[i][j];  
                k++;  
    ```
1.  ```
    smr[0][0] = r;
    smr[0][1] = c;
    smr[0][2] = k - 1;
    ```
1. Loop from i=0 to r and j=0 to c and print the elements sm[i][j].
1. Loop from i=0 to k and j=0 to 3 and print the elements smr[i][j].
1. STOP

#### Result:-
The program executed successfully.