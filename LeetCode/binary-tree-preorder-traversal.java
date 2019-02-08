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
    public List<Integer> preorderTraversal(TreeNode root) {
        ArrayList<Integer> result = new ArrayList<Integer>();
        preorderTraversalUtil(root,result);
        return result;
    }
    
    private void preorderTraversalUtil(TreeNode root, ArrayList<Integer> result){
        if(root == null){
            return;
        }
        else{
            result.add(root.val);
            preorderTraversalUtil(root.left,result);
            preorderTraversalUtil(root.right, result);
        }
    }
}