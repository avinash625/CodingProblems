class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> ans;
        stack<int> st;
        unordered_map<int,int> mapping;
        
        for(int number: nums){
            while(!st.empty() && st.top() < number){
                mapping[st.top()] = number;
                st.pop();
            }
            st.push(number);
        }
        for(int number: findNums){
            if(mapping[number])
                ans.push_back(mapping[number]);
            else
                ans.push_back(-1);
        }
        return ans;
    }
};
