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
    public boolean isUnivalTree(TreeNode root) {
        if(root == null) return true;
        else{
            
            if(root.left != null && root.right != null){
                var left = (root.val == root.left.val && isUnivalTree(root.left));
                var right = (root.val == root.right.val && isUnivalTree(root.right));
                return left && right;
            }else if(root.left == null){
                if(root.right == null) return true;
                else return (root.val == root.right.val && isUnivalTree(root.right));
            }else if(root.right == null){
                if(root.left == null) return true;
                else return (root.val == root.left.val && isUnivalTree(root.left));
            }
            return false;
        }
    }
}