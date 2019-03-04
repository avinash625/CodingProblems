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
    public List<Integer> postorderTraversal(TreeNode root) {
        ArrayList<Integer> result = new ArrayList<Integer>();
        postOrderTraversalUtil(root,result);
        return result;
    }
    
    public void postOrderTraversalUtil(TreeNode root, ArrayList<Integer> result){
        if(root == null) return;
        else{
            postOrderTraversalUtil(root.left,result);
            postOrderTraversalUtil(root.right,result);
            result.add(root.val);
        }
    }
}