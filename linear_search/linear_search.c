#include <stdio.h>

void linear_search(int n, int arr[n], int search) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == search) {
            printf("%d was found at position %d", search, i);
            return;
        }
    }

    printf("%d was not found in the array", search);
}

void main() {
    // Get the number of elements in the array
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Get the elements in the array
    int arr[n];
    printf("Enter the elements in the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Get the element to search for
    int search;
    printf("Enter the element to search for: ");
    scanf("%d", &search);

    linear_search(n, arr, search);
}