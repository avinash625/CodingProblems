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
    public int findSecondMinimumValue(TreeNode root) {
        Set<Integer> myset = new HashSet<Integer>();
        getNodeValues(root,myset);
        ArrayList<Integer> nodes = new ArrayList<Integer>();
        nodes.addAll(myset);
        Collections.sort(nodes);
        if(nodes.size() < 2)
            return -1;
        return nodes.get(1);
    }
    
    public void getNodeValues(TreeNode root, Set<Integer> myset){
        if(root == null) return;
        else{
            myset.add(root.val);
            getNodeValues(root.left,myset);
            getNodeValues(root.right,myset);
        }
    }
}