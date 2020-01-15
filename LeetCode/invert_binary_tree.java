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
    public TreeNode invertTree(TreeNode root) {
        if(root == null) return root;
        else{
            if(root.left != null && root.right != null){
                invertTree(root.left);
                invertTree(root.right);
                TreeNode current = root.left;
                root.left = root.right;
                root.right = current;
            }else if(root.left == null){
                root.left = invertTree(root.right);
                root.right = null;
            }else if(root.right == null){
                root.right = invertTree(root.left);
                root.left = null;
            }
        }
        return root;
    }
}