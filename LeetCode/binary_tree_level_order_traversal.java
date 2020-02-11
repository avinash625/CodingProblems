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
    public List<List<Integer>> levelOrder(TreeNode root) {
        ArrayList<List<Integer>> result = new ArrayList<List<Integer>>();
        levelOrderUtil(root,0, result);
        return result;
    }
    
    public void levelOrderUtil(TreeNode root, int currentLevel, List<List<Integer>> result){
        if(root == null) return;
        else{
            if(currentLevel == result.size()){
                 result.add(new ArrayList<Integer>());
            }
            levelOrderUtil(root.left, currentLevel+1, result);
            (result.get(currentLevel)).add(root.val);
            levelOrderUtil(root.right, currentLevel+1, result);
        }     
    }
}