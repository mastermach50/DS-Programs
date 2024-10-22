// Write a program to conduct linear search in a user defined array of integers

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

    // Get the element to search for from the user
    int search;
    printf("Enter the element to search for: ");
    scanf("%d", &search);

    // Loop through the array and search for the element
    // If the element is found exit from the program
    for (int i = 0; i < n; i++) {
        if (arr[i] == search) {
            printf("%d was found at position %d", search, i);
            exit(0);
        }
    }

    // If the element was not found then print that it was not found
    printf("%d was not found int the array", search);
}