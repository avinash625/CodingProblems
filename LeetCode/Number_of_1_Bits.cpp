/*
Problem Link:
https://leetcode.com/problems/number-of-1-bits/description/
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count =0;
        while(n){
            if((n&1)==1)
                count++;
            n = n/2;
        }
        return count;
    }
};
