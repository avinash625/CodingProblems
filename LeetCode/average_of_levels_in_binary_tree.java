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
    public List<Double> averageOfLevels(TreeNode root) {
        int height = getHeight(root);
        ArrayList<Double> result = new ArrayList<Double>();
        ArrayList<ArrayList<Integer>> levels = new ArrayList<ArrayList<Integer>>();
        averageOfLevelsUtil(root,levels,0);
        Iterator<ArrayList<Integer>> iter = levels.iterator();
        while(iter.hasNext()){
            ArrayList<Integer> currentLevel = iter.next();
            Iterator<Integer> i = currentLevel.iterator();
            long sum = 0;
            while(i.hasNext()){
                sum += i.next();
            }
            result.add((sum*1.00)/currentLevel.size());
        }
        return result;
    }
    
    public void averageOfLevelsUtil(TreeNode root, ArrayList<ArrayList<Integer>> levels, int currentLevel){
       if(root == null) return;
        else{
            if(levels.size() <= currentLevel){
                levels.add(new ArrayList<Integer>());
                (levels.get(currentLevel)).add(root.val);
            }else{
                (levels.get(currentLevel)).add(root.val);
            }
            averageOfLevelsUtil(root.left,levels, currentLevel+1);
            averageOfLevelsUtil(root.right, levels, currentLevel+1);
        }
    }
    
    public int getHeight(TreeNode root){
        if(root == null) return 0;
        else{
            return Math.max(getHeight(root.left), getHeight(root.right)) + 1;
        }
    }
}