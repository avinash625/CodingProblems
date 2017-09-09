/*
Problem Link:
https://leetcode.com/problems/missing-number/description/
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len =  nums.size();
        int sum = 0;
        for(int iter =0;iter<len;iter++){
            sum += nums[iter];
        }
        return ((len*(len+1))/2)-sum;
    }
};
