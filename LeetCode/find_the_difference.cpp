/*
Problem Link:
https://leetcode.com/problems/find-the-difference/description/
*/
class Solution {
public:
    char findTheDifference(string s, string t) {
        char xorValue = 0;
        for(int iter = 0;s[iter];iter++)
            xorValue = xorValue ^ s[iter];
        for(int iter = 0;t[iter];iter++)
            xorValue = xorValue ^ t[iter];
        return xorValue;
    }
};
