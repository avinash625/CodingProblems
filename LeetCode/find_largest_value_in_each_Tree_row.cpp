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
        else return (1+max(getHeight(root->left),getHeight(root->right)));
    }
    void getRowLargestValues(TreeNode *root,vector<int> &result, int level){
        if(!root) return;
        else{
            if(result[level] < root->val){
                result[level] = root->val;
            }
            getRowLargestValues(root->left,result,level+1);
            getRowLargestValues(root->right,result, level+1);
        }
    }
    vector<int> largestValues(TreeNode* root) {
       int height = getHeight(root);
        vector<int> result(height,INT_MIN);
        getRowLargestValues(root,result,0);
        return result; 
    }
};
