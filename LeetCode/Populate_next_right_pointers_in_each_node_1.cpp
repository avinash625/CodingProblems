/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void makeRightNull(TreeLinkNode *root){
        TreeLinkNode *temp = root;
        while(temp){
            temp->next = NULL;
            temp = temp->right;
        }
    }
    void connectUtil(TreeLinkNode *root){
        if(root){
            
            if(root->left && root->right){
                //cout<<"connecting "<<root->left->val<<" and "<<root->right<<endl;
                root->left->next = root->right;
            }
            if(root->next && root->right){
                //cout<<"connecting "<<root->right->val<<" and "<<root->next->left->val<<endl;
                root->right->next = root->next->left;
            }
            connectUtil(root->left);
            connectUtil(root->right);
        }
        else{
            return;
        }
    }
    void connect(TreeLinkNode *root) {
        makeRightNull(root);
        connectUtil(root);
    }
};
