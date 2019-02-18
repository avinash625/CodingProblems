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
    public boolean findTarget(TreeNode root, int k) {
        ArrayList<Integer> nodes = new ArrayList<Integer>();
        getNodes(root,nodes);
        int position = 0;
        for(int index = 0; index < nodes.size(); index++){
            position = Collections.binarySearch(nodes,k-(nodes.get(index).intValue()));
            if(position >= 0 && position != index)
                return true;
        }
        return false;
    }
    
     public void getNodes(TreeNode root, ArrayList<Integer> nodes){
         if(root == null) return;
         else{
             getNodes(root.left,nodes);
             nodes.add(root.val);
             getNodes(root.right, nodes);
         }
     }
}