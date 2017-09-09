/*
Problem LinK:
https://leetcode.com/problems/number-complement/description/
*/
class Solution {
public:
    int findComplement(int num) {
        int bitPosition  = 0 ;
        int result = 0;
        int lastBit;
        while(num){
            lastBit = (num&1);
            if(lastBit==0){
                result = result + (1<<bitPosition);
            }
            bitPosition++;
            num = num/2;
        }
        return result;
    }
};
