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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        ArrayList<List<Integer>> levelOrder = new ArrayList<List<Integer>>();
        int height = getHeight(root);
        for(int iter = 0;iter< height; iter++){
            levelOrder.add(new ArrayList<Integer>());
        }
        levelOrderBottomUtil(root,getHeight(root), 0, levelOrder);
        return levelOrder;
    }
    
    public void levelOrderBottomUtil(TreeNode root, int height, int currentLevel, List<List<Integer>> levelOrder){
        if(root == null) return;
        else{
            (levelOrder.get(height-currentLevel-1)).add(root.val);
            levelOrderBottomUtil(root.left, height, currentLevel+1, levelOrder);
            levelOrderBottomUtil(root.right, height, currentLevel+1, levelOrder);
        }
    }
    
    public int getHeight(TreeNode root){
        if(root == null) return 0;
        else{
            return Integer.max(getHeight(root.left), getHeight(root.right)) + 1;
        }
    }
}