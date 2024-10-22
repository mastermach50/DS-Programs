// Write a program to search for a number in an array using binary search

#include <stdio.h>

void main() {
    // Get the elements in the array from the user
    int n, search;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements in the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Get the element to serch for
    printf("Enter the element to search for: ");
    scanf("%d", &search);

    // Perform binary search
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == search) {
            printf("%d was found  at position %d", search, mid);
            return;
        } else if (search > arr[mid]) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    printf("%d was not found in the array", search);
}