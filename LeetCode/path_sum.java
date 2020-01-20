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
    public boolean hasPathSum(TreeNode root, int sum) {
        return hasPathSumUtil(root, sum, 0);
    }
    public boolean hasPathSumUtil(TreeNode root, int sum, int currentSum){
        if(root == null) return false;
        else{
            if(root.left == null && root.right == null && root.val+ currentSum == sum) return true;
            boolean left = hasPathSumUtil(root.left, sum, currentSum + root.val);
            boolean right = hasPathSumUtil(root.right, sum, currentSum + root.val);
            
            return (left||right);
        }
    }
}