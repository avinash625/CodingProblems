class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size());
        if(nums.size() == 1) {
            vector<int> emptyResult(1,1);
            return emptyResult;
        }else if(nums.size() == 0){
            vector<int> emptyResult(0);
            return emptyResult;
        }
            
        int zeroCount =0;
        for(vector<int>::iterator it = nums.begin(); it != nums.end();  it++){
            if(*it == 0)
                zeroCount++;
        }
        if(zeroCount > 2){
            for(int iter = 0;iter< nums.size(); iter++){
                result[iter] = 0;        
            }
        }else{
            vector<int> lcp(nums.size());
            vector<int> rcp(nums.size());
            lcp[0] = nums[0];
            for(int iter = 1, n = nums.size();iter<n; iter++){
                lcp[iter] = lcp[iter-1] * nums[iter];
            }
            rcp[nums.size()-1] = nums.back();
            for(int iter = nums.size()-2;iter>=0;iter--){
                rcp[iter] = rcp[iter+1] * nums[iter];
            }
            result[0]= rcp[1];
            result[nums.size()-1] = lcp[nums.size()-2];
            for(int iter = 1;iter<nums.size()-1;iter++){
                result[iter] = lcp[iter-1]* rcp[iter+1];
            }
        }
        return result;
        
    }
};
