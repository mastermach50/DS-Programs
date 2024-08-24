// Write a program to sort a user defined array of integers using bubble sort

#include <stdio.h>

// A function to print the array [arr] till position [n]
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

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

    // Print array before sorting
    print_array(arr, n);

    // Bubble sort with optimizations (phase optimization and swapped flag optimization)
    for (int i = 0; i < n; i++) {
        int swapped = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }

    // Print array after sorting
    print_array(arr, n);
}