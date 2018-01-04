class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size() == 0 ) return 0;
        int p1 = nums[0]*nums[1]*nums.back();
        int p2 = nums[nums.size()-1]*nums[nums.size()-2]* nums[nums.size()-3];
        if(p1>p2) return p1;
        return p2;
    }
};
