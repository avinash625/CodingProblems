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
    public TreeNode pruneTree(TreeNode root) {
        if(root == null) return null;
        else{
            TreeNode left = pruneTree(root.left);
            TreeNode right = pruneTree(root.right);
            
            if(left == null) root.left = null;
            if(right == null) root.right = null;
            
            if(root.val == 0 && root.left == null && root.right == null){
                return null;
            }else{
                return root;
            }
        }
    }
}