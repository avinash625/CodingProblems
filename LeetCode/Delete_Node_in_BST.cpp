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
    TreeNode *findMaximum(TreeNode *root){
        TreeNode *iter = root;
        if(!root)return root;
        else{
            while(iter->left){
                iter = iter->left;
            }
        }
         return iter;       
    }
    void printInorder1(TreeNode *root){
        if(!root) return ;
        else{
            printInorder1(root->left);
            cout<<" "<<root->val;
            printInorder1(root->right);
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return NULL;
        else if(root->val < key){
                root->right = deleteNode(root->right,key);
            }
        else if(root->val > key){
                root->left = deleteNode(root->left,key);
            }
        else if(root->val == key){
            if(!root->left && root->val == key){
                return (root->right);
            }
            else if(!root->right && root->val == key){
                return (root->left);
            }
            else{
                TreeNode * maximumNode = findMaximum(root->right);
                root->val = maximumNode->val;
                root->right = deleteNode(root->right,maximumNode->val);
            }
        }
        return root;
    }
};
