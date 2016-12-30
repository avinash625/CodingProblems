#include"BST.h"
#include<iostream>
#include<vector>
#include<map>
using namespace std;

void printLevelK(Node *root, int level, int curr_level){
	if (!root)
		return;
	else if (level == curr_level){
		printf("%d ", root->data);
	}
	else if (curr_level > level){
		return;
	}
	else{
		printLevelK(root->left, level, curr_level + 1);
		printLevelK(root->right, level, curr_level + 1);
	}
}
void levelOrder(Node *root){
	if (!root)
		return;
	else{
		int ht = height(root);
		for (int iter = 0; iter < ht; iter++){
			printf("level %d :", iter);
			printLevelK(root, iter, 0);
			printf("\n");
		}
	}
}