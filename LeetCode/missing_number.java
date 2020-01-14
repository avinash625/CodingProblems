class Solution {
    public int missingNumber(int[] nums) {
        int missingNumber = 0;
        for(int iter = 0;iter< nums.length; iter++){
            missingNumber = missingNumber ^ nums[iter];
            missingNumber = missingNumber ^ iter;
        }
        return missingNumber^nums.length;
    }
}