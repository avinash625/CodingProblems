/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> getLonelyNodes(TreeNode root) {
        ArrayList<Integer> result = new ArrayList<Integer>();
        if(root == null) return result;
        else{
            if(root.left == null && root.right != null){
                result.add(root.right.val);
                getLonelyNodesUtil(root.right, result);
            }else if(root.right == null && root.left != null){
                result.add(root.left.val);
                getLonelyNodesUtil(root.left, result);
            }else{
                getLonelyNodesUtil(root.left, result);
                getLonelyNodesUtil(root.right, result);
            }
        }
        return result;
    }
    
    public void getLonelyNodesUtil(TreeNode root, List<Integer> result){
        if(root == null) return;
        else if(root.left == null && root.right != null){
            result.add(root.right.val);
            getLonelyNodesUtil(root.right, result);
        }else if(root.right == null && root.left != null){
            result.add(root.left.val);
            getLonelyNodesUtil(root.left, result);
        }else{
            getLonelyNodesUtil(root.right, result);
            getLonelyNodesUtil(root.left, result);
        }
    }
}