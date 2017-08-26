class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(vector<int>::iterator it  = nums.begin(); it!= nums.end(); it++){
            result = result ^ *it;
        }
        return result;
    }
};
