/*
Problem Link:
https://leetcode.com/problems/move-zeroes/description/
*/


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int writeIter = 0;
        int readIter = 0;
        for(readIter = 0; readIter<len;readIter++){
            if(nums[readIter] != 0){
                nums[writeIter] = nums[readIter];
                writeIter++;
            }
            else{
                continue;
            }
        }
        for(;writeIter<len;writeIter++){
            nums[writeIter] = 0;
        }
    }
};
