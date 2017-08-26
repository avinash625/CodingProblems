/*
Problem link:
https://leetcode.com/problems/merge-two-binary-trees/description/
*/




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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1){
            //cout<<"t1 is null so returning "<<endl;
            return t2;
        }
        else if(!t2){
            //cout<<"t2 is null so returning t1"<<endl;
         return t1;   
        }
        else{
            t1->left = mergeTrees(t1->left,t2->left);
            t1->right = mergeTrees(t1->right,t2->right);
            //cout<<"adding values "<<t1->val <<" and "<<t2->val<<endl;
            t1->val = t1->val + t2->val;
        }
        return t1;
    }
};
