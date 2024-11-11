#include <stdio.h>

void binary_search(int n, int arr[n], int search) {
    int l = 0;
    int r = n - 1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == search) {
            printf("%d was found at position %d", search, mid);
            return;
        } else if (arr[mid] < search) {
            l = mid + 1;
        } else {
            r = mid - 1;
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

    // Note that binary search requires a sorted array
    binary_search(n, arr, search);
}