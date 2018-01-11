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
    void findLeftValue(TreeNode *root, int *leftValue, int *levelValue,int level){
        if(!root) return;
        else{
            if(*levelValue < level){
                *leftValue = root->val;
                *levelValue = level;
            }
            findLeftValue(root->left,leftValue, levelValue, level+1);
            findLeftValue(root->right,leftValue, levelValue, level+1);
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        int leftValue , levelValue;
        levelValue = 0;
        leftValue = root->val;
        findLeftValue(root,&leftValue, &levelValue, 0);
        return leftValue;
    }
};
