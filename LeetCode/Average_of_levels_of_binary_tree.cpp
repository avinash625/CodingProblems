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
    int getTreeHeight(TreeNode *root){
        if(root == NULL) return 0;
        else return 1+(max(getTreeHeight(root->left),getTreeHeight(root->right)));
    }
    void getAverageOfLevels(TreeNode *root,vector<double> &average,vector<int> &noOfNodes,int level){
        if(!root){
            return ;
        }
        else{
           average[level] = (average[level]*noOfNodes[level]+root->val)/(noOfNodes[level] + 1);
            noOfNodes[level] += 1;
            getAverageOfLevels(root->left,average,noOfNodes,level+1);
            getAverageOfLevels(root->right,average,noOfNodes,level+1);
        }
    }
    vector<double> averageOfLevels(TreeNode* root) {
       int height = getTreeHeight(root);
        vector<double> average(height);
        vector<int> noOfNodes(height);
        getAverageOfLevels(root,average, noOfNodes,0);
        return average;
    }
};
