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
    int getHeight(TreeNode *root){
        if(!root) return 0;
        else return max(getHeight(root->left), getHeight(root->right))+1;
    }
    void getRightView(TreeNode *root, vector<int> &result,int level){
       if(!root) return;
        else{
            result[level] = root->val;
            getRightView(root->left,result,level+1);
            getRightView(root->right,result, level+1);
        } 
    }
    vector<int> rightSideView(TreeNode* root) {
       int height = getHeight(root);
        vector<int> result(height);
        getRightView(root,result,0);
        return result;
    }
};
