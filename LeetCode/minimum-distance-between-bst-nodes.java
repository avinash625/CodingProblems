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
    public int minDiffInBST(TreeNode root) {
        ArrayList<Integer> nodes = new ArrayList<Integer>();
        getNodes(root,nodes);
        int minimum = Integer.MAX_VALUE;
        for(int iter = 0;iter<nodes.size()-1;iter++){
            int diff = nodes.get(iter+1) - nodes.get(iter);
            if(diff < minimum){
                minimum = diff;
            }
        }
        return minimum;
    }
    
    public void getNodes(TreeNode root, ArrayList<Integer> result){
        if(root == null) return;
        else{
            getNodes(root.left, result);
            result.add(root.val);
            getNodes(root.right, result);
        }
    }
}