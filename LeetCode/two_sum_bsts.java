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
    public boolean twoSumBSTs(TreeNode root1, TreeNode root2, int target) {
        return (inorder(root1, root2,target) || inorder(root2, root1, (long)target));
    }
    
    public boolean inorder(TreeNode root1, TreeNode root2, long target){
        if(root1 == null) return false;
        else{
            long diff = target - root1.val;
            return find(root2, diff) || inorder(root1.left, root2, target) || inorder(root1.right, root2, target);
        }
    }
    
    public boolean find(TreeNode root, long value){
        if(root == null) return false;
        else{
            if(root.val == value) return true;
            else if( root.val > value) return find(root.left, value);
            else return find(root.right, value);
        }
    }
}