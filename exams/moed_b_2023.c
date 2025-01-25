#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MASK_C1 512
#define MASK_C2 254
#define MASK_o1 2048
#define MASK_o2 4096


// Define the TreeNode structure
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to create a new node
TreeNode* createNode(int value) {
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new value into the binary search tree
TreeNode* insert(TreeNode *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to calculate the height of a binary tree
int height(TreeNode *root) {
    if (root == NULL) {
        return -1; // Return -1 for an empty tree
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}

void oper(int status){
    int value_o1 = (status & MASK_o1)>>11;
    int value_o2 = (status & MASK_o2)>>12;
    int value_c1 = (status & MASK_C1)>>9;
    int value_c2 = (status & MASK_C2)>>1;
    if(value_o1==0 && value_o2==0){
        double c1_doub = (double)(value_c1);
        double c2_doub = (double)(value_c2);
        printf("answer is: %lf",pow(c2_doub,c1_doub));
    }
    if(value_o1==1 && value_o2==0){
        double c1_doub = (double)(value_c1);
        double c2_doub = (double)(value_c2);
        printf("answer is: %lf",pow(c1_doub,c2_doub));
    }
    if(value_o1==0 && value_o2==1){
        printf("answer is: %d",value_c2 - value_c1);
    }
    if(value_o1==1 && value_o2==1){
        printf("answer is: %d",value_c2 + value_c1);
    }
}

typedef struct{
    unsigned int o1 : 1;
    unsigned int o2 : 1;
    unsigned int c1 : 1;
    unsigned int c2 : 7;
}Bitfield;

int main(){
    Bitfield bits = {1,1,1,4};
    if(bits.o1==0 && bits.o2==0){
        double c1_doub = (double)(bits.c1);
        double c2_doub = (double)(bits.c2);
        printf("answer is: %lf",pow(c2_doub,c1_doub));
    }
    if(bits.o1==1 && bits.o2==0){
        double c1_doub = (double)(bits.c1);
        double c2_doub = (double)(bits.c2);
        printf("answer is: %lf",pow(c1_doub,c2_doub));
    }
    if(bits.o1==0 && bits.o2==1){
        printf("answer is: %d",bits.c2 - bits.c1);
    }
    if(bits.o1==1 && bits.o2==1){
        printf("answer is: %d",bits.c2 + bits.c1);
    }
}

typedef struct item { 
   int value; 
   struct item *next; 
} item; 

item* merge(item* node1, item* node2){
    item dummy;
    item* tail = &dummy;
    dummy.next = NULL;
    // Merge the two lists
    while (node1 && node2) {
        if (node1->value <= node2->value) {
            tail->next = node1;
            node1 = node1->next;
        } else {
            tail->next = node2;
            node2 = node2->next;
        }
        tail = tail->next;
    }

    // Attach any remaining nodes
    if (node1) {
        tail->next = node1;
    }
    if (node2) {
        tail->next = node2;
    }

}

//array of nodes, size of the array, pointer to pointer to node(point to lst)
void multimerger(item* arr[], int size, item** pNewList) {
    if (size == 0) {
        *pNewList = NULL;
        return;
    }
    // Initialize the merged list as the first list in the array
    item* mergedList = arr[0];
    // Iteratively merge each list into the merged list
    for (int i = 1; i < size; i++) {
        mergedList = merge(mergedList, arr[i]);
    }
    // Update the output pointer
    *pNewList = mergedList;
}