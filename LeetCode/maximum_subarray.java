class Solution {
    public int maxSubArray(int[] nums) {
        int start = 0, end = 0;
        int maximumSum = Integer.MIN_VALUE;
        
        for(int iter = 0;  iter< nums.length; iter++){
            int currentSum = nums[iter];
            start = iter;
            end = iter;
            while(currentSum > 0 && end < nums.length){
                if(currentSum > maximumSum)
                    maximumSum = currentSum;
                end++;
                if(end < nums.length)
                    currentSum += nums[end];
            }
            if(currentSum > maximumSum)
                maximumSum = currentSum;
        }
        return maximumSum;
    }
}