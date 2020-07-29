class Solution {
    public int[] runningSum(int[] nums) {
        int[] result= new int[nums.length];
        if(nums.length == 0) return result;
        else{
            result[0] = nums[0];
            for(int index  = 1; index< nums.length; index++){
                result[index] = result[index-1] + nums[index];
            }
        }
        return result;
    }
}