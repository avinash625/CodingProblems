class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int writeIndex = 0, readIndex = 0;
        int arraySize = nums.size();
        for( ; readIndex < arraySize; ){
            if(nums[readIndex] == val){
                readIndex++;
            }
            else{
                nums[writeIndex] = nums[readIndex];
                readIndex++;
                writeIndex++;
            }
        }
        return writeIndex;
    }
};
