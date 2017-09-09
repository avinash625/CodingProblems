/*
Problem LinK:
https://leetcode.com/problems/add-digits/description/
*/
class Solution {
public:
    int addDigits(int num) {
        int sum =0;
        while(num > 0){
            sum = sum + ( num%10);
            num = num/10;
        }
        if(sum > 9)
            return addDigits(sum);
        else
            return sum;
    }
};
