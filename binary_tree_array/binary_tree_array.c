#include <stdio.h>

#define SIZE 15

// Define the binary tree in array form
char binarytree[SIZE] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', '\0', '\0', 'J', '\0', 'K', 'L'};

// Define functions to get the left and right child of a node
int getRightChildIndex(int index) {
    if (binarytree[index] != '\0' && (2 * index + 2) < SIZE) {
        return (2 * index + 2);
    }
    return -1;
}

int getLeftChildIndex(int index) {
    if (binarytree[index] != '\0' && (2 * index + 1) < SIZE) {
        return (2 * index + 1);
    }
    return -1;
}

// Define the preorder, inorder and postorder functions
int preorder(int index) {
    if (binarytree[index] != '\0' && index != -1) {
        printf("%c ", binarytree[index]);
        preorder(getLeftChildIndex(index));
        preorder(getRightChildIndex(index));
    }
}

int inorder(int index) {
    if (binarytree[index] != '\0' && index != -1) {
        inorder(getLeftChildIndex(index));
        printf("%c ", binarytree[index]);
        inorder(getRightChildIndex(index));
    }
}

int postorder(int index) {
    if (binarytree[index] != '\0' && index != -1) {
        postorder(getLeftChildIndex(index));
        postorder(getRightChildIndex(index));
        printf("%c ", binarytree[index]);
    }
}

void main() {
    printf("Preorder traversal:\n");
    preorder(0);
    printf("\n");
    printf("Inorder traversal:\n");
    inorder(0);
    printf("\n");
    printf("Postorder traversal:\n");
    postorder(0);
    printf("\n");
}