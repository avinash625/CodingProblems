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
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        return constructMaximumBinaryTreeUtil(nums, 0, nums.length-1);
    }
    
    public TreeNode constructMaximumBinaryTreeUtil(int[] nums, int left, int right){
        if(right < left) return null;
        if(left == right) return new TreeNode(nums[left]);
        
        int maximum = left;
        for(int iter = left; iter <= right; iter++){
            if(nums[iter] > nums[maximum])
                maximum = iter;
        }
        //System.out.println("maximum found at index "+ maximum + " with value of "+ nums[maximum]);
        
        TreeNode currentNode = new TreeNode(nums[maximum]);
        
        currentNode.left = constructMaximumBinaryTreeUtil(nums,left,maximum-1);
        currentNode.right = constructMaximumBinaryTreeUtil(nums, maximum+1, right);
        
        return currentNode;
    }
}