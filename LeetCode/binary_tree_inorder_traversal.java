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
    public List<Integer> inorderTraversal(TreeNode root) {
        ArrayList<Integer> inorder = new ArrayList<Integer>();
        inorderTraversalUtil(root, inorder);
        return inorder;
    }
    
    public void inorderTraversalUtil(TreeNode root, ArrayList<Integer> inorder){
        if(root == null) return;
        else{
            inorderTraversalUtil(root.left, inorder);
            inorder.add(root.val);
            inorderTraversalUtil(root.right, inorder);
        }
    }
}