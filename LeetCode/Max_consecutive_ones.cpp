/*
Problem Link:
https://leetcode.com/problems/max-consecutive-ones/description/
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int finalResult = 0;
        int currentResult = 0;
        for(int iter = 0;iter<nums.size(); iter++){
            if(nums[iter] == 1)currentResult++;
            else currentResult = 0;
            if(currentResult > finalResult) finalResult = currentResult;
        }
        return finalResult;
    }
};
