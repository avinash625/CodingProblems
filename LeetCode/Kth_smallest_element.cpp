/* 
Problem Link:
https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
/*
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void KthSmallestUtil(TreeNode *root, int k, int *currentPosition, int *answer){
        if(!root) return ;
        else{
            KthSmallestUtil(root->left,k,currentPosition,answer);
            if(*currentPosition == k-1) *answer = root->val;
            //cout<<" at currentPosition of "<<*currentPosition << " "<<root->val <<" is present"<<endl;
            * currentPosition = *currentPosition + 1;
            KthSmallestUtil(root->right,k,currentPosition,answer);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        int answer = 0,currentPosition = 0;
        KthSmallestUtil(root,k,&currentPosition,&answer);
        return answer;
    }
};
