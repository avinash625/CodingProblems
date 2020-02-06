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
    public List<Integer> rightSideView(TreeNode root) {
        ArrayList<Integer> result = new ArrayList<Integer>();
        rightSideUtil(root,0 , result);
        return result;
        
    }
    
    public void rightSideUtil(TreeNode root, int currentLevel, ArrayList<Integer> result ){
        if(root == null) return;
        else{
            if(currentLevel == result.size()){
                result.add(root.val);
                rightSideUtil(root.left, currentLevel + 1, result);
                rightSideUtil(root.right, currentLevel + 1, result);
            }else{
                result.set(currentLevel, root.val);
                rightSideUtil(root.left, currentLevel + 1, result);
                rightSideUtil(root.right, currentLevel + 1, result);
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