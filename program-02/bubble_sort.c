// Write a program to sort a user defined array of integers using bubble sort

#include <stdio.h>

void main() {
    // Get the elements in the array from the user
    int n;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements in the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array using bubble sort
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            // Swap the current and the next element if they are not in order
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Print the array after sorting
    for (int j = 0; j < n; j++) {
        printf("%d ", arr[j]);
    }
    printf("\n");
}