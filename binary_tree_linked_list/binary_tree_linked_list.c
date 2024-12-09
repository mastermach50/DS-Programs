#include <stdio.h>
#include <stdlib.h>

// Define a struct for each node of the binary tree
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Define a function to create a newnode
struct node *getNewnode(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("ERROR: Program out of memory\n");
        exit(-1);
    }
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

// Define the preorder, inorder and postorder functions
void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void main() {
    struct node *root = getNewnode(0);
    root->left = getNewnode(1);
    root->right = getNewnode(2);
    root->left->left = getNewnode(3);
    root->left->right = getNewnode(4);
    root->right->left = getNewnode(5);
    root->right->right = getNewnode(6);

    printf("Preorder traversal:\n");
    preorder(root);
    printf("\n");
    printf("Inorder traversal:\n");
    inorder(root);
    printf("\n");
    printf("Postorder traversal:\n");
    postorder(root);
    printf("\n");
}
