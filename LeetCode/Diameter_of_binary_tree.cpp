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
    int height(TreeNode *root , int *dia){\
        int left ,right;
        if(!root) return 0;
        else{
            left = height(root->left,dia);
            right = height(root->right,dia);
            int a = left+ right;
            if((*dia)  < a)
                *dia = a;                
        }
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        height(root,&dia);
        return dia;
    }
};
