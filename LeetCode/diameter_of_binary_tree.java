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
    private static  int  diameter = 0;
    
    public int diameterOfBinaryTree(TreeNode root) {
        Solution.diameter = 0;
        calculateDiameter(root);
        return Solution.diameter;
    }
    
    public int calculateDiameter(TreeNode root){
        if(root == null) return 0;
        else{
            int left = calculateDiameter(root.left);
            int right = calculateDiameter(root.right);
            
            if(Solution.diameter < left+right){
                Solution.diameter = left+right;
                //System.out.println(" Diameter is updated at " + root.val + " to " + Solution.diameter);
            }
            return Integer.max(left, right) + 1;
        }
    }
}