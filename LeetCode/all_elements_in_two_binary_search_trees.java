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
    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        Deque<Integer> first = new LinkedList<Integer>();
        Deque<Integer> second = new LinkedList<Integer>();
        
        getElements(root1, first);
        getElements(root2, second);
        
        ArrayList<Integer> result = new ArrayList<Integer>();
        
        while(!first.isEmpty() && !second.isEmpty()){   
            if(first.peekFirst() > second.peekFirst()){
                result.add(second.peekFirst());
                second.removeFirst();
            }else{
                result.add(first.peekFirst());
                first.removeFirst();
            }
        }
        while(!first.isEmpty()){
                result.add(first.removeFirst());
        }
        while(!second.isEmpty()){
            result.add(second.removeFirst());
        }
        return result;
    }
    
    public void getElements(TreeNode root, Deque<Integer> nodes){
        if(root == null) return;
        else{
            getElements(root.left, nodes);
            nodes.addLast(root.val);
            getElements(root.right, nodes);
        }
    }
    
    
}