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
    private int nodeSum = 0;
    
    public TreeNode bstToGst(TreeNode root) {
        nodeSum = 0;
        bstToGstUtil(root);
        return root;
    }
    
    public void bstToGstUtil(TreeNode root){
        if(root == null) return;
        else{
            bstToGstUtil(root.right);
            root.val = root.val + nodeSum;
            nodeSum = root.val;
            bstToGstUtil(root.left);
        }
    }
}