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
        
        visitNodes(root, nodes);
        
        int first = 0, second = nodes.size()-1;
        
        while(first < second){
            if(nodes.get(first) + nodes.get(second) > k){
                second--;
            }else if(nodes.get(first) + nodes.get(second) < k){
                first++;
            }else{
                return true;
            }
        }
        return false;
    }
    
    
    public void visitNodes(TreeNode root, ArrayList<Integer> nodes){
        if(root == null) return;
        else{
            visitNodes(root.left, nodes);
            nodes.add(root.val);
            visitNodes(root.right, nodes);
        }
    }
}