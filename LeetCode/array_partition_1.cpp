/*
Problem Link:
https://leetcode.com/problems/array-partition-i/description/
*/
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l = nums.size();
        int result = 0;
        for(int iter =0;iter<l;iter+=2){
            result += nums[iter];
        }
        return result;
    }
};
