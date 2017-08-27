/*
Problem Link:
https://leetcode.com/problems/majority-element/description/
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityElement = nums[0];
        int majorityElementFreq = 1;
        int len = nums.size();
        for(int iter = 1;iter<len;iter++){
            if(nums[iter] != majorityElement){
                majorityElementFreq--;
                if(majorityElementFreq == 0){
                    majorityElement = nums[iter];
                    majorityElementFreq++;
                }
            }
            else{
                majorityElementFreq++;
            }
        }
        return majorityElement;
    }
};
