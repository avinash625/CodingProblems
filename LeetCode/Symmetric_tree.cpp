/*
Problem Link:
https://leetcode.com/problems/symmetric-tree/description/
*/


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
    bool isSymmetricUtil(TreeNode *root1,TreeNode *root2){
        if(!root1 && root2){
            return false;
        }
        else if(!root2 && root1){
            return false;
        }
        else if(!root1 && !root2){
            return true;
        }
        else{
            if(root1->val == root2->val){
                return (isSymmetricUtil(root1->left,root2->right) && isSymmetricUtil(root1->right,root2->left));
            }
            else
                return false;
        }
    }
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }
        else{
            return isSymmetricUtil(root->left,root->right);
        }
    }
};
