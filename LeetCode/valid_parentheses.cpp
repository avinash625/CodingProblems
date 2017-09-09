/*
Problem Link:
https://leetcode.com/problems/valid-parentheses/description/
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int iter = 0;s[iter];iter++){
            if(st.empty()){
                st.push(s[iter]);
            }
            else if(st.top() == '('  && s[iter] == ')')
                st.pop();
            else if(st.top() == '{' && s[iter] == '}')
                st.pop();
            else if(st.top() == '[' && s[iter] == ']')
                st.pop();
            else
                st.push(s[iter]);
        }
        if(st.size() == 0){
            return true;
        }
        return false;
    }
};
