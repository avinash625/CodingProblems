/*
Problem Link:
https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
*/


class Solution {
public:
    int abs(int num){
        if(num>0)
            return num;
        return num*-1;
    }
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        int len = nums.size();
        for(int iter = 0;iter< len;iter++){
            int value = abs(nums[iter]);
            if(nums[value-1] > 0){
                nums[value-1] = nums[value-1]*-1;
            }
        }
        for(int iter = 0;iter< len;iter++){
            if(nums[iter] > 0){
                result.push_back(iter+1);
            }
        }
        return result;
    }
};
