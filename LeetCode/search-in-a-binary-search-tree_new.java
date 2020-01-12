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
    public TreeNode searchBST(TreeNode root, int val) {
        if(root == null){
            return root;
        }else if(val > root.val){
            return searchBST(root.right, val);
        }else if(val < root.val){
            return searchBST(root.left, val);
        }else if(val == root.val){
            return root;
        }
        return null;
    }
}