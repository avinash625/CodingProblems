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
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        ArrayDeque<Integer> firstNodes = new ArrayDeque<Integer>();
        ArrayDeque<Integer> secondNodes = new ArrayDeque<Integer>();
        getNodes(root2,secondNodes);
        getNodes(root1, firstNodes);
        if(firstNodes.size() != secondNodes.size()){
            return false;
        }else{
            while(firstNodes.isEmpty() == false && firstNodes.peekFirst() == secondNodes.peekFirst()){
                firstNodes.pollFirst();
                secondNodes.pollFirst();
            }
            if(firstNodes.isEmpty() == false || secondNodes.isEmpty() == false){
                return false;
            }
            return true;
        }
    }
    
    public void getNodes(TreeNode root, ArrayDeque<Integer> nodes){
        if(root == null) return;
        else{
            if(root.left == null && root.right == null){
                nodes.addLast(root.val);
            }else{
                getNodes(root.left,nodes);
                getNodes(root.right,nodes);
            }
        }
    }
    
}