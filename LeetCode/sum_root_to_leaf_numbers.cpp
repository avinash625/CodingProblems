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
    void getSumNumbers(TreeNode *root, int previousValue, int *result){
        if(!root) return ;
        else{
            if(!root->left && !root->right){
                *result = *result  + (previousValue*10+root->val);
            }else{
                getSumNumbers(root->left,previousValue*10+root->val, result);
                getSumNumbers(root->right,previousValue*10+root->val, result);
            }
        }
    }
    int sumNumbers(TreeNode* root) {
        int result = 0;
        if(!root) return 0;
        else{
            getSumNumbers(root,0,&result);
            return result;
        }
    }
};
