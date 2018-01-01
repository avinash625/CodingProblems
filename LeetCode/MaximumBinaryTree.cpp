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
    TreeNode *constructNode(int data) {
        TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode) * 1);
        newNode->val = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    TreeNode *constructMaximumBinaryTreeUtil(vector<int> input, int start, int ending) {
            if (ending < start)
                return NULL;
            else {
                int maxIndex = start;
                for (int iter = start;iter <= ending;iter++) {
                    if (input[maxIndex] < input[iter])
                        maxIndex = iter;
                }
                //cout<<"the maximumIndex is "<<maxIndex<<" with value "<<input[maxIndex]<<endl;
                TreeNode *newNode = constructNode(input[maxIndex]);
                //cout<<"moving to the left subpart of range "<<start <<" " <<maxIndex-1<<endl;
                newNode->left = constructMaximumBinaryTreeUtil(input, start, maxIndex - 1);
                //cout<<"moving to the left subpart of range "<<maxIndex+1 <<" " <<ending<<endl;
                newNode->right = constructMaximumBinaryTreeUtil(input, maxIndex + 1, ending);
                //cout<<"returning "<<newNode->val<< " as the root "<<endl;
                return newNode;
            }
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTreeUtil(nums,0,nums.size()-1);
    }
};
