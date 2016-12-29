#include"BST.h"
#include<stdio.h>
#include<stdlib.h>

using namespace std;

void printInorder(Node *root) {
	if (!root) {
		return;
	}
	printInorder(root->left);
	printf("%d ", root->data);
	printInorder(root->right);
}

Node * getNode(Node *root, int data)
{	//given a data value , it returns the node address to manipulate with.
	if (!root)
		return nullptr;
	else if (root->data > data) {
		return getNode(root->left, data);
	}
	else if (root->data < data) {
		return getNode(root->right, data);
	}
	return NULL;
}

Node *createNode(int data) {
	Node *root = (Node *)malloc(sizeof(Node));
	root->data = data;
	root->left = NULL;
	root->right = NULL;
	root->nextSibling = NULL;
	return root;
}

Node *insertion(Node *root, int data) {
	if (!root) {
		return createNode(data);
	}
	else if (root->data < data) {
		root->right = insertion(root->right, data);
	}
	else if (root->data > data) {
		root->left = insertion(root->left, data);
	}
	return root;
}

Node *constructTree(int *values, int n) {
	Node *root = NULL;
	for (int iter = 0; iter < n; iter++) {
		root = insertion(root, values[iter]);
	}
	return root;
}

Node * getMinNode(Node * root)
{
	Node *temp = root;
	if (!root) {
		return NULL;
	}
	else {
		while (temp->left) {
			temp = temp->left;
		}
	}
	return temp;
}

Node *deletion(Node *root, int data) {
	if (!root) {
		return NULL;
	}
	else if (root->data < data) {
		root->right = deletion(root->right, data);
	}
	else if (root->data > data) {
		root->left = deletion(root->left, data);
	}
	else {
		if (root->left == NULL) {
			root = root->right;
		}
		else if (root->right == NULL) {
			root = root->left;
		}
		else {
			Node *temp = getMinNode(root->right);
			root->data = temp->data;
			root->right = deletion(root->right, temp->data);
		}
	}
	return root;
}



void main(void) {
	Node *root = NULL;
	int values[] = { 20, 10, 25, 5, 15, 30, 29, 55 };//this array represents the preorder of the tree.Using this the tree is constructed.
	int n = 8;//this has to be the number of nodes in the binary tree.
	root = constructTree(values, n);
	cout << "the nodes are ";
	printInorder(root);
	deletion(root, 15);
	cout << "\nthe nodes are ";
	printInorder(root);

}