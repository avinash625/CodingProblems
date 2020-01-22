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
    public int deepestLeavesSum(TreeNode root) {
        int height = getHeight(root);
        System.out.println("height : " + height);
        return deepestLeavesSumUtil(root,height,1);
    }
    
    public int deepestLeavesSumUtil(TreeNode root, int height, int currentLevel){
        if(root == null) return 0;
        else{
            if(currentLevel == height){
                return root.val;
            }else{
                return deepestLeavesSumUtil(root.left,height,currentLevel+1) + deepestLeavesSumUtil(root.right,height, currentLevel+1);
            }
        }
    }
    
    public int getHeight(TreeNode root){
        if(root == null) return 0;
        else{
            return Integer.max(getHeight(root.left), getHeight(root.right)) + 1;
        }
    }
}