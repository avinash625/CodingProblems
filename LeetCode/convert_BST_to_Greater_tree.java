/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    int sum = 0;
    public TreeNode convertBST(TreeNode root) {
        convertBSTUtil(root);
        return root;
    }
    
    public void convertBSTUtil(TreeNode root){
        if(root == null) return;
        else{
            convertBSTUtil(root.right);
            sum = root.val + sum;
            root.val = sum;
            convertBSTUtil(root.left);
        }
    }
}