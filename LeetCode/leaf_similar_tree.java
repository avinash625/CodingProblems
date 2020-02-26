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
        Stack<Integer> st = new Stack<Integer>();
        getNodes(root1, st);
        verifyNodes(root2, st);
        //System.out.println(" stack size : "+ st.size());
        if(st.empty()) return true;
        return false;
    }
    
    public void getNodes(TreeNode root, Stack<Integer> st){
        if(root == null) return;
        else{
            getNodes(root.left, st);
            if(root.left == null && root.right == null){
                //System.out.println(" pushing "+ root.val);
                st.push(root.val);
            }
            getNodes(root.right, st);
        }
    }
    
    public void verifyNodes(TreeNode root, Stack<Integer> st){
        if(root == null) return;
        else{
            verifyNodes(root.right, st);
            if(!st.empty() && st.peek() == root.val && root.left == null && root.right == null){
                //System.out.println(" removing "+ root.val);
                st.pop();
            }
            verifyNodes(root.left, st);
        }
    }
}