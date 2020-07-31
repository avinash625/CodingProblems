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
    public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        if(t1 == null && t2 == null) {
            //System.out.println("both nodes are null so returning null");
            return t1;
        }
        else{
            if(t1 != null && t2 != null){
                //System.out.println("both nodes are NOT null with values of " + t1.val + " , " + t2.val);
                //System.out.println("entering into left tree of "+ t1.val);
                t1.left = mergeTrees(t1.left, t2.left);
                //System.out.println(" entering into right tree of "+t1.val);
                t1.right = mergeTrees(t1.right, t2.right);
                //System.out.println("updated value with sum " + (t1.val + t2.val));
                t1.val = t1.val + t2.val;
                return t1;
            }else if(t1 == null) {
                //System.out.println("returning t2 " + t2.val);
                return t2;
            }
            else{
                //System.out.println("returning t1 " + t1.val);
                return t1;
            }
        }
    }

    public TreeNode mergeTrees_1(TreeNode t1, TreeNode t2) {
        if(t1 == null) return t2;
        if(t2 == null) return t1;
        
        t1.val = t1.val + t2.val;
        t1.left = mergeTrees(t1.left, t2.left);
        t1.right = mergeTrees(t1.right, t2.right);
        return t1;
    }
}