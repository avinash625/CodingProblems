/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

import java.util.Collections;
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
     ArrayList<List<Integer>> result = new ArrayList<List<Integer>>();
        zigzagLevelOrderUtil(root,0, result);
        for(int iter = 0; iter< result.size(); iter++){
            if(iter %2 != 0){
                Collections.reverse(result.get(iter));
            }
        }
        return result;
    }
    
    public void zigzagLevelOrderUtil(TreeNode root, int currentLevel, List<List<Integer>> result){
        if(root == null) return;
        else{
            if(currentLevel == result.size()){
                 result.add(new ArrayList<Integer>());
            }
            zigzagLevelOrderUtil(root.left, currentLevel+1, result);
            (result.get(currentLevel)).add(root.val);
            zigzagLevelOrderUtil(root.right, currentLevel+1, result);
        }     
    }
}