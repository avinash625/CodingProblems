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
    int SumOfLeftLeavesUtil(TreeNode *root, int isRight){
        if(!root) return 0;
        if(!isRight){
            if(!root->left && !root->right){
                return root->val;
            }
        }
        return SumOfLeftLeavesUtil(root->left,0) + SumOfLeftLeavesUtil(root->right,1);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        return SumOfLeftLeavesUtil(root->left,0)+SumOfLeftLeavesUtil(root->right,1);
    }
};
