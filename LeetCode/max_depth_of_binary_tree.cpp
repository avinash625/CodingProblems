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
    int max(int a, int b){
        if(a>b)return a;
        return b;
    }
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        else
            return max(maxDepth(root->left), maxDepth(root->right))+1;
    }
};
