# [Program-3] Sparse Matrix Addition
## Aim:-
Write a program to add two sparse matrix representations.

## Algorithm:-
1. START
2. Read and store two sparse matrix representations from the user as smatrA and smatrB. Create a sparse matrix representation smatrR to store the sum of the sparse matrix representations.
3. Set k1=k2=k3=1.
4. While k1 <= smatrA[0][2] and k2 <= smatrB[0][2] follow steps 5 to 
5. Compare the row value of the k1<sup>th</sup> term of smatrA and the k2<sup>th</sup> term of smatrB. If they are equal then goto step 6 else goto step 7.
6. Compare the column value of the k1<sup>th</sup> term of smatrA and the k2<sup>th</sup> term of smatrB, if they are equal then insert a new term into smatrR with the same row and column value as the compared terms and the value of the term as sum of the values of the compared terms, then increment k1, k2 and k3. Otherwise insert the term with the lowest column value, then increment k3 it's k value.
7. Compare the row value of the k1<sup>th</sup> term of smatrA and the k2<sup>th</sup> term of smatrB, then insert the term with the lowest row value, then increment k3 and it's k value.
8. Insert any remaining terms in the two sparse matrix representations into the result matrix.
9. Display the result matrix.
10. STOP
    
## Result:-
Two sparse matrix representations were added.