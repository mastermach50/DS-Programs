# Bubble Sort

#### Aim:-
Write a program to sort a user defined array of integers using bubble sort.

#### Algorithm:-
1. START
1. Get the number of elements in the array and store it as n.
1. Loop from i=0 to n and read each element in the array from the user and store it in an array called arr.
1. Create a function print_array(int arr[], int n) that loops from i=0 to n and print each arr[i].
1. Call the print_array function with arr and n
1.  ```
    Loop from i=0 to n  
        swapped = 0  
        Loop from j=0 to n-1-i  
            if arr[j] > arr[j+1]  
                swap arr[j] and arr[j+1]  
                swapped = 1  
        if swapped = 1 then break  
    ```
1. Call the print_array function with arr and n
1. STOP

#### Result:-
Program executed successfully.