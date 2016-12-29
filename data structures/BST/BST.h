#include<stdio.h>
#include<iostream>
#include<stdbool.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right, *nextSibling;
}Node;


//Basic Tree  functions
Node *constructTree(int *values, int n);
Node *insertion(Node* root, int data);
Node *createNode(int data);
Node *deletion(Node *root, int data);
Node *getMinNode(Node *root);
Node *getNode(Node *root, int data);//similar to find method 
void printInorder(Node *root);
void PrintPreorder(Node *root);
void printPostorder(Node *root);
bool isBst(Node *root);
void levelOrder(Node *root);
void reverseLevelOrder(Node *root);
bool isMirror(Node *first, Node *second);
void printZigZag(Node *root);
Node *trim(Node *root, int a, int b);
Node *leastCommonAncestor(Node *root, Node *a, Node *b);
int height(Node *root);
int diameter(Node *root);
void leftView(Node *root);
void rightView(Node *root);
void topView(Node *root);
void bottomView(Node*root);
void path_with_sum_k(Node *root);
void path_with_largest_sum(Node *root);
void print_Nodes_at_distance_of_k_from_given_node(Node *root, Node *source);
bool isCompleteTree(Node *root);
Node *makeLinks(Node *root);

