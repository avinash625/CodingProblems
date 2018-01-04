class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int writeIndex = 0, readIndex = 0;
        int arraySize = nums.size();
        if(arraySize == 0) return 0;
        for(;readIndex < arraySize;){
            if(nums[writeIndex] == nums[readIndex]){
                readIndex++;
            }
            else{
                writeIndex++;
                nums[writeIndex] = nums[readIndex];
                readIndex++;
            }
        }
        return writeIndex+1;
    }
};
