class Solution {
    public int maximumProduct(int[] nums) {
        Arrays.sort(nums);
        
        int length = nums.length;
        
        if(nums[length-1] * nums[length-2]* nums[length-3] > nums[0]*nums[1] * nums[length-1]){
            return nums[length-1] * nums[length-2]* nums[length-3];
        }else{
            return nums[0]*nums[1] * nums[length-1];
        }
    }
}