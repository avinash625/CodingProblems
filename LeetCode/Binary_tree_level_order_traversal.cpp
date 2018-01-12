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
    void levelOrderUtil(TreeNode *root, vector<vector<int>> &result, int level){
        if(!root) return;
        else{
            result[level].push_back(root->val);
            levelOrderUtil(root->left,result,level+1);
            levelOrderUtil(root->right,result,level+1);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int height = getHeight(root);
        vector<vector<int>> result(height);
        levelOrderUtil(root,result,0);
        return result;
    }
};
