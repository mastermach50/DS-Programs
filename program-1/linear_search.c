// Write a program to conduct linear search in a user defined array of integers

#include <stdio.h>

void main() {

    // Get number of elements
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Get elements
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter element [%d]: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Get search term
    int search;
    printf("Enter element to search: ");
    scanf("%d", &search);

    // Loop over elements and search
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == search) {
            printf("%d was found at position %d", search, i + 1);
            break;
        }
    }
    // This line executes if the loop did not break and ran to completion
    if (i == n) {
        printf("%d was not found in the array", search);
    }
}