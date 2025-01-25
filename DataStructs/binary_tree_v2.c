#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure
typedef struct Node_ {
    int data;
    struct Node_* left;
    struct Node_* right;
} node, *pnode;

// Function to create a new node
pnode newNode(int val) {
    pnode temp = (pnode)malloc(sizeof(node));
    if (!temp) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Function to insert a new value into the binary search tree
void insert(pnode* root, int data) {
    while (*root) {
        if (data < (*root)->data)
            root = &((*root)->left);
        else
            root = &((*root)->right);
    }
    *root = newNode(data);
}

// Function to find the height of a binary tree
int height(pnode node) {
    if (!node) return -1; // Return -1 for an empty tree

    int lh = height(node->left); // Height of the left subtree
    int rh = height(node->right); // Height of the right subtree

    if (lh > rh) 
        return lh + 1; // Include the current node
    else 
        return rh + 1; // Include the current node
}

// Main function to demonstrate usage
int main() {
    pnode root = NULL;

    insert(&root, 10);
    insert(&root, 5);
    insert(&root, 15);
    insert(&root, 3);
    insert(&root, 7);

    printf("Height of the tree: %d\n", height(root)); // Expected output: 2

    return 0;
}
