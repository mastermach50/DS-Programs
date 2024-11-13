#include <stdio.h>

void display(int n, int arr[n]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertion_sort(int n, int arr[n]) {
    for (int i = 1; i < n; ++i) {
        // Set the second element at the key, because we are
        // assuming that the first element is sorted
        int key = arr[i];

        // Set j = i - 1, we are going to compare the [key] with every element before it
        int j = i - 1;

        // Loop backwards till we find an element in the back
        // which is lower than the key or till we check all the elements in the back
        while (j >= 0 && arr[j] > key) {
            // For every element in the back that is higher than the key
            // we set the next element equal to that element
            arr[j + 1] = arr[j];

            // We are going backwards
            j--;
        }
        // Set the last checked element equal to the key
        arr[j + 1] = key;
    }

    // Finally display the sorted array
    display(n, arr);
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

    insertion_sort(n, arr);
}