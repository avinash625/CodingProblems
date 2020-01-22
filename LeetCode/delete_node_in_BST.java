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
    public TreeNode deleteNode(TreeNode root, int key) {
        if(findNode(root,key)){
            root = deleteNodeUtil(root,key);
        }
        return root;
    }
    
    public boolean findNode(TreeNode root,int key){
        if(root == null) return false;
        else{
            if(root.val > key){
                return findNode(root.left,key);
            }else if(root.val < key){
                return findNode(root.right,key);
            }else if(root.val == key){
                return true;
            }
        }
        return false;
    }
    
    public TreeNode deleteNodeUtil(TreeNode root, int key){
        if(root == null) return null;
        else{
            if(root.val > key){
                root.left = deleteNodeUtil(root.left,key);
            }else if(root.val < key){
                root.right = deleteNodeUtil(root.right ,key);
            }else if(root.val == key){
                if(root.left == null && root.right == null) return null;
                else if(root.right == null){
                    return root.left;
                }
                else if(root.left == null){
                    return root.right;
                }
                
                TreeNode minimumNode = findMinimum(root.right);
                root.val = minimumNode.val;
                root.right = deleteNodeUtil(root.right,root.val);
                    
            }
        }
        return root;
    }
    
    public TreeNode findMinimum(TreeNode root){
        TreeNode iter = root;
        while(iter.left != null){
            iter = iter.left;
        }
        return iter;
    }
}