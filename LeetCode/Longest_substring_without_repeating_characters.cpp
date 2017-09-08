/*
Problem Link:
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        queue<char> result;
        int maxLength = 0;
        bool charPresent[512];
        for(int iter = 0;iter<512;iter++)
            charPresent[iter] = false;
        for(int iter = 0;s[iter];iter++){
            
            if(charPresent[s[iter]] == false){
                result.push(s[iter]);
                charPresent[s[iter]] = true;
                if(result.size() > maxLength){
                    maxLength = result.size();
                }
            }
            else{
                if(result.front() == s[iter]){
                    result.push(s[iter]);
                    result.pop();
                }
                else{
                    while(result.front() != s[iter]){
                        charPresent[result.front()] = false;
                        result.pop();
                    }
                    result.push(s[iter]);
                    result.pop();
                }
            }
        }
        return maxLength;
    }
};
