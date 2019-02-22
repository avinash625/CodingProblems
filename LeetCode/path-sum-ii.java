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
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        ArrayList<Integer> currentNodes = new ArrayList<Integer>();
        List<List<Integer>> result = new  ArrayList<List<Integer>>();
        pathSumUtil(root, sum, currentNodes,result,0);
        return result;
    }
    
    public void pathSumUtil(TreeNode root, int sum, ArrayList<Integer> currentNodes, List<List<Integer>> result, int currentSum){
        if(root == null) return;
        else{
            currentNodes.add(root.val);
            if(root.left == null && root.right == null){
                if(currentSum+ root.val == sum){
                    int[] a = currentNodes.stream().filter(t -> t != null).mapToInt(t -> t).toArray();
                    List<Integer> b = new ArrayList<Integer>();
                    for(int n: a){
                        b.add(n);
                    }
                    result.add(b);
                }
            }
            else{
                pathSumUtil(root.left, sum, currentNodes,result,currentSum+root.val);
                pathSumUtil(root.right, sum, currentNodes, result, currentSum+root.val);
            }
            currentNodes.remove(currentNodes.size()-1);
        }
    }
}