class Solution {
    public int singleNumber(int[] nums) {
        int xor = 0;
        for(int iter = 0; iter< nums.length; iter++){
            xor = xor ^ nums[iter];
        }
        return xor;
    }
}