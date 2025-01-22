#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* createNode(int value);
TreeNode* insert(TreeNode *root, int value);
TreeNode* search(TreeNode *root, int value);
void inorderTraversal(TreeNode *root);
void preorderTraversal(TreeNode *root);
void postorderTraversal(TreeNode *root);
void freeTree(TreeNode *root);

#endif
