#include"BST.h"
#include<limits.h>

bool checkBST(Node *root, int min, int max){
	if (!root)
		return true;
	else if (root->data > min && root->data < max){
		bool left = checkBST(root->left, min, root->data);
		bool right = checkBST(root->right, root->data, max);
		if (left && right)
			return true;
	}
	return false;
}

bool isBst(Node *root){
	int result = checkBST(root, INT_MIN, INT_MAX);
	if (result)
		return true;
	return false;
}