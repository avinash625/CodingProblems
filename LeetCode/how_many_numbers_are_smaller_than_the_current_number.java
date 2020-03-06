import java.util.*;
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] preSum = new int[101];
        for(int iter = 0 ; iter< nums.length; iter++){
            preSum[nums[iter]]  = preSum[nums[iter]] + 1; 
        }
        for(int iter = 1; iter<= 100; iter++){
            preSum[iter] = preSum[iter-1] + preSum[iter];
        }
        int[] result = new int[nums.length];
        for(int iter = 0; iter< nums.length; iter++){
            if(nums[iter] > 0)
                result[iter] = preSum[nums[iter]-1];
            else
                result[iter] = 0;
        }
        return result;
    }
}