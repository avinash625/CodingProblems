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
    void convertBSTUtil(TreeNode *root, int *greaterNodeValue){
        if(!root)
            return ;
        else{
            convertBSTUtil(root->right,greaterNodeValue);
            //cout<<"greaterNodeValue changed from "<<*greaterNodeValue <<" to "<<*greaterNodeValue+ root->val<<endl;
            *greaterNodeValue = *greaterNodeValue+(root->val);
            root->val = *greaterNodeValue;
            convertBSTUtil(root->left,greaterNodeValue);
        }
    }
    TreeNode* convertBST(TreeNode* root) {
        int greaterNodeValue = 0;
        convertBSTUtil(root,&greaterNodeValue);
        return root;
    }
};
