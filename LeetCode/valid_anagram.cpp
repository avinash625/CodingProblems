/*
Problem Link:
https://leetcode.com/problems/valid-anagram/description/
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        int Freq[26] = {0};
        for(int iter =0;s[iter];iter++)
            Freq[s[iter]-'a']++;
        for(int iter =0;t[iter];iter++)
            Freq[t[iter]-'a']--;
        for(int iter =0;iter<26;iter++)
            if(Freq[iter])
                return false;
        return true;
    }
};
