#include <stdio.h>

void display(int n, int arr[n]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selection_sort(int n, int arr[n]) {
    int min, temp;

    for (int i = 0; i < n - 1; i++) {
        // Assume [i] to be the position with minimum element
        min = i;
        // Loop through all the positions after [i] and find the position with the actual minimum
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        // Swap the values at [i] and [min]
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
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

    selection_sort(n, arr);
}