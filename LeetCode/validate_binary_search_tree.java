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
    public boolean isValidBST(TreeNode root) {
        return isValidBSTUtil(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
    
    public int getTreeHeight(TreeNode root){
        if(root == null) return 0;
        else{
            return Integer.max(getTreeHeight(root.left), getTreeHeight(root.right)) + 1;
        }
    }
    public boolean isValidBSTUtil(TreeNode root, Long minimum, Long maximum){
        if(root == null) return true;
        else{
            if(root.val >= maximum || root.val <= minimum) return false;
            else{
                return (isValidBSTUtil(root.left,minimum, new Long(root.val)) && isValidBSTUtil(root.right, new Long(root.val), maximum));
            }
        }
        
    }
}