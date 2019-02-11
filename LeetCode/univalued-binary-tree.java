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
        return isUnivalTree(root,root.val);
    }
    
    public boolean isUnivalTree(TreeNode root, int val){
        if(root == null){
            return true;
        }else{
            if(root.val == val){
                return (true && (isUnivalTree(root.left, val) && isUnivalTree(root.right,val)));
            }else{
                return false;
            }
        }
    }
}