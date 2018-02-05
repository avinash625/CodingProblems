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
    string tree2str(TreeNode* t) {
        if(!t) return "";
        else{
            //cout<<"at root "<<t->val<<endl;
            string result = "";
            if(t->left){
                //cout<<"moving to left of root and adding ("<<endl;
                result = result + "(";
                result += tree2str(t->left);
                result = result + ")";
                //cout<<"moving back to the root and adding )"<<endl;
            }
            else{
                result = result + "()";
            }
            if(t->right){
                //cout<<"moving to right of root and adding ("<<endl;
                result = result + "(";
                result += tree2str(t->right);
                result = result + ")";
                //cout<<"moving back to the root and adding )"<<endl;
            }
            else if(!t->left && !t->right){
                //cout<<"returning "<<to_string(t->val)<<endl;
                return to_string(t->val);
            }
            //cout<<"returning "<<to_string(t->val) + result << endl;
            return to_string(t->val) + result;
        }
    }
};
