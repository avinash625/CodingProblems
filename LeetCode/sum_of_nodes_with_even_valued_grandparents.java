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
    public int sumEvenGrandparent(TreeNode root) {
        if(root == null) return 0;
        else{
            if(root.val%2 == 0){
                int left = 0, right = 0;
                if(root.left != null){
                    if(root.left.left != null)
                        left = root.left.left.val;
                    if(root.left.right != null){
                        left += root.left.right.val;
                    }
                }
                if(root.right != null){
                    if(root.right.left != null){
                        right = root.right.left.val;
                    }
                    if(root.right.right != null){
                        right += root.right.right.val;
                    }
                }
                return left+right + sumEvenGrandparent(root.left) + sumEvenGrandparent(root.right);
            }else{
                return sumEvenGrandparent(root.left) + sumEvenGrandparent(root.right);
            }
        }
    }
}