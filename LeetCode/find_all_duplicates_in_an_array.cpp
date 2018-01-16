class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        
        for(int iter = 0;iter<nums.size();iter++){
            int index = abs(nums[iter])-1;
            //cout<<"index value is "<<index<<" with "<<nums[abs(index)] <<" as its value"<<endl;
            if(nums[index] < 0){
                result.push_back(abs(nums[iter]));
                //cout<<" adding "<<abs(nums[iter])<<endl;
            }
                
            else{
                //cout<<"making "<<nums[index]<<" to value "<<-nums[index]<<endl;
                nums[index] = -nums[index];
            }
            
        }
        return result;
    }
};
